/*
 * GameState.h
 *
 *  Created on: May 5, 2012
 *      Author: Toby
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_
//#include "Entity.h"
//#include "Event.h"
#include "NameList.h"
#include "AllEntities.h"
#include "EntityPool2.h"

class AllEntities;
class Entity;
class OF;

class GameState {
public:
  GameState(OF *oF);
  virtual ~GameState();
  void init();
  void incrementTime();
  double getGas() const;
  double getMinerals() const;
  unsigned getSupply() const;
  unsigned getSupplyMax() const;
  int getTime() const;
  void addSupply(int supply);
  void addSupplyMax(int supplyMax);
  void addMinerals(double mins);
  void spendMinerals(double mins);
  void addGas(double gas);
  void spendGas(double gas);
  AllEntities* getAe();
  bool tryAddEntity(Entity* e);

private:
  GameState();
  OF *oF;
  double minerals;
  double gas;
  int time;
  int supply;
  int supplyMax;
  AllEntities *ae;
};

#endif /* GAMESTATE_H_ */
