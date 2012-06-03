/* 
 * File:   OrbitalCommand.h
 * Author: Toby
 *
 * Created on May 8, 2012, 5:54 PM
 */

#ifndef ORBITALCOMMAND_H
#define	ORBITALCOMMAND_H
#include "Command.h"
#include "Energy.h"
#include "Mules.h"

class OrbitalCommand : public Command {
public:
  OrbitalCommand();
  virtual ~OrbitalCommand();
  void update(GameState *gs);
  void complete(GameState *gs);
  void reset();
  bool meetsRequired(GameState *gs);
protected:
  void updateMules(GameState *gs);
private:
  Energy *energy;
  Mules *mules;
};

#endif	/* ORBITALCOMMAND_H */

