/**
 * Copyright (c) 2013 xjrsanchezx@yahoo.es
 *
 * Use of this source code is governed by The MIT License (MIT) license 
 * that can be found in the LICENSE file.
 */

/** \file
 * \brief The window that contains the web browser
 *
 * \author xjrsanchezx@yahoo.es (Jairo R. Sánchez)
 * \copyright MIT License (MIT)
 */

#ifndef MAINDLG_H
#define MAINDLG_H

#include <QtWidgets/QMainWindow>
#include <QtWebKitWidgets\qwebview.h>
#include "ui_hvg_main.h"

// controllers
#include "controller.h"

class MainDlg : public QMainWindow
{
	Q_OBJECT

public:
	MainDlg(QWidget *parent = 0);
	~MainDlg();

private:
	

public slots:
	void addJSObject();
	void loadFinished(bool ok);

	void newControllerRequested(QString controller, QStringMap params);	///< emited by controllers

private:
	void changeActiveController(const QString& controller, const QStringMap& params);

private:
	Ui::MainDlgClass ui;

	Controller* _activeController;		///< Running controller
	ViewParams* _params;
};

#endif // MAINDLG_H
