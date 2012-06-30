/*
 * Command.h
 *
 *  Created on: May 6, 2012
 *      Author: Toby
 */

#ifndef COMMAND_H_
#define COMMAND_H_
#include <vector>
#include "Producer.h"
//#include "Entity.h"
//#include "AllEntities.h"

//class Supplier;

class Command : public Producer {
public:
  Command();
  virtual ~Command();
  void update(GameState *gs);
  void complete(GameState *gs);
  void reset();
  void sendToMineMinerals(Entity *scv);
  bool tryAttachRefinery();
  Entity* getScv();
  unsigned numberMining();
  void setAttachedRefineries(int n); // TODO delete this
  int getAttachedRefineries();
  std::vector<Entity*> & getWorkersOnMinerals(); // delete this?
  void transferWorkers(std::vector<Entity *> &workersOnMinerals);
  int getProvidedSupply();
protected:
  double mineralsMined(int n);
  std::vector<Entity*> workersOnMinerals;
  int attachedRefineries;
  //  int providedSupply;
};

#endif /* COMMAND_H_ */
