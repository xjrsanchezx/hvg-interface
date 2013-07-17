#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include "controller.h"
#include "mainModel.h"

/**
* The controller of the main window. This window displays available machines
*/
class MainController : public Controller
{
public:
	MainController() {};
	~MainController() {};

	void run();

private:
	MainModel _model;		///< Data model
};

#endif // MAIN_CONTROLLER_H