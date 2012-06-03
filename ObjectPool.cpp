/* 
 * File:   ObjectPool.cpp
 * Author: Toby
 *
 * Created on May 13, 2012, 12:12 AM
 */

#include "ObjectPool.h"

ObjectPool::ObjectPool() {
  entityPool = new EntityPool2();
}

Entity* ObjectPool::get(Info name) {
  return instance()->entityPool->getNew(name);
}

Entity* ObjectPool::getAny(E::Name name) {
  return instance()->entityPool->getAny(name);
}

void ObjectPool::retrieveAll() {
  instance()->entityPool->returnAllToPool();
}

void ObjectPool::printPool() {
  instance()->entityPool->printPoolContents();
}

int ObjectPool::getPoolSize() {
  return instance()->entityPool->getSize();
}
