/* 
 * File:   Events.h
 * Author: Toby
 *
 * Created on May 10, 2012, 2:57 PM
 */

#ifndef EVENTS_H
#define	EVENTS_H
#include "Name.h"

class Event {
public:
  Event(const Info &name, int time);
  virtual ~Event();
  E::Name getName();
  E::Name getArg();
  E::Name getArg2();
  int getTime();
private:
  E::Name name;
  E::Name arg;
  E::Name arg2;
  int time;
};

#endif	/* EVENTS_H */

