/* 
 * File:   Stack.h
 * Author: Toby
 *
 * Created on May 16, 2012, 11:05 AM
 */

#ifndef STACK_H
#define	STACK_H
#include "Entity.h"
#include "Name.h"
#include <iostream>

class Stack {
public:
  Stack() {}
  virtual ~Stack() {}
  virtual Entity* getEntity() = 0;
  virtual bool equals(E::Name name) = 0;
  virtual unsigned long getSize() = 0;
  virtual void retrieveEntities() = 0;
  virtual void print() = 0;
};

#endif	/* STACK_H */

