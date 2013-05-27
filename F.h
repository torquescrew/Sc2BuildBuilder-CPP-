/*
 * F.h
 *
 *  Created on: May 6, 2012
 *      Author: Toby
 */

#ifndef F_H_
#define F_H_
//#include "Entity.h"
//#include "Name.h"
#include "E.h"
//#include "Population.h"
#include <string>
#include <sstream>
#include <iostream>

class GameState;
class Population;

namespace P {

//  template<typename T>
//  void println(T value)
//  {
//    std::cout << value << std::endl;
//  }
//
//  template<typename T, typename... Args>
//  void println(T value, Args... args)
//  {
//    std::cout << value;
//    if (sizeof...(Args))
//      println(args...);
//  }
//
//  void println()
//  {
//    std::cout << std::endl;
//  }

}

class F {
public:
  F() {}
  virtual ~F() {}
  static std::string toString(E::Name n);
//  static unsigned long nextInt(unsigned long min, unsigned long max);
//  static double nextDouble();
  static void printNewUnit(E::Name name, GameState* gs);
  static std::string displaySupply(GameState* gs);
  static std::string displayResources(GameState* gs);
  static std::string displayTime(int time);
  static void print(std::string s);
  static void printGen(int gen, Population *p);

//  static void println() {
//    cout << endl;
//  }
//  template<class T>
//  static void println(T s) {
//    cout << s << endl;
//  }
//  template<class T, class T2>
//  static void println(T s, T2 s2) {
//    cout << s << s2 << endl;
//  }
//  template<class T, class T2, class T3>
//  static void println(T s, T2 s2, T3 s3) {
//    cout << s << s2 << s3 << endl;
//  }
//  template<class T, class T2, class T3, class T4>
//  static void println(T s, T2 s2, T3 s3, T4 s4) {
//    cout << s << s2 << s3 << s4 << endl;
//  }
  
  template<typename T>
  static void println(T value)
  {
    std::cout << value << std::endl;
  }
  
  template<typename T, typename... Args>
  static void println(T value, Args... args)
  {
    std::cout << value;
    if (sizeof...(Args))
      println(args...);
  }
  
  static void println()
  {
    std::cout << std::endl;
  }

//  static string makeStr(S str);
//  static void println();
//  static void println(S str);

  static void printInit(Population *p);
};

#endif /* F_H_ */
