#include "infoController.h"
#include "config.h"
#include <iostream>
#include <QUrl>

// register the controller into the factory
namespace
{
	Controller* CreateInfoController()
	{
		return new InfoController();
	}
	// The ID of class InfoController
	const std::string id = "InfoController";

	// The ControllerrFactory is a singleton factory
	const bool registered = ControllerrFactory::Instance().Register(id, CreateInfoController);
}
////////////////////////////////////////////

ViewParams* InfoController::run()
{	
	// construct the url using the name of the machine
	QString url = QString(HVG_PATH) + "/" + _machine + "/html/" + _machine + ".htm";
	_params.setMachineURL( QUrl(url).url() );

	return &_params;
}

/**
* This controller needs the parameter 'machine' with the name of the machine
*
* \param[in] params The parameter map
*/
void InfoController::setParams(const QStringMap& params)
{
	if( !params.contains("machine") )
	{
		std::cerr << "InfoController: Parameter 'machine' not found" << std::endl;
		return;
	}

	_machine = params["machine"];
}

/**
\param[in] id The id of the selected machine
*/
void InfoController::elementActivated(QString id)
{
	if(id =="back")
	{
		emit newControllerRequested("MainController", QStringMap() );
	}
	
	else if(id == "forward")
		return;

	else
	{
		std::cerr << "InfoController: Unknown element activated " << id.toUtf8().constData() << std::endl;
		return;
	}
}