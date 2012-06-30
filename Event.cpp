/* 
 * File:   Events.cpp
 * Author: Toby
 * 
 * Created on May 10, 2012, 2:57 PM
 */

#include "Event.h"

Event::Event(const Event &event) {
  name = event.getName();
  arg = event.getArg();
  arg2 = event.getArg2();
  time = event.getTime();
}

Event::Event(const Info &name, int time) {
  this->name = name.getName();
  this->arg = name.getArg();
  this->arg2 = name.getArg2();
  this->time = time;
}

Event::~Event() {
//  delete name;
}

E::Name Event::getName() const {
  return name;
}

E::Name Event::getArg() const {
  return arg;
}

E::Name Event::getArg2() const {
  return arg2;
}

unsigned Event::getTime() const {
  return time;
}
