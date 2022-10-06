#ifndef WAR_H
#define WAR_H

#include "../Graph/Node.h"
#include "../Graph/Path.h"
#include "../Empire.h"

#include "WarRollback.h"

class War {

private:
	Node* nodes;
	Empire* empires;
	Path* paths;
	Alliance* alliances;

public:
	WarRollback createWarRollback();

	void setWarRollback(WarRollback war_rollback);
};

#endif
