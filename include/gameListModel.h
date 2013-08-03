#ifndef GAME_LIST_MODE_H
#define GAME_LIST_MODE_H

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
	void getGames(const QString& machine, GameList& games) const;						///< Gets the list of games
	QString getRomPathFromName(const QString& machine, const QString& romName) const;	///< Gets the path of a game
	QString getEmulatorPath(const QString& machine) const;								///< Gets the path to the emulator

private:
	bool connectDB(const QString& machine, QSqlDatabase& db) const;	///< Opens a connection to a DB
};

#endif // GAME_LIST_MODE_H