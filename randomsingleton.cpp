#include "randomsingleton.h"

RandomSingleton::RandomSingleton() {
  int seed = 3;
  randomGen = new Random(seed);
}

RandomSingleton::~RandomSingleton() {
  delete randomGen;
}

unsigned int RandomSingleton::nextInt(int min, int max) {
  return instance()->randomGen->uniform(min, max);
}

double RandomSingleton::nextDouble() {
  return instance()->randomGen->uniform();
}
