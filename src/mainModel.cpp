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

/**
* \param[out] machines A vector with the names of existing machines
*/
void MainModel::getMachines(QStringList& machines) const
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
		 subDir.setNameFilters(QStringList() << "*.mdb");

		 QStringList databases = subDir.entryList();
		 
		 if(databases.size() == 1 && dirname != "." && dirname != "..")
		 {
			 machines << dirname;
		 }
	 }
}