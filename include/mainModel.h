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

#include <QStringList>

class MainModel
{
public:
	void getMachines(QStringList& machines) const;				///< Gets the list of machines
};

#endif //MAIN_MODEL_H