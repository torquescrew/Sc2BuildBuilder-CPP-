/* 
 * File:   ProducerStack.h
 * Author: Toby
 *
 * Created on May 16, 2012, 2:25 PM
 */

#ifndef PRODUCERSTACK_H
#define	PRODUCERSTACK_H

#include "Stack.h"
#include "F.h"
#include <vector>

using namespace std;

template <class T>
class ProducerStack : public Stack {

public:
  ProducerStack(E::Name name) {
    this->name = name;
  }

  virtual ~ProducerStack() {
    for (unsigned int i = 0; i < free.size(); i++) {
      delete free[i];
    }
  }

  Entity* getEntity() {
    if (free.empty()) {
      Entity *e = new T();
      inUse.push_back(e);
      return e;
    }
    else {
      Entity *e = free.back();
      inUse.push_back(e);
      free.pop_back();
      return e;
    }
  }

  unsigned long getSize() {
    return (free.size() + inUse.size());
  }

  bool equals(E::Name name) {
    return this->name == name;
  }

  void retrieveEntities() {
    for (unsigned int i = 0; i < inUse.size(); i++) {
      inUse[i]->reset();
      free.push_back(inUse[i]);
    }
    inUse.clear();
  }
  
  void print() {
    cout << "(" << F::toString(name) << " " << free.size() << "/" << inUse.size() << ") ";
  }

private:
  E::Name name;
  vector<Entity*> free;
  vector<Entity*> inUse;
};

#endif	/* PRODUCERSTACK_H */

