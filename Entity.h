/*
 * Entity.h
 *
 *  Created on: May 5, 2012
 *      Author: Toby
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include "E.h"
#include <vector>
#include <string>
#include "Name.h"
//#include "GameState.h"

//using namespace std;

class GameState;
//class AllEntities;

class Entity {
public:
  Entity();
  virtual ~Entity();
  bool meetsCosts(GameState *gs);
  void payCosts(GameState *gs);
  int getBuildTime() const;
  int getGas() const;
  int getMinerals() const;
  E::Name getName() const;
  virtual bool meetsRequired(GameState *gs);
  int getSupply() const;
  int getProvidedSupply() const;
  virtual void update(GameState *gs) {};
  virtual void complete(GameState *gs);
  virtual void reset();
  const std::vector<E::Name>& getBuiltBy() const;
  const std::vector<E::Name>& getRequired() const;
  std::string getNameStr();
  bool isCommand();
protected:
  int minerals;
  int gas;
  int buildTime;
  unsigned supply;
  E::Name name;
  std::vector<E::Name> required;
  std::vector<E::Name> builtBy;
  int providedSupply;
};

#endif /* ENTITY_H_ */
