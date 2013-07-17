#ifndef MAINDLG_H
#define MAINDLG_H

#include <QtWidgets/QMainWindow>
#include "ui_hvg_main.h"

// controllers
#include "mainController.h"

class MainDlg : public QMainWindow
{
	Q_OBJECT

public:
	MainDlg(QWidget *parent = 0);
	~MainDlg();

private:
	Ui::MainDlgClass ui;

	Controller* _activeController;		///< Running controller

};

#endif // MAINDLG_H
