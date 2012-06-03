/* 
 * File:   Barracks.cpp
 * Author: Toby
 * 
 * Created on May 8, 2012, 4:22 AM
 */

#include "Barracks.h"

Barracks::Barracks() {
  minerals = 150;
  buildTime = 65;
  name = E::BARRACKS;
  builtBy.push_back(E::SCV);
  required.push_back(E::SUPPLY_DEPOT);
}

Barracks::~Barracks() {
}

//void Barracks::update(GameState* gs) {
//	if (checkForBuilt(gs->getTime())) {
//		getBuiltEntity();// no point returning marines
////    acknowledgeBuilt();
//	}
//}
