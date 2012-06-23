/* 
 * File:   NameList.cpp
 * Author: Toby
 * 
 * Created on May 9, 2012, 3:50 PM
 */

#include <iostream>
#include <string>
#include "NameList.h"
#include "F.h"

NameList::NameList() {
}

NameList::~NameList() {
}

void NameList::add(const Info &name) {
  names.push_back(name);
}

const Info NameList::get(unsigned long i) const {
  return names[i];
}

//Info NameList::operator [](unsigned long i) const {
//  return names[i];
//}

void NameList::set(unsigned long i, const Info &name) {
  names[i] = name;
}

std::vector<Info> NameList::get() {
  return names;
}

void NameList::removeLast() {
  if (names.size() > 0) {
    names.pop_back();
  }
}

void NameList::clear() {
  names.clear();
}

void NameList::printNames() {
  for (unsigned int i = 0; i < names.size(); i++) {
    names[i].print();
  }
//  std::cout << std::endl;
  F::println("");
}

unsigned long NameList::size() const {
  return names.size();
}
