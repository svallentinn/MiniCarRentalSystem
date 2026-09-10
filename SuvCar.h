#pragma once
#include "ACar.h"
class SuvCar : public ACar
{
	SuvCar(short id, const std::string& model, float pricePerDay, CarStatus status);
	CarType getType() const;
};

