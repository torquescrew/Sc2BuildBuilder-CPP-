#include "RunGA.h"
//#include "Population.h"
#include "Config.h"
#include <sstream>


namespace {
// The expected string sent by the browser.
const char* const kHelloString = "hello";
// The string sent back to the browser upon receipt of a message
// containing "hello".
const char* const kReplyString = "hello from NaCl";
} // namespace

RunGA::RunGA(PP_Instance instance) : pp::Instance(instance) {
  p = new Population();
}

RunGA::~RunGA() {
  delete p;
}

void RunGA::initBuilds() {
  for (unsigned i = 0; i < Config::getNumberOfBuilds(); i++) {
    pp::Var var_reply;
    p->initOneList();
    stringstream ss;
    ss << "generated build " << p->getSize();
    var_reply = pp::Var(ss.str());
    PostMessage(var_reply);
  }
  p->normalise();
}

void RunGA::crossover() {
  for (unsigned i = 0; i < Config::getNumOfGenerations(); i++) {
    p->crossover();
    p->mutate();
    p->normalise();

    stringstream ss;
    ss << "Completed Gen " << i+1 << ". ";
    ss << "Highest: " << p->getHighest()->getFitness();

    PostMessage(pp::Var(ss.str()));
  }
}

void RunGA::HandleMessage(const pp::Var& var_message) {
  if (!var_message.is_string())
    return;
//  std::string message = var_message.AsString();
  pp::Var var_reply;

//  for (unsigned i = 0; i < Config::getNumberOfBuilds(); i++) {
//    p->initOneList();
//    stringstream ss;
//    ss << "generated build " << p->getSize();
//    var_reply = pp::Var(ss.str());
//    PostMessage(var_reply);
//  }
  var_reply = pp::Var(kReplyString);
  PostMessage(var_reply);

  initBuilds();
  //  p.run();

  crossover();
  //  if (message == kHelloString) {

//  var_reply = pp::Var(ss.str());
//  PostMessage(var_reply);
  //}
}

void RunGA::run() {
  Population p;
  p.run();
  //  instance->p
}
