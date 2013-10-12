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


#include "mainModel.h"
#include "config.h"

#include <QDir>
#include <QtSql>

/**
* \param[out] machines A vector with the names of existing machines
*/
void MainModel::getMachines(QStringList& machines)
{
	// open the hvg directory and look for all directories containing a game database
	 QDir hvgDir(HVG_PATH);

	 hvgDir.setFilter(QDir::Dirs);

	 QStringList entries = hvgDir.entryList();

	 for( QStringList::ConstIterator entry=entries.begin(); entry!=entries.end(); ++entry )
	 {
		 QString dirname=*entry;

		 // check if the mdb file is present
		 QString subDirName = HVG_PATH;
		 subDirName.push_back("\\");
		 subDirName.push_back(dirname);

		 QDir subDir(subDirName);
		 subDir.setNameFilters(QStringList() << "*.sqlite");

		 QStringList databases = subDir.entryList();
		 
		 // open the sqlite database and read the names
		 if(databases.size() == 1 && dirname != "." && dirname != "..")
		 {		
			 QString dbFileName = subDirName + "/" + databases[0];

			 if( !QFile::exists(dbFileName) )
				 continue;

			 QSqlDatabase *db;
			 // Find QSLite driver and create the file
			 db = new QSqlDatabase( QSqlDatabase::addDatabase("QSQLITE") );
			
			 db->setDatabaseName(dbFileName);

			 // Open the database
			 if (!db->open()) 
			 {
				 CLOSE_DB(db)
				 continue;
			 }

			 // create the table with the machine info	
			 QSqlQuery query;
			 
			 query.exec("SELECT name FROM machine");

			 QString name = "";

			 if(query.next() )
			 {
				 name = query.value(0).toString();	 
				 machines << name;
			 }

			 query.clear();
			 
			 CLOSE_DB(db)

			 if(name != "")
				_machineDatabases.insert(name, dbFileName);
		 }
	 }
}

QString MainModel::getMachineDB(const QString& machine) const
{
	if( _machineDatabases.find(machine) != _machineDatabases.end() )
		return _machineDatabases[machine];
	return "";
}