#include "mainController.h"
#include <iostream>

// register the controller into the factory
namespace
{
	Controller* CreateMainController()
	{
		return new MainController();
	}
	// The ID of class MainController
	const std::string id = "MainController";

	// The ControllerrFactory is a singleton factory
	const bool registered = ControllerrFactory::Instance().Register(id, CreateMainController);
}
////////////////////////////////////////////

ViewParams* MainController::run()
{
	// get the list of machines
	QStringList machines;

	_model.getMachines(machines);
	_params.setMachines(machines);

	std::cout << machines.size();

	return &_params;
}

/**
\param[in] id The id of the selected machine
*/
void MainController::elementActivated(QString id)
{
	emit newControllerRequested(id);
}