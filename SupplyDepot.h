/* 
 * File:   SupplyDepot.h
 * Author: Toby
 *
 * Created on May 8, 2012, 1:46 AM
 */

#ifndef SUPPLYDEPOT_H
#define	SUPPLYDEPOT_H
#include "Entity.h"

class GameState;

class SupplyDepot : public Entity {
public:
  SupplyDepot();
  virtual ~SupplyDepot();
  void complete(GameState* gs);
  void update(GameState *gs);
private:

};

#endif	/* SUPPLYDEPOT_H */

