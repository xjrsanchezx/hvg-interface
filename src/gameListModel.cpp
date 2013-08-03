#include "gameListModel.h"
#include "config.h"

#include <QDir>

#include <iostream>

bool GameListModel::connectDB(const QString& machine, QSqlDatabase& db) const
{
	// open the machine directory and look for a game database
	QString dbDir = QString(HVG_PATH"/") + machine + "/" + machine +".mdb";
	
	db = QSqlDatabase::addDatabase("QODBC");
	db.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ="+dbDir);
	
	if (!db.open()) 
	{
		std::cerr << "GameListModel: Game database not found!" << std::endl;
		return false;;
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
	
	QSqlDatabase db;

	if( !connectDB(machine, db) )
		return;

	// The name of the table is HVGn where n is the recopilation number
	QString tableName = (db.tables())[0];

	QSqlQuery query("SELECT NOMBRE, ROM, IMAGEN, best, snapdir, manual, info FROM "+tableName);

	while(query.next() )
	{
		GameInfo game;

		game.name = query.value(0).toString();
		game.rom = query.value(1).toString();
		
		// get path to images

	//	game.comment = query.value(3).toString();
	//	game.publisher = query.value(4).toString();		
		game.recommended = query.value(3).toString() == "si" ? true : false;
		game.manual = query.value(5).toString();
		game.info = query.value(6).toString();

		games.push_back(game);
	}
}

/**
* \param[in] machine The name of the machine
* \param[in] romName The name of the game
* \returns The full path to the rom. It may not exist!
*/
QString GameListModel::getRomPathFromName(const QString& machine, const QString& romName) const
{
	QSqlDatabase db;

	if( !connectDB(machine, db) )
		return "";

	// The name of the table is HVGn where n is the recopilation number
	QString tableName = (db.tables())[0];
	QString queryString = "SELECT ROM FROM " + tableName + " WHERE NOMBRE = :romName";

	QSqlQuery query;
	query.prepare(queryString);
	query.bindValue(":romName", romName);
	query.exec();

	if(query.next() )
		return QString(HVG_PATH"/") + machine + "/games/" + query.value(0).toString();
	else
		return "";
}

QString GameListModel::getEmulatorPath(const QString& machine) const
{
	// they are under c:\hvg\hvgn directory	where n is the recopilation number
	// the easiest way is to open again the database
	QSqlDatabase db;

	if( !connectDB(machine, db) )
		return "";

	// The name of the table is HVGn where n is the recopilation number
	QString tableName = (db.tables())[0];

	return QString("c:/hvg/") + tableName.toLower() + "/" + machine.toLower() + "/emulator/loader_" + machine.toLower() + ".exe";
}