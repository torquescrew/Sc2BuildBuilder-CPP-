/*
 * Crossover.cpp
 *
 *  Created on: Feb 23, 2012
 *      Author: Toby
 */

#include "Crossover.h"
#include "BuildList.h"
#include "F.h"
#include <cstdlib>
#include <iostream>


Crossover::Crossover() {
}

Crossover::~Crossover() {
}

BuildList* Crossover::createChild(BuildList* b1, BuildList* b2) {
  BuildList *c = singlePoint(b1, b2);
  BuildList *c2 = singlePoint(b1, b2);
  if (c->getFitness() > c2->getFitness()) {
    delete c2;
    return c;
  }
  else {
    delete c;
    return c2;
  }
  
//	return singlePoint(b1, b2);
}

BuildList* Crossover::singlePoint(BuildList* b, BuildList* b2) {
  unsigned long num = b->getEventNum();
  if (num == 0) {
    num++;
  }
  unsigned long crossPoint = F::nextInt(1, num);

	BuildList *child = new BuildList();

	for (unsigned long i = 0; i < crossPoint; i++) {
		child->add(b->get(i));
	}
	for (unsigned long i = crossPoint; i < b->size(); i++) {
		child->add(b2->get(i));
	}
	child->evaluateBuild();
	return child;
}



