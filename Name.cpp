/* 
 * File:   Job.cpp
 * Author: Toby
 *
 * Created on May 9, 2012, 3:32 PM
 */


#include <iostream>

#include "Name.h"
#include "F.h"
#include "Entity.h"
//#include "ObjectPool.h"
#include <sstream>

//Info::Info() {
//  name = E::EMPTY;
//  arg = E::EMPTY;
//  arg2 = E::EMPTY;
//  std::cout << "Info()" << std::endl;
//}

Info::Info(const Info &name) {
  this->name = name.getName();
  this->arg = name.getArg();
  this->arg2 = name.getArg2();
}

Info::Info(E::Name name) {
  this->name = name;
  this->arg = E::EMPTY;
  this->arg2 = E::EMPTY;
}

Info::Info(E::Name name, E::Name arg) {
  this->name = name;
  this->arg = arg;
  this->arg2 = E::EMPTY;
}

Info::Info(E::Name name, E::Name arg, E::Name arg2) {
  this->name = name;
  this->arg = arg;
  this->arg2 = arg2;
}

Info::~Info() {
}

//Name Name::operator =(const Name &name) {
//  Name temp(name);
//  return temp;
//}

E::Name Info::getName() const {
  return name;
}

E::Name Info::getArg() const {
  return arg;
}

E::Name Info::getArg2() const {
  return arg2;
}

void Info::print() const {
  std::stringstream ss;

  ss << F::toString(name);
  if (arg != E::EMPTY) {
    ss << " " << F::toString(arg);
  }
  if (arg2 != E::EMPTY) {
    ss << " " << F::toString(arg2);
  }
  ss << ", ";
  F::print(ss.str());
}
