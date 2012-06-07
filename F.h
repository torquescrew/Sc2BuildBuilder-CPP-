/*
 * F.h
 *
 *  Created on: May 6, 2012
 *      Author: Toby
 */

#ifndef F_H_
#define F_H_
#include "Entity.h"
#include "Name.h"
#include "Population.h"
//#include "build_tool.cpp"
//#include "Random.h"
//#include "ppapi/cpp/instance.h"
#include "build_tool.h"

using namespace std;

class F {
public:
  F() {}
  virtual ~F() {}
  static string toString(E::Name n);
  static unsigned long nextInt(unsigned long min, unsigned long max);
//  static uint32_t xor128();
  static double nextDouble();
  static void printNewUnit(E::Name name, GameState* gs);
  static string displaySupply(GameState* gs);
  static string displayResources(GameState* gs);
  static string displayTime(int time);
  static void print(string s);
  static void printGen(int gen, Population *p);

  static void println(string s);
  static void printInit(Population *p);

//  static void setBTInstance(build_toolInstance *i);
//private:
//  static build_toolInstance *instance;
};

#endif /* F_H_ */
