#ifndef CONTROLLER_H
#define CONTROLLER_H

/**
* Base class for all controllers
*/
class Controller
{
public:
	Controller(){};

	virtual void run() = 0;		///< Starts the controller
};

#endif // CONTROLLER_H