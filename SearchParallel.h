#ifndef SEARCHPARALLEL_H
#define SEARCHPARALLEL_H
#include "Population.h"
#include <pthread.h>
#include <vector>



class SearchParallel {
public:
  SearchParallel();
  virtual ~SearchParallel();

  void run();
  static void *initBuilds(void *p_t);
private:
  Population mainPop;
//  Population *p[NUM_THREADS];

  std::vector<Population*> p;
};

#endif // SEARCHPARALLEL_H