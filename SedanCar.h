#pragma once
#include "ACar.h"
class SedanCar: public ACar
{
public:
	SedanCar(short id, const std::string& model, float pricePerDay, CarStatus status);
	CarType getType() const;
};

