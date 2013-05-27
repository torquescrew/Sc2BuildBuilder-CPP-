/*
 * F.cpp
 *
 *  Created on: May 6, 2012
 *      Author: Toby
 */

#include "F.h"
//#include <iostream>
//#include <sstream>
//#include "Name.h"
//#include "MersenneTwister.h"
#include "RandomSingleton.h"
#include "Config.h"
#include "GameState.h"
#include "Population.h"
//#include "ppapi/cpp/instance.h"
//#include "ppapi/cpp/module.h"
//#include "ppapi/cpp/var.h"


//template<class T> inline std::string to_string(const T& t) {
//  std::stringstream ss;
//  ss << t;
//  return ss.str();
//}

using namespace std;

string F::toString(E::Name n) {
  switch (n) {
  case E::EMPTY:
    return "empty";
  case E::SCV:
    return "SCV";
  case E::COMMAND_CENTER:
    return "Command Center";
  case E::SUPPLY_DEPOT:
    return "Supply Depot";
  case E::BARRACKS:
    return "Barracks";
  case E::BARRACKS_WITH_TECHLAB:
    return "Barracks with Techlab";
  case E::BARRACKS_WITH_REACTOR:
    return "Barracks with Reactor";
  case E::REFINERY:
    return "Refinery";
  case E::ORBITAL_COMMAND:
    return "Orbital Command";
  case E::PLANETARY_FORTRESS:
    return "Planetary Fortress";
  case E::MARINE:
    return "Marine";
  case E::MARAUDER:
    return "Marauder";
  case E::ENGINEERING_BAY:
    return "Engineering Bay";
  default:
    return "Undefined";
  }
}

//unsigned long F::nextInt(unsigned long min, unsigned long max) {
//  unsigned long r = RandomSingleton::nextInt(min, max);
//  return r;
//}

//double F::nextDouble() {
//  double r = RandomSingleton::nextDouble();
//  return r;
//}


void F::printNewUnit(E::Name name, GameState* gs) {
  stringstream ss;
  ss << displayTime(gs->getTime()) << ", ";
  ss << displayResources(gs);
  ss << displaySupply(gs);
  ss << toString(name);
  F::println(ss.str());
}

std::string F::displaySupply(GameState* gs) {
  string str;
  str.append(" (");
  str.append(to_string(gs->getSupply()));
  str.append("/");
  str.append(to_string(gs->getSupplyMax()));
  str.append(") ");
  return str;
}

std::string F::displayResources(GameState* gs) {
  std::string str;

  str.append("mins: ");
  str.append(to_string((int) gs->getMinerals()));
  str.append(", gas: ");
  str.append(to_string((int) gs->getGas()));
  str.append(" ");

//  str = makeStr("mins: " + (int) gs->getMinerals() + ", gas: " + (int) gs->getGas() + " ");

  return str;
}

std::string F::displayTime(int time) {
  std::string str;

  str += " ";
  if (time % 60 < 10) {
    str += to_string(time / 60);
    str.append(":0");
    str.append(to_string(time % 60));
  } else {
    str.append(to_string(time / 60));
    str.append(":");
    str.append(to_string(time % 60));
  }
  return str;
}

void F::printGen(int gen, Population *p) {
  stringstream ss;
  ss << "Completed generation " << (gen + 1);
  int fitness = p->getListOfBuilds().back()->getFitness();
  ss << " highest fitness: " << fitness;
  ss << " best: " << p->getHighest()->getFitness() << ".";
//  cout << ss.str() << endl;
  F::println(ss.str());
}

void F::print(string s) {
  cout << s;
}

//void F::println() {
//  cout << endl;
//}

//void F::println(S str) {
//  cout << str.get() << endl;
//}

//string F::makeStr(S str) {
//  return str.get();
//}

void F::printInit(Population* p) {
  if (p->getSize() % 1 == 0) {
    string s;
    s += "generated build ";
    s += to_string(p->getSize());
    F::println(s);
  }
}
