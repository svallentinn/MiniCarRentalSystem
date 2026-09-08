#pragma once
#include <string>
#include "CarStatus.h"
#include "CarType.h"
#include "RentalStatus.h"
class StringToEnumConvert
{
public:
	CarStatus stringToCarStatus(const std::string& option);
	std::string CarStatusToString(CarStatus status);
	CarType stringToCarType(const std::string& option);
	std::string CarTypetoString(CarType type);
	RentalStatus stringToRentalStatus(const std::string& option);
	std::string rentalStatusToString(RentalStatus rentalStatus);
};

