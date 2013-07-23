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
class Controller : public QObject
{
	Q_OBJECT

public:
	Controller(){};

	virtual ViewParams* run() = 0;		///< Starts the controller

	// slots used to respond to javascript events
	// controllers can asign slots to these signals
public slots:
	virtual void elementActivated(QString id) {};		///< inform that an interface element has been activated

signals:
	void newControllerRequested(QString controller);	///< emitted when the controller requests to give up the controll to other controller
};

#endif // CONTROLLER_H