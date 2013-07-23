#ifndef MAINDLG_H
#define MAINDLG_H

#include <QtWidgets/QMainWindow>
#include <QtWebKitWidgets\qwebview.h>
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
	

public slots:
	void addJSObject();
	void loadFinished(bool ok);

private:
	Ui::MainDlgClass ui;

	Controller* _activeController;		///< Running controller
	ViewParams* _params;
};

#endif // MAINDLG_H
