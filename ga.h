#ifndef GA_H
#define GA_H
#include "NameList.h"
#include "Name.h"
#include <vector>
#include "Config.h"

using namespace std;

class GA
{
public:
  GA() {

  }
  virtual ~GA() {}

  void setConfig() {
    NameList* allowed = new NameList();
    vector<E::Name> names;

    names.push_back(E::SCV);
    names.push_back(E::SUPPLY_DEPOT);
    names.push_back(E::COMMAND_CENTER);
    names.push_back(E::BARRACKS);
    names.push_back(E::ORBITAL_COMMAND);
    names.push_back(E::REFINERY);
    names.push_back(E::MARINE);
    names.push_back(E::MARAUDER);
    names.push_back(E::BARRACKS_WITH_TECHLAB);
    names.push_back(E::BARRACKS_WITH_REACTOR);

    for (E::Name n : names) {
      allowed->add(Info(n));
    }

    Config::setAllowed(allowed);
    Config::setEntityPoolOption(true);
  }

};

#endif // GA_H
