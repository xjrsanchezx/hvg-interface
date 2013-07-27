#include "gameListModel.h"
#include "config.h"

#include <QDir>
#include <QtSql>

#include <iostream>

/**
* Gets the complete info of videogames for a given machine
*
* \param[in] machine The name of the machine
* \param[out] games The list of available games
*/
void GameListModel::getGames(const QString& machine, GameList& games)  const
{
	games.clear();

	// open the machine directory and look for a game database
	QString dbDir = QString(HVG_PATH"/") + machine + "/" + machine +".mdb";
	
	QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
	db.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ="+dbDir);
	
	if (!db.open()) 
	{
		std::cerr << "GameListModel: Game database not found!" << std::endl;
		return;
	}

	QSqlQuery query("SELECT NOMBRE, ROM, IMAGEN, COMENTARIO, best, snapdir, manual, info FROM HVG3");

	while(query.next() )
	{
		GameInfo game;

		game.name = query.value(0).toString();
		game.rom = query.value(1).toString();
		
		// get path to images

		game.comment = query.value(3).toString();
	//	game.publisher = query.value(4).toString();		
		game.recommended = query.value(4).toString() == "si" ? true : false;
		game.manual = query.value(6).toString();
		game.info = query.value(7).toString();

		games.push_back(game);
	}
}