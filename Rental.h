#pragma once
#include <string>
#include <vector>
#include "RentalStatus.h"
#include "ACar.h"
class Rental
{
private:
	short _rentalId;
	short _carId;
	std::string _customerName;
	short _numberOfDays;
	RentalStatus _status;
	Rental(short rentalId, short carId, const std::string& customerName, short numberOfDays, RentalStatus status);
public:	
	short getRentalId() const;
	short getCarID() const;
	const std::string& getCustomerName() const;
	short getNumberOfDays() const;
	RentalStatus getStatus() const;
	void printRentalInfo() const;
	static bool carIdExists(short carId, const std::vector<ACar*>& cars);
	static bool isRentalValid(short rentalId, short carId, const std::string& customerName, short numberOfDays, RentalStatus status);
	static Rental* create(short rentalId, short carId, const std::string& customerName, short numberOfDays, RentalStatus status);
};