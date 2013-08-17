//#include "SearchParallel.h"
//#include "F.h"
//#include "Config.h"
////#include <sstream>
//#include <iostream>
//#include "BuildList.h"
//
//
//pthread_attr_t attr;
//
//SearchParallel::SearchParallel() {
//  numThreads = 1;
//
//  for (unsigned i = 0; i < numThreads; i++) {
//    threads.push_back(new pthread_t());
//  }
//}
//
//SearchParallel::~SearchParallel() {
//  //TODO delete some stuff
//}
//
//
//void SearchParallel::run() {
//
////  pthread_attr_init(&attr);
////  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
//
//  for (unsigned t = 0; t < numThreads; t++) {
//    pthread_create(threads[t], NULL, initBuilds, this);
//  }
//
//  for (unsigned t = 0; t < numThreads; t++) {
//    pthread_join(*threads[t], NULL);
//  }
//
////  pthread_exit(NULL);
//}
//
//void *SearchParallel::initBuilds(void *p_t) {
//  std::cout << "created thread 0" << std::endl;
//
////  size_t mystacksize;
////  pthread_attr_getstacksize (&attr, &mystacksize);
////  std::cout << "stack size " << mystacksize << std::endl;
//
////  Population *threadPop = static_cast<Population*>(p_t);
////  threadPop->initLists();
//
////  threadPop->getOF()->getEntityPool()->printPoolContents();
//
//  Population *p = new Population();
//  p->run();
//
//
////  F::println("");
//
//  pthread_exit(NULL);
////  return 0;
//}
