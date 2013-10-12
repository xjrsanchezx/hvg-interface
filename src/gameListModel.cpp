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

bool GameListModel::connectDB(const QString& machine, QSqlDatabase** db) const
{	
	// Find QSLite driver and create the file
	*db = new QSqlDatabase( QSqlDatabase::addDatabase("QSQLITE") );
			
	(*db)->setDatabaseName(_dbFileName);

	// Open the database
	if (!(*db)->open()) 
	{
		std::cerr << "GameListModel: Game database not found!" << std::endl;
		CLOSE_DB(*db)

		return false;
	}

	return true;
}

/**
* Gets the complete info of videogames for a given machine
*
* \param[in] machine The name of the machine
* \param[out] games The list of available games
*/
void GameListModel::getGames(const QString& machine, GameList& games)  const
{
	games.clear();
	
	QSqlDatabase *db;

	if( !connectDB(machine, &db) )
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
* \param[in] machine The name of the machine
* \param[in] romName The name of the game
* \returns The full path to the rom. It may not exist!
*/
QString GameListModel::getRomPathFromName(const QString& machine, const QString& romName) const
{
	QSqlDatabase *db;

	if( !connectDB(machine, &db) )
		return "";

	QString queryString = "SELECT rom FROM games WHERE NOMBRE = :romName";

	QSqlQuery query;
	query.prepare(queryString);
	query.bindValue(":romName", romName);
	query.exec();

	QString path = "";

	if(query.next() )
		path =  QString(HVG_PATH"/") + machine + "/games/" + query.value(0).toString();
	
	query.clear();
	CLOSE_DB(db)

	return path;
}

QString GameListModel::getEmulatorPath(const QString& machine) const
{
	// they are under c:\hvg\hvgn directory	where n is the recopilation number
	// the easiest way is to open again the database
/*	QSqlDatabase db;

	if( !connectDB(machine, db) )
		return "";

	// The name of the table is HVGn where n is the recopilation number
	QString tableName = (db.tables())[0];

	return QString("c:/hvg/") + tableName.toLower() + "/" + machine.toLower() + "/emulator/loader_" + machine.toLower() + ".exe";*/
	return "";
}