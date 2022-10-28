#include "FootmenBarracks.h"

Unit* FootmenBarracks::factoryMethod(){
    return new Footmen();
}

FootmenBarracks::FootmenBarracks(){};