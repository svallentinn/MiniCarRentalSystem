#include "HatchbackCarCreator.h"
#include "HatchbackCar.h"
ACar* HatchbackCarCreator::createCar(short id, const std::string& model, float pricePerDay, CarStatus status) const
{	
	return new HatchbackCar(id, model, pricePerDay, status);
}