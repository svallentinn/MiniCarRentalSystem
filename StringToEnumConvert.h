#pragma once
#include <string>
#include "CarStatus.h"
#include "CarType.h"
#include "RentalStatus.h"
class StringToEnumConvert
{
public:
	static std::string toUpperCase(const std::string& option);
	static CarStatus stringToCarStatus(const std::string& option);
	std::string carStatusToString(CarStatus status);
	static CarType stringToCarType(const std::string& option);
	std::string carTypeToString(CarType type);
	static RentalStatus stringToRentalStatus(const std::string& option);
	std::string rentalStatusToString(RentalStatus rentalStatus);
};

