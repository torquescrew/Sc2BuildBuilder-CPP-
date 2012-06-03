/* 
 * File:   BarrackWithTechlab.h
 * Author: Toby
 *
 * Created on May 9, 2012, 9:49 AM
 */

#ifndef BARRACKWITHTECHLAB_H
#define	BARRACKWITHTECHLAB_H
#include "Producer.h"

class BarracksWithTechlab : public Producer {
public:
  BarracksWithTechlab();
  virtual ~BarracksWithTechlab();
  void complete(GameState *gs);
private:

};

#endif	/* BARRACKWITHTECHLAB_H */

