#ifndef ARMYRATIO_H
#define ARMYRATIO_H

class ArmyRatio
{
  public:
  /// The ratio of cavalry in the Army
  float cavalry_ratio;
  /// The ratio of archers in the Army
  float archer_ratio;
  /// The ratio of footmen in the Army
  float footmen_ratio;
  /// The ratio of slingers in the Army
  float slinger_ratio;

  ArmyRatio(float cavalry_ratio,
            float archer_ratio,
            float footmen_ratio,
            float slinger_ratio);
};


#endif
