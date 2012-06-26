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
#include <string>
#include <sstream>

using namespace std;

//class S {
//public:
//  template<class T>
//  S(T w) {
//    stringstream ss;
//    ss << w;
//    word = ss.str();
//  }

//  S operator + (S param) {
//    string str = word + param.get();
//    return S(str);
//  }

////  template<class F>
////  S operator + (F param) {
////    stringstream ss;
////    ss << param;
////    return S(ss.str());
////  }

//  string get() {
//    return word;
//  }
//private:
//  string word;
//};

//template<class F>
//S operator + (F p, S p2) {
//  stringstream ss;
//  ss << p << p2.get();
//  return S(ss.str());
//}

class F {
public:
  F() {}
  virtual ~F() {}
  static string toString(E::Name n);
//  static unsigned long nextInt(unsigned long min, unsigned long max);
//  static double nextDouble();
  static void printNewUnit(E::Name name, GameState* gs);
  static string displaySupply(GameState* gs);
  static string displayResources(GameState* gs);
  static string displayTime(int time);
  static void print(string s);
  static void printGen(int gen, Population *p);

  static void println() {
    cout << endl;
  }
  template<class T>
  static void println(T s) {
    cout << s << endl;
  }
  template<class T, class T2>
  static void println(T s, T2 s2) {
    cout << s << s2 << endl;
  }
  template<class T, class T2, class T3>
  static void println(T s, T2 s2, T3 s3) {
    cout << s << s2 << s3 << endl;
  }
  template<class T, class T2, class T3, class T4>
  static void println(T s, T2 s2, T3 s3, T4 s4) {
    cout << s << s2 << s3 << s4 << endl;
  }
//  static string makeStr(S str);
//  static void println();
//  static void println(S str);

  static void printInit(Population *p);
};

#endif /* F_H_ */
