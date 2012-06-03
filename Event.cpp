/* 
 * File:   Events.cpp
 * Author: Toby
 * 
 * Created on May 10, 2012, 2:57 PM
 */

#include "Event.h"

Event::Event(const Info &name, int time) {
  this->name = name.getName();
  this->arg = name.getArg();
  this->arg2 = name.getArg2();
  this->time = time;
}

Event::~Event() {
//  delete name;
}

E::Name Event::getName() {
  return name;
}

E::Name Event::getArg() {
  return arg;
}

E::Name Event::getArg2() {
  return arg2;
}

int Event::getTime() {
  return time;
}
