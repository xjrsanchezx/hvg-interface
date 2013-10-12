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

#include "infoModel.h"

#include <iostream>
#include <QFile>
#include <QDir>
#include <QtSql>

QString InfoModel::getInfoURL(const QString& machine) const
{
	if( !QFile::exists(_dbFileName) )
	{
		std::cerr << "InfoModel: Machine database not found!" << std::endl;
		return "";
	}

	QSqlDatabase *db;
	// Find QSLite driver and create the file
	db = new QSqlDatabase( QSqlDatabase::addDatabase("QSQLITE") );
			
	db->setDatabaseName(_dbFileName);

	// Open the database
	if (!db->open()) 
	{
		std::cerr << "InfoModel: Cannot open machine database" << std::endl;
		CLOSE_DB(db)

		return "";
	}

	// create the table with the machine info	
	QSqlQuery query;
			 
	query.exec("SELECT infoURL FROM machine");

	QString url ="";

	if(query.next() )
		url = query.value(0).toString();	 	
	query.clear();
			 
	CLOSE_DB(db)

	if(url == "") return "";

	// get the absolute path
	QDir dbPath = QFileInfo(_dbFileName).absoluteDir();

	return dbPath.absolutePath() + "/" + url;
}