/*
 * CommandCenter.h
 *
 *  Created on: May 6, 2012
 *      Author: Toby
 */

#ifndef COMMANDCENTER_H_
#define COMMANDCENTER_H_
//#include "Entity.h"
#include "Command.h"
#include "GameState.h"

class CommandCenter : public Command {
public:
  CommandCenter();
  virtual ~CommandCenter();
  void update(GameState *gs);
  void complete(GameState *gs);
};

#endif /* COMMANDCENTER_H_ */
