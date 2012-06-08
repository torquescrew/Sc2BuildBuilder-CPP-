#ifndef SEARCHPARALLEL_H
#define SEARCHPARALLEL_H
#include "Population.h"
#include <pthread.h>

#define NUM_THREADS 2

class SearchParallel {
public:
  SearchParallel();
  virtual ~SearchParallel();

  void run();
  static void *initBuilds(void *p_t);
private:
  Population mainPop;
  Population p[NUM_THREADS];
};

#endif // SEARCHPARALLEL_H
