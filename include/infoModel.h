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

#ifndef INFO_MODEL_H
#define INFO_MODEL_H

#include "model.h"

#include "QString"

class InfoModel
{
public:
	InfoModel(){};

	void setDatabaseFile(const QString& dbFileName) { _dbFileName = dbFileName; };
	QString getMachineDB() const { return _dbFileName; };
	QString getInfoURL(const QString& machine) const;

private:
	QString _dbFileName;
};

#endif //INFO_MODEL_H