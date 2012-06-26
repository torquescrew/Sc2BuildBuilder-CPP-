#ifndef SEARCH_H
#define SEARCH_H
#include "Population.h"
#include <string>

class Search {
public:
  Search();
  ~Search();

  std::string createBuild();
  void normalise();
  std::string completeGeneration(int c);

  void parseNewSettings(std::string s);

  int numBuilds();
  int numEntities();
  int numGenerations();
  int timeLimit();

  std::string createTable();

private:
  Population *p;
};

#endif // SEARCH_H
