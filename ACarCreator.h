#pragma once
#include <string>
#include "ACar.h"
class ACarCreator
{
public:
	ACar* getCar(short id, const std::string& model, float pricePerDay, CarStatus status);
	virtual ~ACarCreator() = 0;
protected:
	virtual ACar* createCar(short id, const std::string& model, float pricePerDay, CarStatus status) const = 0;
};

