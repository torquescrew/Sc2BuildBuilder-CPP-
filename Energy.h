/* 
 * File:   Energy.h
 * Author: Toby
 *
 * Created on May 8, 2012, 6:03 PM
 */

#ifndef ENERGY_H
#define	ENERGY_H

class Energy {
public:
  Energy();
  Energy(double startEnergy, double spellCost, double maxEnergy);
  virtual ~Energy();
  bool trySpend();
  void update();
  void reset();
private:
  double energy;
  double spellCost;
  double maxEnergy;
};

#endif	/* ENERGY_H */

