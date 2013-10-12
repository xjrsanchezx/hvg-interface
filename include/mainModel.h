/**
 * Copyright (c) 2013 xjrsanchezx@yahoo.es
 *
 * Use of this source code is governed by The MIT License (MIT) license 
 * that can be found in the LICENSE file.
 */

/** \file
 * \brief Data model of the main screen
 *
 * \author xjrsanchezx@yahoo.es (Jairo R. Sánchez)
 * \copyright MIT License (MIT)
 */

#ifndef MAIN_MODEL_H
#define MAIN_MODEL_H

#include "model.h"

#include <QString>
#include <QStringList>
#include <QMap>

class MainModel
{
public:
	void getMachines(QStringList& machines);				///< Gets the list of machines
	QString getMachineDB(const QString& machine) const;			///< Gets the DB file of the given machine

private:
	QMap< QString, QString > _machineDatabases;		///< Map with the database file of each machine
};

#endif //MAIN_MODEL_H