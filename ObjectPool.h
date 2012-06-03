/* 
 * File:   ObjectPool.h
 * Author: Toby
 *
 * Created on May 13, 2012, 12:12 AM
 */

#ifndef OBJECTPOOL_H
#define	OBJECTPOOL_H

#include "EntityPool.h"
#include "EntityPool2.h"

class ObjectPool {
  static ObjectPool* s_instance;

  ObjectPool();
public:
  static Entity* get(Info name);
  static Entity* getAny(E::Name name);
  static void printPool();
  static int getPoolSize();
  static void retrieveAll();

  static ObjectPool* instance() {
    if (!s_instance)
      s_instance = new ObjectPool;
    return s_instance;
  }
private:
  EntityPool2 *entityPool;
};

#endif	/* OBJECTPOOL_H */

