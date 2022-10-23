#include "CavalryBarracks.h"

Unit* CavalryBarracks::factoryMethod(int numRecruits) {
	// TODO - implement CavalryBarracks::factoryMethod
	Cavalry** cavalry=new Cavalry*[numRecruits];

	for(int i=0;i<numRecruits;i++){
		cavalry[i]=new Cavalry();
	}

	return *cavalry;
}
