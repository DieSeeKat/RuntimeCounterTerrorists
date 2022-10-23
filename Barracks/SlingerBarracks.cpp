#include "SlingerBarracks.h"

Unit* SlingerBarracks::factoryMethod(int numRecruits){
    Slinger** slinger=new Slinger*[numRecruits];

	for(int i=0;i<numRecruits;i++){
		slinger[i]=new Slinger();
	}

	return *slinger;
}