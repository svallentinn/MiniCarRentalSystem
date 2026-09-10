#include "SedanCar.h"
SedanCar::SedanCar(short id, const std::string& model, float pricePerDay, CarStatus status):
	ACar{id, model, pricePerDay, status} {}

CarType SedanCar::getType() const
{
	return CarType::SEDAN;
}