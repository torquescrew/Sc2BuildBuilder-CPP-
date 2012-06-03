/* 
 * File:   Refinery.h
 * Author: Toby
 *
 * Created on May 8, 2012, 3:52 PM
 */

#ifndef REFINERY_H
#define	REFINERY_H
#include "Entity.h"
#include "Refinery.h"
#include "GameState.h"
#include "AllEntities.h"
#include "Command.h"
#include "Config.h"

class Refinery : public Entity {
public:
  Refinery();
  virtual ~Refinery();
  double gasMined();
  int workersOnGas();
  void update(GameState *gs);
  void sendToMine(Entity *e);
  Entity* takeScvOffGas();
  void reset();
  virtual bool meetsRequired(GameState *gs);
private:
  vector<Entity*> workers;
  unsigned long wantedScvs;
  bool attachedToCommand;
  bool isAttachedToCommand(GameState *gs);
  bool tryAttachToCommand(GameState *gs);
};

#endif	/* REFINERY_H */

