#include "OF.h"
#include "F.h"
#include <iostream>
#include <sstream>

OF::OF() {
	init();
	entityPool = new EntityPool2(this);

	seed = 3;
	random = new Random(seed);

  num_builds = 200;
  num_entities = 100;
	num_generations = 200;
	timeLimit = 600;
}

OF::~OF() {
	delete entityPool;
}

void OF::init() {
	allowed = new NameList();
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

	for (unsigned i = 0; i < names.size(); i++) {
		allowed->add(Info(names[i]));
	}
}

// could also auto delete last?
BuildEval *OF::newBuildEval() {
	return new BuildEval(this);
}

GameLoop *OF::newGameLoop() {
	return new GameLoop(this, true);
}

Entity *OF::newEntity(Info name) {
	return entityPool->getNew(name);
}

Entity *OF::newEntity(E::Name name) {
  return entityPool->getAny(name);
}

Entity *OF::getAny(E::Name name) {
  return entityPool->getAny(name);
}

void OF::retrieveAllEntities() {
	entityPool->returnAllToPool();
}

EntityPool2 *OF::getEntityPool() {
	return entityPool;
}

unsigned OF::getNumBuilds() {
	return num_builds;
}

unsigned OF::getNumEntities() {
	return num_entities;
}

unsigned OF::getNumGenerations() {
	return num_generations;
}

unsigned OF::getTimeLimit() {
	return timeLimit;
}

unsigned OF::nextInt(unsigned min, unsigned max) {
	return random->uniform(min, max);
}

double OF::nextDouble() {
	return random->uniform();
}

NameList *OF::getAllowed() {
	return allowed;
}

void OF::updateSettings(string s) {
	num_builds = parseSetting(s, "numOfBuilds");
//	num_entities = parseSetting(s, "numOfEntities");
	num_generations = parseSetting(s, "numOfGenerations");
}

unsigned OF::parseSetting(string s, string setting) {
	unsigned newValue;
	unsigned pos = 0;
	unsigned pos2 = 0;
	string sub;
  pos = (unsigned)s.find(setting);
	sub = s.substr(pos);
  pos = (unsigned)sub.find(":") + 1;
	sub = sub.substr(pos);
	pos2 = sub.find(" ");
	sub = sub.substr(0, pos2 - pos);
	stringstream ss;
	ss << sub;
	ss >> newValue;
	return newValue;
}

void OF::increaseNumEntities() {
  num_entities += 10;
}
