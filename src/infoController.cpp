/**
 * Copyright (c) 2013 xjrsanchezx@yahoo.es
 *
 * Use of this source code is governed by The MIT License (MIT) license 
 * that can be found in the LICENSE file.
 */

/** \file 
 * \author xjrsanchezx@yahoo.es (Jairo R. S�nchez)
 * \copyright MIT License (MIT)
 */


#include "infoController.h"
#include "config.h"
#include <iostream>
#include <QDir>
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
	QString infoURL = _model.getInfoURL( _machine );

	// chek if empty
	if(infoURL != "")
	{			
		infoURL = QDir(infoURL).absolutePath();	// remove relative paths as the view expects absolute paths
		_params.setMachineURL( QUrl(infoURL).url() );
	}

	return &_params;
}

/**
* This controller needs the parameter 'machine' with the name of the machine
*
* \param[in] params The parameter map
*/
void InfoController::setParams(const QStringMap& params)
{
	if( !params.contains("machine") || !params.contains("machine"))
	{
		std::cerr << "InfoController: Required parameter not found" << std::endl;
		return;
	}

	_machine = params["machine"];
	_model.setDatabaseFile( params["db"] );
}

/**
\param[in] id The id of the selected machine
*/
void InfoController::elementActivated(QString id)
{
	if(id =="back")	// go back to the initial window
	{
		emit newControllerRequested("MainController", QStringMap() );
	}
	
	else if(id == "forward") // go to the list of games
	{
		QStringMap params;
		params["machine"] = _machine;
		params["db"] = _model.getMachineDB();

		emit newControllerRequested("GameListController", params);
		return;
	}

	else
	{
		std::cerr << "InfoController: Unknown element activated " << id.toUtf8().constData() << std::endl;
		return;
	}
}