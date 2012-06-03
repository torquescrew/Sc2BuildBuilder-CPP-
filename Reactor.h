/* 
 * File:   Reactor.h
 * Author: Toby
 *
 * Created on May 9, 2012, 11:18 AM
 */

#ifndef REACTOR_H
#define	REACTOR_H
#include "BuildSlot.h"
#include "Producer.h"

class Reactor : public Producer {
public:
  Reactor();
  virtual ~Reactor();
  bool checkForBuilt(int time);
  bool tryBuildEntity(Entity *e, int time);
  Entity *getBuiltEntity();
  bool busy() const;
  void update(GameState *gs);
private:
  BuildSlot *bs2;
  int checkTime;

};

#endif	/* REACTOR_H */

