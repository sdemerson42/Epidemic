#ifndef __SYS_BASE__
#define __SYS_BASE__

#include "EventHandler.h"

class SystemBase : public EventHandler
{
public:
	virtual ~SystemBase(){}
	virtual void update(){};
};

#endif