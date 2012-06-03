/* 
 * File:   EntityStack.h
 * Author: Toby
 *
 * Created on May 16, 2012, 2:32 PM
 */

#ifndef ENTITYSTACK_H
#define	ENTITYSTACK_H

#include "Stack.h"

using namespace std;

template <class T>
class EntityStack : public Stack {
public:
  EntityStack(E::Name name) {
    this->name = name;
    e = new T();
  }

  virtual ~EntityStack() {
    delete e;
  }
  
  Entity* getEntity() {
    return e;
  }
  
  unsigned long getSize() {
    return 1;
  }
  
  bool equals(E::Name name) {
    return this->name == name;
  }
  
  void retrieveEntities() {
    
  }
  
  void print() {
    F::print("(" + e->getNameStr() + ") ");
//    cout << "(" << e->getNameStr() << ") ";
  }
  
private:
  E::Name name;
  Entity *e;
};

#endif	/* ENTITYSTACK_H */

