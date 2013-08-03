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


#include "mainDlg.h"
#include <qwebframe.h>
#include <iostream>
#include "config.h"

MainDlg::MainDlg(QWidget *parent /*= 0*/)
	: QMainWindow(parent)
{
#ifdef _DEBUG
	QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
#endif

	ui.setupUi(this);	

	// force the signal linkClicked to be called when clicking
	ui.webView->page()->setLinkDelegationPolicy(QWebPage::LinkDelegationPolicy::DontDelegateLinks);

	// Signal is emitted before frame loads any web content:
    QObject::connect((QObject*)ui.webView->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
                     this, SLOT(addJSObject()) );

	// signal emitted after loading the page
	QObject::connect((QObject*)ui.webView, SIGNAL(loadFinished(bool)), this, SLOT(loadFinished(bool)));

	_activeController = NULL;

	// initially load the main controller
	changeActiveController( "MainController", QStringMap() );
}

MainDlg::~MainDlg()
{
	delete _activeController;
}

/**
* Sets the parameters for the view in the javascript engine
*/
void MainDlg::addJSObject()
{
	// parameters for the rendering
	ui.webView->page()->mainFrame()->addToJavaScriptWindowObject( QString("params"), _params );

	// pass the controller object to be able to call its signals
	ui.webView->page()->mainFrame()->addToJavaScriptWindowObject( QString("controller"), _activeController );

	ui.webView->page()->settings()->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls,true);
//	ui.webView->page()->settings()->setAttribute(QWebSettings::LocalContentCanAccessFileUrls,true);
}

void MainDlg::loadFinished(bool ok)
{
	if(!ok)
		std::cerr << "Error loading the view!!" << std::endl;
}

void MainDlg::newControllerRequested(QString controller, QStringMap params)
{
	changeActiveController(controller, params);
}

void MainDlg::changeActiveController(const QString& controller, const QStringMap& params)
{
	// remove the active controller and disconnect the slot
	QObject::disconnect(this, SLOT(newControllerRequested(QString, QStringMap)));
	delete _activeController;	

	// create the new controller
	_activeController = ControllerrFactory::Instance().CreateObject( controller.toUtf8().constData() );
	_activeController->setParams(params);
	// connect signals
	QObject::connect( _activeController, SIGNAL(newControllerRequested(QString, QStringMap)), this, SLOT(newControllerRequested(QString, QStringMap)));

	_params = _activeController->run();

	// launch the view
	ui.webView->setUrl("qrc:/hvg_interface/" + _params->getViewURL() );	
}