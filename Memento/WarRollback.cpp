#include "WarRollback.h"

WarRollback::WarRollback()
{
}

std::vector<Node *> WarRollback::getNodes()
{
	return nodes;
}

void WarRollback::setNodes(std::vector<Node *> nodes)
{
	this->nodes = nodes;
}

std::vector<Empire *> WarRollback::getEmpires()
{
	return empires;
}

void WarRollback::setEmpires(std::vector<Empire *> empires)
{
	this->empires = empires;
}

std::vector<Path *> WarRollback::getPaths()
{
	return paths;
}

void WarRollback::setPaths(std::vector<Path *> paths)
{
	this->paths = paths;
}