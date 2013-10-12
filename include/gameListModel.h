/**
 * Copyright (c) 2013 xjrsanchezx@yahoo.es
 *
 * Use of this source code is governed by The MIT License (MIT) license 
 * that can be found in the LICENSE file.
 */

/** \file
 * \brief The data model of the game list controller.
 *
 * \author xjrsanchezx@yahoo.es (Jairo R. Sánchez)
 * \copyright MIT License (MIT)
 */

#ifndef GAME_LIST_MODE_H
#define GAME_LIST_MODE_H

#include "model.h"

#include <QStringList>
#include <QList>
#include <QtSql>

/**
* Structure contaning the info of a single game
*/
struct GameInfo
{
	QString name;			///< The name of the game
	QString rom;			///< The path to the rom
	QStringList images;		///< The paths to the images
	QString comment;		///< Additional comment
//	QString publisher;		///< The publisher
//	bool official;			///< is the game official?
	QString manual;			///< path to the manual pdf
	QString info;			///< path to the info pdf
	bool recommended;		///< is the game recommended?
};

typedef QList<GameInfo> GameList;

class GameListModel
{
public:
	void setDatabaseFile(const QString& dbFileName) { _dbFileName = dbFileName; };
	QString getMachineDB() const { return _dbFileName; };

	void getGames(GameList& games) const;						///< Gets the list of games
	QString getRomPathFromName(const QString& romName) const;	///< Gets the path of a game
	QString getEmulatorPath() const;							///< Gets the path to the emulator

private:
	bool connectDB(QSqlDatabase** db) const;	///< Opens a connection to a DB

private:
	QString _dbFileName;
};

#endif // GAME_LIST_MODE_H