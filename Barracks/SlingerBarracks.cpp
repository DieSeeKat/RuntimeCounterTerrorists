#include "SlingerBarracks.h"

Unit* SlingerBarracks::factoryMethod(){
    return new Slinger();
}

SlingerBarracks::SlingerBarracks()
{}