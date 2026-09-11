#include "ACarCreator.h"
ACarCreator::~ACarCreator() {}
ACar* ACarCreator::getCar(short id, const std::string& model, float pricePerDay, CarStatus status)
{
	if (!ACar::isValid(id, model, pricePerDay))
	{
		return nullptr;
	}
	return createCar(id, model, pricePerDay, status);
}