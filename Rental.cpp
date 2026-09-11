#include<iostream>
#include "Constants.h"
#include "StringToEnumConvert.h"

Rental::Rental(short rentalId, short carId, const std::string& customerName, short numberOfDays,
	RentalStatus status): _rentalId{rentalId}, _carId{carId}, _customerName{customerName}, 
	_numberOfDays{numberOfDays}, _status{status} {}

short Rental::getRentalId() const
{
	return _rentalId;
}

short Rental::getCarID() const
{
	return _carId;
}

const std::string& Rental::getCustomerName() const
{
	return _customerName;
}

short Rental::getNumberOfDays() const
{
	return _numberOfDays;
}

RentalStatus Rental::getStatus() const
{
	return _status;
}

void Rental::printRentalInfo() const
{
	StringToEnumConvert converter;
	std::cout << "Rental " << _rentalId << " " << Constants::PIPE_DELIMITER << " " << _carId << " " << Constants::PIPE_DELIMITER <<
		" " << _customerName << " " << Constants::PIPE_DELIMITER << " " << _numberOfDays << " " << Constants::DAY << " " <<
		Constants::PIPE_DELIMITER << " " << converter.rentalStatusToString(_status) << std::endl;
}
bool Rental::carIdExists(short carId, const std::vector<ACar*>& cars)
{
	for (short i = 0; i < cars.size(); i++)
	{
		if (cars[i] != nullptr && cars[i]->getId() == carId)
		{
			return true;
		}
	}
	return false;
}
bool Rental::isRentalValid(short rentalId, short carId, const std::string& customerName, short numberOfDays, RentalStatus status)
{
	if (rentalId <= 0)
	{
		return false;
	}
	if (carId <= 0)
	{
		return false;
	}
	if (customerName.empty())
	{
		return false;
	}
	if (numberOfDays <= 0)
	{
		return false;
	}
	if (!carIdExists(carID, cars))
	{
		return false;
	}
	return true;
}
Rental* Rental::create(short rentalId, short carId, const std::string& customerName, short numberOfDays, RentalStatus status)
{
	if (!isRentalValid(rentalId, carId, customerName, numberOfDays, status))
	{
		return nullptr;
	}
	return new Rental(rentalId, carId, customerName, numberOfDays, status);
}