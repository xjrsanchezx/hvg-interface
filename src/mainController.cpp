#include "mainController.h"
#include <iostream>

void MainController::run()
{
	// get the list of machines
	QStringList machines;

	_model.getMachines(machines);

	std::cout << machines.size();
}