#include "SuvCarCreator.h"
#include "SuvCar.h"
ACar* SuvCarCreator::createCar(short id, const std::string& model, float pricePerDay, CarStatus status) const
{
	return new SuvCar(id, model, pricePerDay, status);
}