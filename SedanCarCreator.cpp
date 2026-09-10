#include "SedanCarCreator.h"
#include "SedanCar.h"
ACar* SedanCarCreator::createCar(short id, const std::string& model, float pricePerDay, CarStatus status) const
{
	return new SedanCar(id, model, pricePerDay, status);
}