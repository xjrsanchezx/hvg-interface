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


#include "gameListModel.h"
#include "config.h"

#include <QDir>

#include <iostream>

bool GameListModel::connectDB(QSqlDatabase** db) const
{	
	// Find QSLite driver and create the file
	*db = new QSqlDatabase( QSqlDatabase::addDatabase("QSQLITE") );
			
	(*db)->setDatabaseName(_dbFileName);

	// Open the database
	if (!(*db)->open()) 
	{
		std::cerr << "GameListModel: Game database not found! " << _dbFileName.toStdString() << std::endl;
		CLOSE_DB(*db)

		return false;
	}

	return true;
}

/**
* Gets the complete info of videogames for a given machine
*
* \param[out] games The list of available games
*/
void GameListModel::getGames(GameList& games)  const
{
	games.clear();
	
	QSqlDatabase *db;

	if( !connectDB(&db) )
		return;

	QSqlQuery query("SELECT name, rom FROM games");

	while(query.next() )
	{
		GameInfo game;

		game.name = query.value(0).toString();
		game.rom = query.value(1).toString();

		games.push_back(game);
	}

	query.clear();

	CLOSE_DB(db)
}

/**
* \param[in] romName The name of the game
* \returns The full path to the rom. It may not exist!
*/
QString GameListModel::getRomPathFromName(const QString& romName) const
{
	QSqlDatabase *db;

	if( !connectDB(&db) )
		return "";

	QString queryString = "SELECT rom FROM games WHERE name = :romName";

	QSqlQuery query;
	query.prepare(queryString);
	query.bindValue(":romName", romName);
	query.exec();

	QString path = "";

	if(query.next() )
		path = query.value(0).toString();
	
	query.clear();

	// get the rom folder
	queryString = "SELECT romFolder FROM machine";
	query.prepare(queryString);
	query.exec();

	QString romFolder = "";

	if(query.next() )
		romFolder = query.value(0).toString();
	
	query.clear();

	CLOSE_DB(db)

	if(path == "") return "";

	QDir dbPath = QFileInfo(_dbFileName).absoluteDir();
	path =  dbPath.absolutePath() + "/" + romFolder + "/" + path;

	return path;
}

QString GameListModel::getEmulatorPath() const
{
	QSqlDatabase *db;

	if( !connectDB(&db) )
		return "";

	QString queryString = "SELECT emulator FROM machine";

	QSqlQuery query;
	query.prepare(queryString);	
	query.exec();

	QString path = "";
	
	if(query.next() )
	{
		path = query.value(0).toString();
	}

	query.clear();
	
	CLOSE_DB(db)

	if(path == "") return "";
		
	QDir dbPath = QFileInfo(_dbFileName).absoluteDir();
	path =  dbPath.absolutePath() + "/" + path;

	return path;
}