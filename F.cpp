/*
 * F.cpp
 *
 *  Created on: May 6, 2012
 *      Author: Toby
 */

#include "F.h"
#include <iostream>
#include <sstream>
#include "Name.h"
//#include "MersenneTwister.h"
#include "RandomSingleton.h"
#include "Config.h"
//#include "ppapi/cpp/instance.h"
//#include "ppapi/cpp/module.h"
//#include "ppapi/cpp/var.h"


template<class T> inline std::string to_string(const T& t) {
  std::stringstream ss;
  ss << t;
  return ss.str();
}

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

unsigned long F::nextInt(unsigned long min, unsigned long max) {
//  MTRand gen;
//  unsigned long r = min + gen.randInt(max - 1 - min);
  //  int r = gen.randInt()

//  unsigned long r = min+int(range*rand()/(max + 1));
//  Random gen;
//  return Random::uniform(min, max);
//  return gen.uniform(min, max);

  unsigned long r = RandomSingleton::nextInt(min, max);

//  cout << "nextInt(" << min << ", " << max << ") = " << r << endl;

  return r;
}

double F::nextDouble() {

//  MTRand gen;
//  return gen.rand();
//  Random gen;
//  return gen.uniform();

  double r = RandomSingleton::nextDouble();
//  cout << r << endl;

  return r;
}


void F::printNewUnit(E::Name name, GameState* gs) {
  stringstream ss;
  ss << displayTime(gs->getTime()) << ", ";
  ss << displayResources(gs);
  ss << displaySupply(gs);
  ss << toString(name);
  println(ss.str());
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

  return str;
}

std::string F::displayTime(int time) {
  std::string str;

  str.append(" ");
  if (time % 60 < 10) {
    str.append(to_string(time / 60));
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
  ss << "completed generation " << (gen + 1);
  ss << " highest fitness: " << p->getListOfBuilds().back()->getFitness();
  ss << " best: " << p->getHighest()->getFitness();
  println(ss.str());
}

void F::print(string s) {
  cout << s;
}

void F::println(string s) {
  cout << s << endl;
}

void F::printInit(Population* p) {
  if (p->getSize() % 1 == 0) {
    string s;
    s += "generated build ";
    s += to_string(p->getSize());
    println(s);
  }
}
