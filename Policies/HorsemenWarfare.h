#ifndef HORSEMENWARFARE_H
#define HORSEMENWARFARE_H
#include "../ArmyRatio.h"
#include "../Graph/Node.h"
#include "WarStylePolicy.h"
#include <map>

class HorsemenWarfare : public WarStylePolicy
{
  public:
  /**
   * @brief creates the ArmyRatio depending on the type of warfare
   * @return ArmyRatio class
   */
  ArmyRatio createArmyRatio() override;
  /// Constructor
  HorsemenWarfare();
  /// Destructor
  ~HorsemenWarfare();
  /**
   * @brief Clone method for the HorsemenWarfare Policy
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned HorsemenWarfare Policy
   */
  WarStylePolicy* clone(std::map<void*,void*> &objmap);

  virtual string getWarStyleName();
};


#endif//HORSEMENWARFARE_H
