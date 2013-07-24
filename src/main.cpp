#include <QtWidgets/QApplication>
#include "mainDlg.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainDlg dlg;

	dlg.showMaximized();

	return a.exec();
}
