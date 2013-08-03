#include "gameListController.h"
#include "config.h"

#include <iostream>

// register the controller into the factory
namespace
{
	Controller* CreateGameListController()
	{
		return new GameListController();
	}
	// The ID of class InfoController
	const std::string id = "GameListController";

	// The ControllerrFactory is a singleton factory
	const bool registered = ControllerrFactory::Instance().Register(id, CreateGameListController);
}
////////////////////////////////////////////

GameListController::GameListController()
{
	_emulatorProcess = NULL;
}

GameListController::~GameListController()
{
	if( _emulatorProcess )
	{
		_emulatorProcess->close();
		delete _emulatorProcess;
	}
}

ViewParams* GameListController::run()
{		
	GameListModel model;
	GameList availableGames;

	model.getGames( _machine, availableGames );

	_params.setGameList(availableGames);

	return &_params;
}

/**
* This controller needs the parameter 'machine' with the name of the machine
*
* \param[in] params The parameter map
*/
void GameListController::setParams(const QStringMap& params)
{
	if( !params.contains("machine") )
	{
		std::cerr << "GameListController: Parameter 'machine' not found" << std::endl;
		return;
	}

	_machine = params["machine"];
}

/**
\param[in] id The id of the selected game
*/
void GameListController::elementActivated(QString id)
{
	if(id =="back")	// go back to the initial window
	{
		QStringMap params;
		params["machine"] = _machine;

		emit newControllerRequested("InfoController", params);
	}

	else		// try to launch the emulator. The id is the selected game
	{
		GameListModel model;

		QString rom = QString("\"") + model.getRomPathFromName( _machine, id ) + "\"";
		QString emulator = model.getEmulatorPath( _machine );

		// launch the emulator	
		delete _emulatorProcess;
		_emulatorProcess = new QProcess();
		QStringList arguments;
		arguments << rom;

		_emulatorProcess->start(emulator, arguments);
	}
}