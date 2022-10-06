#include "WarRollback.h"

Node* WarRollback::getNodes() {
	// TODO - implement WarRollback::getNodes
	throw "Not yet implemented";
}

void WarRollback::setNodes(Node* nodes) {
	// TODO - implement WarRollback::setNodes
	throw "Not yet implemented";
}

Empire* WarRollback::getEmpires() {
	return this->empires;
}

void WarRollback::setEmpires(Empire* empires) {
	this->empires = empires;
}

Path* WarRollback::getPaths() {
	return this->paths;
}

void WarRollback::setPaths(Path* paths) {
	this->paths = paths;
}

Alliance* WarRollback::getAlliances() {
	return this->alliances;
}

void WarRollback::setAlliances(Alliance* alliances) {
	this->alliances = alliances;
}
