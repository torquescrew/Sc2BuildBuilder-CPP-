/* 
 * File:   EntityPool.h
 * Author: Toby
 *
 * Created on May 12, 2012, 11:00 PM
 */

#ifndef ENTITYPOOL_H
#define	ENTITYPOOL_H
#include "Entity.h"
#include "Name.h"

using namespace std;

class EntityPool {
public:
  EntityPool();
  virtual ~EntityPool();
  Entity* getAny(E::Name name);
  Entity* getNew(Info info);
  void printPoolContents();
  void returnAllToPool();
  void returnLast();
  int getSize();
private:
  Entity* sendToInUseAndReturn(int index);
  Entity* create(E::Name name); // TODO duplicate of F::create
  int contains(E::Name name);
  bool isProducer(Info info);
  vector<Entity*> pool;
  vector<Entity*> inUse;
  vector<E::Name> producers;
};

#endif	/* ENTITYPOOL_H */

