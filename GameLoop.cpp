//
//  GameLoop.cpp
//  BuildTool
//
//  Created by Toby Suggate on 7/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "GameLoop.h"
#include "F.h"
#include "OF.h"
#include <string>
#include <sstream>

GameLoop::GameLoop(OF *oF) : BuildEval(oF) {
	Info scv(E::SCV);
	Entity *e = oF->newEntity(scv);
	F::println(e->getNameStr());
	displayOption = false;
}

GameLoop::GameLoop(OF *oF, bool displayOption) :
		BuildEval(oF) {
	this->displayOption = displayOption;
//	Info scv(E::SCV);
  Entity *e = oF->newEntity(E::SCV);
	F::println(e->getNameStr());
}

std::string GameLoop::createHtmlTable(NameList *list) {
	stringstream ss;

	ss << "<table><thead><tr>";
	ss << "<th>Time</th><th>Minerals</th><th>Gas</th><th>Entity</th><th>Supply</th>";
	ss << "</tr></thead><tbody>";

	for (unsigned i = 0; i < list->size(); i++) {
		if (nextInstruction(list->get(i))) {
			ss << htmlTableRow(list->get(i));
		} else {
			break;
		}
	}

	ss << "</tbody></table>";

	return ss.str();
}

string GameLoop::htmlTableRow(Info info) {
	stringstream ss;

	ss << "<tr>";
	ss << "<td>" << F::displayTime(gs->getTime()) << "</td>";
	ss << "<td>" << (int)gs->getMinerals() << "</td>";
	ss << "<td>" << (int)gs->getGas() << "</td>";
	ss << "<td>" << F::toString(info.getName()) << "</td>";
	ss << "<td>" << F::displaySupply(gs) << "</td>";
	ss << "</tr>";

	return ss.str();
}

// use buildEval::tryAdd unstead?
bool GameLoop::nextEntity(Entity *e, int loops) {
	for (int i = 0; i < loops; i++) {
		if (gs->tryAddEntity(e)) {
			return true;
		} else {
			gs->incrementTime();
		}
	}
	return false;
}

bool GameLoop::tryAdd(Entity* e, int attemptsRemaining) {
	if (attemptsRemaining == 0) {
		return false;
	} else {
		if (gs->tryAddEntity(e)) {
			if (displayOption) {
				F::printNewUnit(e->getName(), gs);
			}
			return true;
		} else {
			gs->incrementTime();
			return tryAdd(e, attemptsRemaining - 1);
		}
	}
}
