/*
 * BuildSlot.h
 *
 *  Created on: May 6, 2012
 *      Author: Toby
 */

#ifndef BUILDSLOT_H_
#define BUILDSLOT_H_
#include "Entity.h"

class BuildSlot {
public:
	BuildSlot();
	virtual ~BuildSlot();
	bool isBusy() const;
	int getFinishTime() const;
	bool tryBuild(Entity *e, int time);
	bool checkForFinished(int time);
	Entity* getNewEntity();
  void reset();
  bool eIsUnit();
private:
	Entity *e;
	bool busy;
	int finishTime;
};

#endif /* BUILDSLOT_H_ */
