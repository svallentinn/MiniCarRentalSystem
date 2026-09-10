#pragma once
#include "ACar.h"
class HatchbackCar: public ACar
{
public:
	HatchbackCar(short id, const std::string& model, float pricePerDay, CarStatus status);
	CarType getType() const;
};

