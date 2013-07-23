#include "mainController.h"
#include <iostream>

ViewParams* MainController::run()
{
	// get the list of machines
	QStringList machines;

	_model.getMachines(machines);
	_params.setMachines(machines);

	std::cout << machines.size();

	return &_params;
}

void MainController::elementActivated(QString id)
{
	std::cout << id.toUtf8().constData() << std::endl;

	emit newControllerRequested("hello");
}