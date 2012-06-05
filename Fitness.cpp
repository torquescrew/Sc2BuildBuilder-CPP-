/*
 * Fitness.cpp
 *
 *  Created on: Feb 23, 2012
 *      Author: Toby
 */

#include "Fitness.h"


double Fitness::getFitness(GameState *gs, vector<Event> &events) {
  double total = 0.0;

  total += slopeReward(events, E::SCV, 56.0);
  total += slopeReward(events, E::MARINE, 56.0);
  total += slopeReward(events, E::MARAUDER, 131.0);

  total -= punish(gs, events, total);

  return total;
}

double Fitness::slopeReward(vector<Event> &events, E::Name name, double w) {
  double total = 0.0;

  for (unsigned int i = 0; i < events.size(); i++) {
    if (events.at(i).getName() == name) {
      total += (w - (0.01 * events.at(i).getTime()));
    }
  }

  return total;
}

double Fitness::punish(GameState *gs, vector<Event> &events, double total) {
  double punishment = 0.0;

//  if (countOf(events, E::COMMAND_CENTER) > 1 || countOf(events, E::COMMAND_CENTER) < 1) {
//    punishment += (total * 0.2);
//  }

  if (gs->getAe()->getCommands().size() > 2 || gs->getAe()->getCommands().size() < 2) {
    punishment += (total * 0.2);
  }

  return punishment;
}

int Fitness::countOf(vector<Event> &events, E::Name name) {
  int count = 0;
  for (unsigned int i = 0; i < events.size(); i++) {
    if (events[i].getName() == name) {
      count++;
    }
  }
  return count;
}
