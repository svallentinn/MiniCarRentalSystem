#pragma once
#include <string>
#include "RentalStatus.h"
class Rental
{
private:
	short _rentalId;
	short _carId;
	std::string _customerName;
	short _numberOfDays;
	RentalStatus _status;
public:
	Rental(short rentalId, short carId, const std::string& customerName, short numberOfDays, RentalStatus status);
	short getRentalId() const;
	short getCarID() const;
	const std::string& getCustomerName() const;
	short getNumberOfDays() const;
	RentalStatus getStatus() const;
	void printRentalInfo() const;
	static bool isRentalValid(short rentalId, short carId, const std::string& customerName, short numberOfDays, RentalStatus status);
};