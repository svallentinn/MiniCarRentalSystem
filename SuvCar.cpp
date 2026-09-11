#include "SuvCar.h"
SuvCar::SuvCar(short id, const std::string& model, float pricePerDay, CarStatus status) :
	ACar{ id, model, pricePerDay, status } {}

CarType SuvCar::getType() const
{
	return CarType::SUV;
}