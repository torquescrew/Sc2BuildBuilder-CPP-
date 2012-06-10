#include "SearchParallel.h"
#include "F.h"
#include "Config.h"
//#include <sstream>
#include <iostream>
#include "BuildList.h"

#define NUM_THREADS 1

SearchParallel::SearchParallel() {
  for (unsigned i = 0; i < NUM_THREADS; i++) {
    p.push_back(new Population());
  }
}

SearchParallel::~SearchParallel() {}


void SearchParallel::run() {
  pthread_t threads[NUM_THREADS];
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
//  bool createFail;

  for (unsigned t = 0; t < NUM_THREADS; t++) {
    pthread_create(&threads[t], &attr, initBuilds, (void *) p.at(t));
//    if (createFail) {
//      F::println("ERROR; failed to create initBuild thread");
//      exit(-1);
//    }
  }

  for (unsigned t = 0; t < NUM_THREADS; t++) {
    pthread_join(threads[t], NULL);
  }

  pthread_exit(NULL);
}

void* SearchParallel::initBuilds(void *p_t) {
  Population *threadPop = static_cast<Population*>(p_t);


  unsigned buildsNum = Config::getNumberOfBuilds() / NUM_THREADS;
  for (unsigned i = 0; i < buildsNum; i++) {
    BuildList *bl = new BuildList(threadPop->getObjectFact());
    bl->generateRandomList();
    threadPop->addBuild(bl);
    F::printInit(threadPop);
  }
  threadPop->getObjectFact()->getEntityPool()->printPoolContents();
  F::println("");

//  pthread_exit(NULL);
  return 0;
}
