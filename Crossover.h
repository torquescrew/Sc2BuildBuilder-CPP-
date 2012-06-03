/*
 * Crossover.h
 *
 *  Created on: Feb 23, 2012
 *      Author: Toby
 */

#ifndef CROSSOVER_H_
#define CROSSOVER_H_

#include "BuildList.h"
#include "Config.h"

class Crossover {
public:
	Crossover();
	virtual ~Crossover();
	BuildList* createChild(BuildList* b1, BuildList* b2);
private:
	BuildList* singlePoint(BuildList* b, BuildList *b2);
};

#endif /* CROSSOVER_H_ */
