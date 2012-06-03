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
class AllEntities;
class Entity;

class GameState {
public:
  GameState();
  virtual ~GameState();
  void init();
  void incrementTime();
  double getGas() const;
  double getMinerals() const;
  int getSupply() const;
  int getSupplyMax() const;
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
  double minerals;
  double gas;
  int time;
  int supply;
  int supplyMax;
  AllEntities *ae;
};

#endif /* GAMESTATE_H_ */
