/**
 * Copyright (c) 2013 xjrsanchezx@yahoo.es
 *
 * Use of this source code is governed by The MIT License (MIT) license 
 * that can be found in the LICENSE file.
 */

/** \file
 * \brief The controller of the machine information screen.
 *
 * \author xjrsanchezx@yahoo.es (Jairo R. Sánchez)
 * \copyright MIT License (MIT)
 */

#ifndef INFO_CONTROLLER_H
#define INFO_CONTROLLER_H

#include "controller.h"
#include "infoModel.h"

/**
* Parameters that will be sent to the machine info view 
*/
class InfoViewParams : public ViewParams
{
	Q_OBJECT

public:
	InfoViewParams() {};

	QString getViewURL() const {return QString("infoView.html");};

	Q_PROPERTY(QString machineURL READ getMachineURL WRITE setMachineURL)	

	Q_INVOKABLE  QString getMachineURL() const {return _machineURL;};	
	Q_INVOKABLE  void setMachineURL(QString& url) {_machineURL = url; };
	
private:
	QString _machineURL;		///< The URL of the machine description page

};


/**
* The controller of the machine information screen. This window displays 
* the webpage with the info of the machine.
*/
class InfoController : public Controller
{
	Q_OBJECT

public:
	InfoController() {};
	~InfoController() {};

	ViewParams* run();
	void setParams(const QStringMap& params);

public slots:
	void elementActivated(QString id);

private:
	InfoViewParams _params;			///< The params to pass to the view
	InfoModel _model;				///< data model
	QString _machine;				///< The name of the selected machine
};


#endif // INFO_CONTROLLER_H