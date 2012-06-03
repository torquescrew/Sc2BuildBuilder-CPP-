/* 
 * File:   Mules.h
 * Author: Toby
 *
 * Created on May 8, 2012, 6:33 PM
 */

#ifndef MULES_H
#define	MULES_H
#include <vector>

class Mules {
public:
  Mules();
  virtual ~Mules();
  void addMule(int time);
  double getMineralsFromMules(int time);
  void reset();
private:
  std::vector<int> mulesExpireTime;
  int muleDuration;
  int containsExpired(int time);
};

#endif	/* MULES_H */

