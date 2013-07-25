#ifndef MAINDLG_H
#define MAINDLG_H

#include <QtWidgets/QMainWindow>
#include <QtWebKitWidgets\qwebview.h>
#include "ui_hvg_main.h"

// controllers
#include "controller.h"

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

	void newControllerRequested(QString controller, QStringMap params);	///< emited by controllers

private:
	void changeActiveController(const QString& controller, const QStringMap& params);

private:
	Ui::MainDlgClass ui;

	Controller* _activeController;		///< Running controller
	ViewParams* _params;
};

#endif // MAINDLG_H
