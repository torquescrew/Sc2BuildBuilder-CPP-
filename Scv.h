/*
 * Scv.h
 *
 *  Created on: May 5, 2012
 *      Author: Toby
 */

#ifndef SCV_H_
#define SCV_H_
#include "Producer.h"

class Scv : public Producer {
public:
  Scv();
  virtual ~Scv();
  void complete(GameState *gs);
//  bool meetsCosts(GameState *gs);
};

#endif /* SCV_H_ */
