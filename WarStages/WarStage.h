#ifndef WARSTAGE_H
#define WARSTAGE_H

#include <map>
class Empire;

class WarStage
{

  protected:
  WarStage();
  /// The Empire owner of the WarStage
  Empire *empire;

  public:
  virtual void takeTurn() = 0;

  WarStage(Empire *empire);
  ~WarStage();
  /**
   * @brief Clone method for the WarStage
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned WarStage
   */
  virtual WarStage* clone(std::map<void*,void*> &objmap) = 0;
};

#endif
