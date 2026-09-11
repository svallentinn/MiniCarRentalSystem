#pragma once
#include "CarType.h"
#include "ACarCreator.h"
class CarCreatorDispatcher
{
public:
	static ACarCreator* getCreator(CarType type);
};

