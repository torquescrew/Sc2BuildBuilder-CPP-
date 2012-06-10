/*
 * AllEntities.h
 *
 *  Created on: May 5, 2012
 *      Author: Toby
 */

#ifndef ALLENTITIES_H_
#define ALLENTITIES_H_
#include "Entity.h"
#include "Command.h"
#include <vector>
#include "EntityPool2.h"

using namespace std;
class Entity;
class GameState;
//class EntityPool2;

class AllEntities {
public:
  AllEntities(EntityPool2 *entityPool);
  virtual ~AllEntities();
  void update(GameState *gs);
  bool contains(E::Name);
  vector<Entity*>& getEntities();
  void addNew(Entity *e);
  void directAdd(Entity *e);
  bool tryAddEntity(Entity *e, int time);
  void transferNewEntities(GameState *gs);
  void printEntities();
  void gatherIdleWorkers();
  int idleWorkerIndex();
  vector<Command*> getCommands();
  void sendToMine(Entity *scv);
  bool takeScvOffMining();
  Entity* getScvOffMining();
  bool inert(E::Name);
  int getNumOf(Entity *e);
  
private:
  AllEntities();
  vector<Entity*> entities;
  vector<Entity*> newEntities;
  EntityPool2 *entityPool;
};

#endif /* ALLENTITIES_H_ */
