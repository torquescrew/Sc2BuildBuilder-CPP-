#ifndef SC2PLANNEROUT_H
#define SC2PLANNEROUT_H
#include <string>
#include <vector>
#include "Event.h"
#include "Name.h"

class sc2PlannerEvent : public Event {
public:
  std::string getEntityString(Event n);

  sc2PlannerEvent(const Event &event) : Event(event) {
    entityString = getEntityString(event);
  }

  sc2PlannerEvent(E::Name name, int time) : Event(Info(name), time) {
    entityString = getEntityString(*this);
  }

  std::string getStr() {
    return entityString;
  }

private:
  std::string entityString;
};

class Sc2PlannerOut {
public:
  Sc2PlannerOut(std::vector<Event> &events);
  std::string createLink();

private:
  void setEvents(std::vector<Event> &events);

  std::vector<sc2PlannerEvent> sc2Events;
};

#endif // SC2PLANNEROUT_H
