#include "Search.h"
#include <sstream>
#include "GameLoop.h"

using namespace std;

Search::Search() {
  p = new Population();
}

Search::~Search() {
  delete p;
}

string Search::createBuild() {
  p->initOneList();
  stringstream ss;
  ss << "Created build: " << p->getSize();
  return ss.str();
}

void Search::normalise() {
  p->normalise();
}

string Search::completeGeneration(int c) {
  p->crossover();
  p->mutate();
  p->normalise();
  p->checkLength();
  stringstream ss;
  ss << "Completed generation " << c << ". Highest fitness: "
     << p->getHighest()->getFitness();
  return ss.str();
}

void Search::parseNewSettings(string s) {
	p->getOF()->updateSettings(s);
}

int Search::numBuilds() {
  return p->getOF()->getNumBuilds();
}

int Search::numEntities() {
  return p->getOF()->getNumEntities();
}

int Search::numGenerations() {
  return p->getOF()->getNumGenerations();
}

int Search::timeLimit() {
  return p->getOF()->getTimeLimit();
}

string Search::createTable() {
	GameLoop *gl = p->getOF()->newGameLoop();
	std::string table = gl->createHtmlTable(p->getHighest()->getList());
	delete gl;
	return table;
}


