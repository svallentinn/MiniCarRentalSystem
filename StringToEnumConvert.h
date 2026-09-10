#pragma once
#include <string>
#include "CarStatus.h"
#include "CarType.h"
#include "RentalStatus.h"
class StringToEnumConvert
{
public:
	CarStatus stringToCarStatus(const std::string& option);
	std::string carStatusToString(CarStatus status);
	CarType stringToCarType(const std::string& option);
	std::string carTypeToString(CarType type);
	RentalStatus stringToRentalStatus(const std::string& option);
	std::string rentalStatusToString(RentalStatus rentalStatus);
};

