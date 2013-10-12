/**
 * Copyright (c) 2013 xjrsanchezx@yahoo.es
 *
 * Use of this source code is governed by The MIT License (MIT) license 
 * that can be found in the LICENSE file.
 */

/** \file 
 * \author xjrsanchezx@yahoo.es (Jairo R. Sánchez)
 * \copyright MIT License (MIT)
 */


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
	
	return &_params;
}

/**
\param[in] id The id of the selected machine
*/
void MainController::elementActivated(QString id)
{
	// request to launch the InfoController with the specified machine
	// build the parameters map
	QStringMap params;
	params["machine"] = id;
	params["db"] = _model.getMachineDB(id);

	emit newControllerRequested("InfoController", params);
}