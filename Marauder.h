/* 
 * File:   Marauder.h
 * Author: Toby
 *
 * Created on May 9, 2012, 9:46 AM
 */

#ifndef MARAUDER_H
#define	MARAUDER_H
#include "Entity.h"

class Marauder : public Entity {
public:
  Marauder();
  virtual ~Marauder();
  void update(GameState *gs);
  void complete(GameState *gs);
private:

};

#endif	/* MARAUDER_H */

