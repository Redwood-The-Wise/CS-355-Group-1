#ifndef AREANODE_H
#define AREANODE_H
#include "Area.h"

struct areaNode
{
	Area info;
	areaNode* u;
	areaNode* d;
	areaNode* l;
	areaNode* r;
};
#endif