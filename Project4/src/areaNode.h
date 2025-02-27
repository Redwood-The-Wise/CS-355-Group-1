#ifndef H_AREA
#define H_AREA
  #include "Area.h"
#endif // H_AREA

struct areaNode
{
	Area info;
	areaNode* u;
	areaNode* d;
	areaNode* l;
	areaNode* r;
};