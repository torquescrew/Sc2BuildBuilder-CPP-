/* 
 * File:   Marine.h
 * Author: Toby
 *
 * Created on May 8, 2012, 4:19 AM
 */

#ifndef MARINE_H
#define	MARINE_H
#include "Entity.h"

class Marine : public Entity {
public:
  Marine();
  virtual ~Marine();
  void update(GameState *gs);
  void complete(GameState *gs);
private:

};

#endif	/* MARINE_H */

