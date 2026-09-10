#pragma once
#include "ACarCreator.h"
class SedanCarCreator: public ACarCreator
{
public:
	ACar* createCar(short id, const std::string& model, float pricePerDay, CarStatus status) const;
};

