// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// C headers
#include <cassert>
#include <cstdio>

// C++ headers
#include <sstream>
#include <string>

// PPAPI headers
#include "ppapi/cpp/completion_callback.h"
#include "ppapi/cpp/input_event.h"
#include "ppapi/cpp/instance.h"
#include "ppapi/cpp/module.h"
#include "ppapi/cpp/point.h"
#include "ppapi/cpp/var.h"
#include "ppapi/utility/completion_callback_factory.h"

#include "custom_events.h"
#include "thread_safe_ref_count.h"
//#include "OF.h"
//#include "Population.h"
#include "Search.h"

namespace event_queue {
const char* const kDidChangeView = "DidChangeView";
const char* const kHandleInputEvent = "DidHandleInputEvent";
const char* const kDidChangeFocus = "DidChangeFocus";
const char* const kHaveFocus = "HaveFocus";
const char* const kDontHaveFocus = "DontHaveFocus";
const char* const kCancelMessage = "CANCEL";
const char* const kStartMessage = "START";

class EventInstance: public pp::Instance {
public:
	explicit EventInstance(PP_Instance instance) :
			pp::Instance(instance), event_thread_(NULL), callback_factory_(this) {
		s = new Search();
	}

	// Not guaranteed to be called in Pepper, but a good idea to cancel the
	// queue and signal to workers to die if it is called.
	virtual ~EventInstance() {
		CancelQueueAndWaitForWorker();
	}

	bool isSetting(std::string s) {
		if (s[0] == 'S' && s[1] == 'E' && s[2] == 'T') {
			return true;
		}
		return false;
	}

	virtual void HandleMessage(const pp::Var& var_message) {
		std::string message = var_message.AsString();
		if (kCancelMessage == message) {
			std::string reply = "Stopped.";
			PostMessage(pp::Var(reply));
			continue_build = false;
			CancelQueueAndWaitForWorker();
		} else if (isSetting(message)) {
			s->parseNewSettings(message);
			continue_build = true;
			pthread_create(&event_thread_, NULL, ProcessEventOnWorkerThread, this);
		} else if (message == kStartMessage) {
			continue_build = true;
			pthread_create(&event_thread_, NULL, ProcessEventOnWorkerThread, this);
		}
	}

	// This method is called from the worker thread using CallOnMainThread.
	// It is not static, and allows PostMessage to be called.
	void* PostStringToBrowser(int32_t result, std::string data_to_send) {
		PostMessage(pp::Var(data_to_send));
		return 0;
	}

	static void myPostMessage(std::string s, EventInstance* event_instance) {
		pp::Module::Get()->core()->CallOnMainThread(0,
				event_instance->callback_factory().NewCallback(
						&EventInstance::PostStringToBrowser, s));
	}

	// |ProcessEventOnWorkerThread| is a static method that is run
	// by a thread.
	static void* ProcessEventOnWorkerThread(void* param) {
		EventInstance* event_instance = static_cast<EventInstance*>(param);

		Search *search = event_instance->getSearch();
		for (int i = 1; i <= search->numBuilds(); i++) {
			myPostMessage(search->createBuild(), event_instance);
		}
		search->normalise();
		for (int i = 0; i < search->numGenerations(); i++) {
			if (event_instance->getContinue()) {
				myPostMessage(search->completeGeneration(i+1), event_instance);
			}
			if ((i % 10) == 0) {
				myPostMessage(search->createTable(), event_instance);
			}
		}

		myPostMessage(search->createTable(), event_instance);

		pthread_exit(NULL);
		return 0;
	}

	// Return the callback factory.
	// Allows the static method (ProcessEventOnWorkerThread) to use
	// the |event_instance| pointer to get the factory.
	pp::CompletionCallbackFactory<EventInstance, ThreadSafeRefCount>&
	callback_factory() {
		return callback_factory_;
	}

	bool getContinue() {
		return continue_build;
	}

	Search* getSearch() {
		return s;
	}

private:
	void CancelQueueAndWaitForWorker() {
		if (event_thread_) {
			pthread_join(event_thread_, NULL);
		}
	}
	Search *s;
	pthread_t event_thread_;
	bool continue_build;
	pp::CompletionCallbackFactory<EventInstance, ThreadSafeRefCount> callback_factory_;
};

// The EventModule provides an implementation of pp::Module that creates
// EventInstance objects when invoked.  This is part of the glue code that makes
// our example accessible to ppapi.
class EventModule: public pp::Module {
public:
	EventModule() :
			pp::Module() {
	}
	virtual ~EventModule() {
	}

	virtual pp::Instance* CreateInstance(PP_Instance instance) {
		return new EventInstance(instance);
	}
};

} // namespace

// Implement the required pp::CreateModule function that creates our specific
// kind of Module (in this case, EventModule).  This is part of the glue code
// that makes our example accessible to ppapi.
namespace pp {
Module* CreateModule() {
	return new event_queue::EventModule();
}
}

