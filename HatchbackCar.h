#pragma once
#include "ACar.h"
class HatchbackCar: public ACar
{
	HatchbackCar(short id, const std::string& model, float pricePerDay, CarStatus status);
	CarType getType() const;
};

