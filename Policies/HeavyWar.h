#ifndef HEAVYWAR_H
#define HEAVYWAR_H

#include "../Graph/Node.h"

#include "RecruitmentPolicy.h"

class HeavyWar : RecruitmentPolicy {
public:
	void calculateRecruits(int town_population);
};

#endif
