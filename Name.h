/* 
 * File:   Job.h
 * Author: Toby
 *
 * Created on May 9, 2012, 3:32 PM
 */

#ifndef NAME_H
#define	NAME_H
#include "E.h"

//class Entity;

class Info {
public:
//  Info();
  Info(const Info &name);
  Info(E::Name name);
  Info(E::Name name, E::Name arg);
  Info(E::Name name, E::Name arg, E::Name arg2);
  virtual ~Info();
//  Name operator=(const Name &name);
  E::Name getName() const;
  E::Name getArg() const;
  E::Name getArg2() const;
  void print() const;
private:
  E::Name name;
  E::Name arg;
  E::Name arg2;
};

#endif	/* NAME_H */

