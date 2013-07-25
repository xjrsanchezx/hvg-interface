#ifndef INFO_CONTROLLER_H
#define INFO_CONTROLLER_H

#include "controller.h"

/**
* Parameters that will be sent to the mainView 
*/
class InfoViewParams : public ViewParams
{
	Q_OBJECT

public:
	InfoViewParams() {};

	QString getViewURL() const {return QString("infoView.html");};

	Q_PROPERTY(QString machineURL READ getMachineURL WRITE setMachineURL)	

	Q_INVOKABLE  QString getMachineURL() {return _machineURL;};	
	Q_INVOKABLE  void setMachineURL(QString& url) {_machineURL = url; };
	
private:
	QString _machineURL;		///< The URL of the machine description page

};


/**
* The controller of the machine information screen. This window displays 
* the webpage with the info of the machine. It is a very simple controller
* so it does not have a model associated.
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
	QString _machine;				///< The name of the selected machine
};


#endif // INFO_CONTROLLER_H