/// @file build_tool.cc
/// This example demonstrates loading, running and scripting a very simple NaCl
/// module.  To load the NaCl module, the browser first looks for the
/// CreateModule() factory method (at the end of this file).  It calls
/// CreateModule() once to load the module code from your .nexe.  After the
/// .nexe code is loaded, CreateModule() is not called again.
///
/// Once the .nexe code is loaded, the browser than calls the CreateInstance()
/// method on the object returned by CreateModule().  It calls CreateInstance()
/// each time it encounters an <embed> tag that references your NaCl module.
///
/// The browser can talk to your NaCl module via the postMessage() Javascript
/// function.  When you call postMessage() on your NaCl module from the browser,
/// this becomes a call to the HandleMessage() method of your pp::Instance
/// subclass.  You can send messages back to the browser by calling the
/// PostMessage() method on your pp::Instance.  Note that these two methods
/// (postMessage() in Javascript and PostMessage() in C++) are asynchronous.
/// This means they return immediately - there is no waiting for the message
/// to be handled.  This has implications in your program design, particularly
/// when mutating property values that are exposed to both the browser and the
/// NaCl module.

#include <cstdio>
#include <string>
#include "build_tool.h"
#include "RunGA.h"
#include "Config.h"
#include "BuildList.h"
#include <sstream>

//namespace {
//  // The expected string sent by the browser.
//  const char* const kHelloString = "hello";
//  // The string sent back to the browser upon receipt of a message
//  // containing "hello".
//  const char* const kReplyString = "hello from NaCl";
//} // namespace


//build_toolInstance::build_toolInstance(PP_Instance instance) : pp::Instance(instance) {}

//build_toolInstance::~build_toolInstance() {}

//void build_toolInstance::HandleMessage(const pp::Var& var_message) {
//  if (!var_message.is_string())
//    return;
//  std::string message = var_message.AsString();
//  pp::Var var_reply;
    
    
////  if (message == kHelloString) {
//    var_reply = pp::Var(kReplyString);

//    PostMessage(var_reply);
//    PostMessage(var_reply);
//    //}
//}

/// The Module class.  The browser calls the CreateInstance() method to create
/// an instance of your NaCl module on the web page.  The browser creates a new
/// instance for each <embed> tag with type="application/x-nacl".
class build_toolModule : public pp::Module {
public:
  build_toolModule() : pp::Module() {}

  virtual ~build_toolModule() {}

  /// Create and return a build_toolInstance object.
  /// @param[in] instance The browser-side instance.
  /// @return the plugin-side instance.
  virtual pp::Instance* CreateInstance(PP_Instance instance) {
    return new RunGA(instance);
  }
};

namespace pp {
  /// Factory function called by the browser when the module is first loaded.
  /// The browser keeps a singleton of this module.  It calls the
  /// CreateInstance() method on the object you return to make instances.  There
  /// is one instance per <embed> tag on the page.  This is the main binding
  /// point for your NaCl module with the browser.
  Module* CreateModule() {
    return new build_toolModule();
  }
}  // namespace pp
