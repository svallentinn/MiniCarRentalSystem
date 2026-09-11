#pragma once
#include "ACar.h"
class SuvCar : public ACar
{
public:
	SuvCar(short id, const std::string& model, float pricePerDay, CarStatus status);
	CarType getType() const;
};

