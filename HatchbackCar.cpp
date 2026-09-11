#include "HatchbackCar.h"
HatchbackCar::HatchbackCar( short id, const std::string& model, float pricePerDay, CarStatus status) :
ACar{ id, model, pricePerDay, status } {}

CarType HatchbackCar::getType() const
{
	return CarType::HATCHBACK;
}
