/*
 * Producer.h
 *
 *  Created on: May 6, 2012
 *      Author: Toby
 */

#ifndef PRODUCER_H_
#define PRODUCER_H_
#include "Entity.h"
#include "BuildSlot.h"
//#include "GameState.h"

class Producer : public Entity {
public:
  Producer();
  virtual ~Producer();
  bool checkForBuilt(int time);
  bool tryBuildEntity(Entity *e, int time);
  Entity* getBuiltEntity();
  void acknowledgeBuilt();
  bool busy() const;
  void update(GameState *gs);
  void reset();
//  void clearBuildSlot();
  bool buildingAddon();
  
protected:
  BuildSlot *bs;
};

#endif /* PRODUCER_H_ */
