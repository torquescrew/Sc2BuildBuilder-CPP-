/* 
 * File:   BarracksWithReactor.h
 * Author: Toby
 *
 * Created on May 9, 2012, 11:16 AM
 */

#ifndef BARRACKSWITHREACTOR_H
#define	BARRACKSWITHREACTOR_H
#include "Reactor.h"

class BarracksWithReactor : public Reactor {
public:
  BarracksWithReactor();
  virtual ~BarracksWithReactor();
  void complete(GameState *gs);
private:

};

#endif	/* BARRACKSWITHREACTOR_H */

