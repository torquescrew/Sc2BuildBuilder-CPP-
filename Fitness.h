/*
 * Fitness.h
 *
 *  Created on: Feb 23, 2012
 *      Author: Toby
 */

#ifndef FITNESS_H_
#define FITNESS_H_

#include "GameState.h"
#include "E.h"
#include "Event.h"


class Fitness {
public:
  Fitness() {}
  virtual ~Fitness() {}
	static double getFitness(GameState *gs, vector<Event> &events);
private:
  static double slopeReward(vector<Event> &events, E::Name name, double w);
  static double punish(GameState *gs, vector<Event> &events, double total);
  static int countOf(vector<Event> &events, E::Name name);
};

#endif /* FITNESS_H_ */
