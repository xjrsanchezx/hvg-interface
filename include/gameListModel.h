#ifndef GAME_LIST_MODE_H
#define GAME_LIST_MODE_H

#include <QStringList>
#include <QList>

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
	void getGames(const QString& machine, GameList& games) const;				///< Gets the list of games
};

#endif // GAME_LIST_MODE_H