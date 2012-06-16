/*
 * GameState.cpp
 *
 *  Created on: May 5, 2012
 *      Author: Toby
 */

#include "GameState.h"
#include "AllEntities.h"
#include "Entity.h"
#include "F.h"
#include "CommandCenter.h"
#include "Scv.h"
//#include "Config.h"
//#include "ObjectPool.h"
#include <iostream>
#include "OF.h"

GameState::GameState(OF *oF) {
  this->oF = oF;
  minerals = 50.0;
  gas = 0.0;
  time = 0;
  supply = 6;
  supplyMax = 11;
  ae = new AllEntities(this->oF);

//  std::cout << "GameState() entityPool address: " << this->entityPool << std::endl;
  init();
}

GameState::GameState() {
  std::cout << "GameState()" << std::endl;
}

GameState::~GameState() {
  delete ae;
}

void GameState::init() {
  Info scv(E::SCV);
  Info command(E::COMMAND_CENTER);

  ae->directAdd(oF->newEntity(command));
  ae->directAdd(oF->newEntity(scv));
  ae->directAdd(oF->newEntity(scv));
  ae->directAdd(oF->newEntity(scv));
  ae->directAdd(oF->newEntity(scv));
  ae->directAdd(oF->newEntity(scv));
  ae->directAdd(oF->newEntity(scv));

//  ae->directAdd(ObjectPool::get(command));
//  ae->directAdd(ObjectPool::get(scv));
//  ae->directAdd(ObjectPool::get(scv));
//  ae->directAdd(ObjectPool::get(scv));
//  ae->directAdd(ObjectPool::get(scv));
//  ae->directAdd(ObjectPool::get(scv));
//  ae->directAdd(ObjectPool::get(scv));
  ae->update(this);

//  delete scv;
//  delete command;
}

void GameState::incrementTime() {
  time++;
  ae->update(this);
}

bool GameState::tryAddEntity(Entity* e) {
  if (e->meetsCosts(this)) {
    if (ae->tryAddEntity(e, time)) {
      e->payCosts(this);
      return true;
    }
  }
  return false;
}

double GameState::getGas() const {
  return gas;
}

double GameState::getMinerals() const {
  return minerals;
}

unsigned GameState::getSupply() const {
  return supply;
}

unsigned GameState::getSupplyMax() const {
  return supplyMax;
}

int GameState::getTime() const {
  return time;
}

void GameState::addSupplyMax(int supply) {
  this->supplyMax += supply;
}

AllEntities* GameState::getAe() {
  return ae;
}

void GameState::addSupply(int supply) {
  this->supply += supply;
}

void GameState::addMinerals(double mins) {
  this->minerals += mins;
}

void GameState::spendMinerals(double mins) {
  this->minerals -= mins;
}

void GameState::addGas(double gas) {
  this->gas += gas;
}

void GameState::spendGas(double gas) {
  this->gas -= gas;
}


