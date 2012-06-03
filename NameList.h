/* 
 * File:   NameList.h
 * Author: Toby
 *
 * Created on May 9, 2012, 3:50 PM
 */

#ifndef NAMELIST_H

#define	NAMELIST_H

#include <vector>
#include "Name.h"

class NameList {
public:
  NameList();
  virtual ~NameList();
  std::vector<Info> get();
  const Info get(unsigned long i) const;
//  Info operator[] (unsigned long i) const;
  void set(unsigned long i, const Info &name);
  void printNames();
  void add(const Info &name);
  void removeLast();
  void clear();
  unsigned long size() const;
private:
  std::vector<Info> names;
};

#endif	/* NAMELIST_H */

