#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

/**
* Base class for the parameters that will be sent to the web view from the controller
*/
class ViewParams : public QObject
{
	Q_OBJECT

public:
	ViewParams() {};

	virtual QString getViewURL() const = 0;	///< Gets the URL of the view to be launched
};

/**
* Base class for all controllers
*/
class Controller
{
public:
	Controller(){};

	virtual ViewParams* run() = 0;		///< Starts the controller
};

#endif // CONTROLLER_H