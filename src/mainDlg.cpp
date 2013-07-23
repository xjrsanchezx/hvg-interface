#include "mainDlg.h"
#include <qwebframe.h>
#include <iostream>

MainDlg::MainDlg(QWidget *parent /*= 0*/)
	: QMainWindow(parent)
{
	ui.setupUi(this);	

	// force the signal linkClicked to be called when clicking
	ui.webView->page()->setLinkDelegationPolicy(QWebPage::LinkDelegationPolicy::DelegateAllLinks);

	// Signal is emitted before frame loads any web content:
    QObject::connect((QObject*)ui.webView->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
                     this, SLOT(addJSObject()) );

	// signal emitted after loading the page
	QObject::connect((QObject*)ui.webView, SIGNAL(loadFinished(bool)), this, SLOT(loadFinished(bool)));

	// initially load the main controller
	_activeController = new MainController();
	_params = _activeController->run();

	// launch the view
	ui.webView->setUrl("qrc:/hvg_interface/" + _params->getViewURL() );	
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

	int a=0;
}

void MainDlg::loadFinished(bool ok)
{
	if(!ok)
		std::cerr << "Error loading the view!!" << std::endl;
}
