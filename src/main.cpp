/**
 * Copyright (c) 2013 xjrsanchezx@yahoo.es
 *
 * Use of this source code is governed by The MIT License (MIT) license 
 * that can be found in the LICENSE file.
 */

/** \file 
 * \author xjrsanchezx@yahoo.es (Jairo R. Sánchez)
 * \copyright MIT License (MIT)
 */


#include <QtWidgets/QApplication>
#include "mainDlg.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainDlg dlg;

	dlg.showMaximized();

	return a.exec();
}
