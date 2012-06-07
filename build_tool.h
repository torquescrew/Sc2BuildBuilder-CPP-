//
//  build_tool.h
//  
//
//  Created by Toby Suggate on 6/06/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _build_tool_h
#define _build_tool_h

#include "Population.h"
#include "ppapi/cpp/instance.h"
#include "ppapi/cpp/module.h"
#include "ppapi/cpp/var.h"


class build_toolInstance : public pp::Instance {
public:
  explicit build_toolInstance(PP_Instance instance);
  virtual ~build_toolInstance();
  virtual void HandleMessage(const pp::Var& var_message);
private:
  Population *p;
};

#endif
