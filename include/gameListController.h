/**
 * Copyright (c) 2013 xjrsanchezx@yahoo.es
 *
 * Use of this source code is governed by The MIT License (MIT) license that can be
 * found in the LICENSE file.
 */

/** \file
 * \brief Controller of the game list screen.
 *
 * \author xjrsanchezx@yahoo.es (Jairo R. Sánchez)
 * \copyright MIT License (MIT)
 */


#ifndef GAME_LIST_CONTROLLER_H
#define GAME_LIST_CONTROLLER_H

#include "controller.h"
#include "gameListModel.h"

#include <QProcess>

/**
* Parameters that will be sent to the game list view 
*/
class GameListViewParams : public ViewParams
{
	Q_OBJECT

public:
	GameListViewParams() {};

	QString getViewURL() const {return QString("gameListView.html");};

	Q_PROPERTY(GameList gameList READ getGameList WRITE setGameList)	
	
	Q_INVOKABLE  GameList getGameList() const {return _gameList;};	
	Q_INVOKABLE  void setGameList(GameList& games) { _gameList = games; };

	Q_INVOKABLE int getNumGames() const { return _gameList.size(); };
	Q_INVOKABLE QString getGameName(int i) const { return _gameList[i].name; };
	
private:
	GameList _gameList;		///< The list of available games

};


/**
* The controller of the game list. This window displays 
* the list of viedeogames available for a specific machine
* and launches the emulator
*/ 
class GameListController : public Controller
{
	Q_OBJECT

public:
	GameListController();
	~GameListController();

	ViewParams* run();
	void setParams(const QStringMap& params);

public slots:
	void elementActivated(QString id);

private:
	GameListViewParams _params;			///< The params to pass to the view
	GameListModel _model;				///< The data model
	QString _machine;					///< The name of the selected machine

	 QProcess *_emulatorProcess;		///< The process of the emulator
};


#endif // GAME_LIST_CONTROLLER_H