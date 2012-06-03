/* 
 * File:   Mules.cpp
 * Author: Toby
 * 
 * Created on May 8, 2012, 6:33 PM
 */

#include <iostream>

#include "Mules.h"

Mules::Mules() {
  muleDuration = 90;
}

Mules::~Mules() {
}

void Mules::addMule(int time) {
  mulesExpireTime.push_back(time + muleDuration);
}

double Mules::getMineralsFromMules(int time) {
  int index = containsExpired(time);
  while (index != -1) {
    mulesExpireTime.erase(mulesExpireTime.begin() + index);
    index = containsExpired(time);
  }
  return 2.8333 * mulesExpireTime.size();
}

int Mules::containsExpired(int time) {
  for (unsigned long i = 0; i < mulesExpireTime.size(); i++) {
    if (mulesExpireTime[i] <= time) {
      return (int)i;
    }
  }
  return -1;
}

void Mules::reset() {
  mulesExpireTime.clear();
}