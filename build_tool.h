//
//  build_tool.h
//  
//
//  Created by Toby Suggate on 6/06/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _build_tool_h
#define _build_tool_h

class build_toolInstance : public pp::Instance {
public:
  explicit build_toolInstance(PP_Instance instance) : pp::Instance(instance);
  virtual ~build_toolInstance();
  virtual void HandleMessage(const pp::Var& var_message);
};

#endif
