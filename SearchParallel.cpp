#include "SearchParallel.h"
#include "F.h"
#include "Config.h"
//#include <sstream>
#include <iostream>
#include "BuildList.h"

SearchParallel::SearchParallel() {}

SearchParallel::~SearchParallel() {}


void SearchParallel::run() {
  pthread_t threads[NUM_THREADS];
  bool createFail;

  for (unsigned t = 0; t < NUM_THREADS; t++) {
    createFail = pthread_create(&threads[t], NULL, initBuilds, (void *) &p[t]);
    if (createFail) {
      F::println("ERROR; failed to create initBuild thread");
      exit(-1);
    }
  }

  pthread_exit(NULL);
}

void* SearchParallel::initBuilds(void *p_t) {
  Population *threadPop = static_cast<Population*>(p_t);

  unsigned buildsNum = Config::getNumberOfBuilds() / NUM_THREADS;

  for (unsigned i = 0; i < buildsNum; i++) {
    BuildList *bl = new BuildList();
    bl->generateRandomList();
    threadPop->addBuild(bl);
    F::printInit(threadPop);
  }

  pthread_exit(NULL);
}
