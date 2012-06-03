/* 
 * File:   EntityPool2.h
 * Author: Toby
 *
 * Created on May 16, 2012, 9:32 AM
 */

#ifndef ENTITYPOOL2_H
#define	ENTITYPOOL2_H
#include <vector>

#include "Stack.h"

using namespace std;

class EntityPool2 {
public:
  EntityPool2();
  virtual ~EntityPool2();
  Entity* getAny(E::Name name);
  Entity* getNew(Info name);
  void printPoolContents();
  void returnAllToPool();
  int getSize();
private:
  void init();
  vector<Stack*> pool;
};

#endif	/* ENTITYPOOL2_H */

