#include "FootmenBarracks.h"

Unit* FootmenBarracks::factoryMethod(int numRecruits){
    Footmen** footmen=new Footmen*[numRecruits];

	for(int i=0;i<numRecruits;i++){
		footmen[i]=new Footmen();
	}

	return *footmen;
}