#ifndef RUNGA_H
#define RUNGA_H
#include "ppapi/cpp/instance.h"
#include "ppapi/cpp/module.h"
#include "ppapi/cpp/var.h"
#include "Population.h"

class RunGA : public pp::Instance {
public:
  explicit RunGA(PP_Instance instance);
  virtual ~RunGA();
  virtual void HandleMessage(const pp::Var& var_message);
  void initBuilds();
  void crossover();
  void run();
private:
  Population *p;
};

#endif // RUNGA_H
