#include "mainDlg.h"

MainDlg::MainDlg(QWidget *parent /*= 0*/)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// initially load the main controller
	_activeController = new MainController();
	_activeController->run();
}

MainDlg::~MainDlg()
{
	delete _activeController;
}
