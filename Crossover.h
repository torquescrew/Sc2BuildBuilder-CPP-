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
#include "OF.h"
//#include "EntityPool2.h"

//class ObjectFact;

class Crossover {
public:
  Crossover(OF *oF);
	virtual ~Crossover();
	BuildList* createChild(BuildList* b1, BuildList* b2);
private:
	BuildList* singlePoint(BuildList* b, BuildList *b2);
  OF *oF;
};

#endif /* CROSSOVER_H_ */
