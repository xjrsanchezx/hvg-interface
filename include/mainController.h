/**
 * Copyright (c) 2013 xjrsanchezx@yahoo.es
 *
 * Use of this source code is governed by The MIT License (MIT) license 
 * that can be found in the LICENSE file.
 */

/** \file
 * \brief The controller of the main screen.
 *
 * \author xjrsanchezx@yahoo.es (Jairo R. Sánchez)
 * \copyright MIT License (MIT)
 */

#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include "controller.h"
#include "mainModel.h"

/**
* Parameters that will be sent to the mainView 
*/
class MainViewParams : public ViewParams
{
	Q_OBJECT

public:
	MainViewParams() {};

	QString getViewURL() const {return QString("mainView.html");};

	Q_PROPERTY(QStringList machines READ getMachines WRITE setMachines);

	Q_INVOKABLE  QStringList getMachines() const { return _machines; };
	Q_INVOKABLE  void setMachines(QStringList& list) {_machines = list; };

private:
	QStringList _machines;		///< List of available machines

};

/**
* The controller of the main window. This window displays available machines
*/
class MainController : public Controller
{
	Q_OBJECT

public:
	MainController() {};
	~MainController() {};

	ViewParams* run();

public slots:
	void elementActivated(QString id);

private:
	MainModel _model;		///< Data model
	MainViewParams _params;
};

#endif // MAIN_CONTROLLER_H