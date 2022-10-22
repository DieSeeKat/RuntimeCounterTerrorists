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
  virtual WarStage* clone(std::map<void*,void*> &objmap) = 0;
};

#endif
