#include "planetaryfortress.h"

PlanetaryFortress::PlanetaryFortress() {
  minerals = 150;
  gas = 150;
  buildTime = 50;
  builtBy.push_back(E::COMMAND_CENTER);
  required.push_back(E::ENGINEERING_BAY);
}
