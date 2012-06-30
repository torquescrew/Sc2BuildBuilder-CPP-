#include "Sc2PlannerOut.h"
#include <deque>
#include <sstream>
#include <iostream>

using namespace std;

std::string sc2PlannerEvent::getEntityString(Event n) {
  switch (n.getName()) {
  case E::EMPTY:
    return "empty";
  case E::SCV:
    return "a";
  case E::COMMAND_CENTER:
    return "oA";
  case E::SUPPLY_DEPOT:
    return "oE";
  case E::BARRACKS:
    return "oF";
  case E::BARRACKS_WITH_TECHLAB:
    return "oP";
  case E::BARRACKS_WITH_REACTOR:
    return "oQ";
  case E::REFINERY:
    return "oD";
  case E::ORBITAL_COMMAND:
    return "oC";
  case E::PLANETARY_FORTRESS:
    return "oB";
  case E::MARINE:
    return "j";
  case E::MARAUDER:
    return "k";
  case E::ENGINEERING_BAY:
    return "oG";
  case E::MINE_GAS_3:
    return "c";
  default:
    return "Undefined";
  }
}

Sc2PlannerOut::Sc2PlannerOut(std::vector<Event> &events) {
  setEvents(events);
}

string Sc2PlannerOut::createLink() {
  stringstream ss;
  ss << "http://www.sc2planner.com/#T";
  for (unsigned i = 0; i < sc2Events.size(); i++) {
    ss << sc2Events[i].getStr();
  }
  return ss.str();
}

void Sc2PlannerOut::setEvents(vector<Event> &events) {
  deque<sc2PlannerEvent> temp;

  for (unsigned i = 0; i < events.size(); i++) {
    if (!temp.empty() && temp.front().getTime() <= events[i].getTime()) {
      sc2Events.push_back(temp.front());
      temp.pop_front();
    }
    sc2Events.push_back(sc2PlannerEvent(events[i]));
    if (events[i].getName() == E::REFINERY) {
      temp.push_back(sc2PlannerEvent(E::MINE_GAS_3, i + 30));
    }
  }
}
