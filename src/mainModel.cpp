#include "mainModel.h"
#include "config.h"

#include <QDir>

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
		 subDir.setNameFilters(QStringList() << "*.mdb");

		 QStringList databases = subDir.entryList();
		 
		 if(databases.size() == 1 && dirname != "." && dirname != "..")
		 {
			 machines << dirname;
		 }
	 }
}