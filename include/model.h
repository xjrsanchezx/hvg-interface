/**
 * Copyright (c) 2013 xjrsanchezx@yahoo.es
 *
 * Use of this source code is governed by The MIT License (MIT) license 
 * that can be found in the LICENSE file.
 */

/** \file
 * \brief Base classes for controllers.
 *
 * \author xjrsanchezx@yahoo.es (Jairo R. Sánchez)
 * \copyright MIT License (MIT)
 */

#ifndef MODEL_H
#define MODEL_H

/// Macro that closes a sqlite database cleanly
#define CLOSE_DB(db) 	{QString connection = (db)->connectionName(); \
						(db)->close(); \
						delete (db); \
						QSqlDatabase::removeDatabase(connection); }



#endif // MODEL_H