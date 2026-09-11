#include "StringToEnumConvert.h"

std::string StringToEnumConvert::toUpperCase(const std::string& option)
{
	std::string result = option;
	for (short i = 0; i < result.size(); i++)
	{
		if (result[i] >= 'a' && result[i] <= 'z')
		{
			result[i] = result[i] - 32;
		}
	}
	return result;
}

CarStatus StringToEnumConvert::stringToCarStatus(const std::string& option)
{
	std::string toUpperCaseOption = StringToEnumConvert::toUpperCase(option);
	if (toUpperCaseOption == "AVAILABLE")
	{
		return CarStatus::AVAILABLE;
	}
	else if (toUpperCaseOption == "RENTED")
	{
		return CarStatus::RENTED;
	}
	else if (toUpperCaseOption == "SERVICE")
	{
		return CarStatus::SERVICE;
	}
}

std::string StringToEnumConvert::carStatusToString(CarStatus status)
{
	if (status==CarStatus::AVAILABLE)
	{
		return "AVAILABLE";
	}
	else if (status == CarStatus::RENTED)
	{
		return "RENTED";
	}
	else if (status==CarStatus::SERVICE)
	{
		return "SERVICE";
	}
}

CarType StringToEnumConvert::stringToCarType(const std::string& option)
{
	std::string toUpperCaseOption = StringToEnumConvert::toUpperCase(option);
	if (toUpperCaseOption == "HATCHBACK")
	{
		return CarType::HATCHBACK;
	}
	else if (toUpperCaseOption == "SEDAN")
	{
		return CarType::SEDAN;
	}
	else if (toUpperCaseOption == "SUV")
	{
		return CarType::SUV;
	}
}

std::string StringToEnumConvert::carTypeToString(CarType type)
{
	if (type== CarType::HATCHBACK)
	{
		return "HATCHBACK";
	}
	else if (type== CarType::SEDAN )
	{
		return "SEDAN";
	}
	else if (type== CarType::SUV )
	{
		return "SUV";
	}
}

RentalStatus StringToEnumConvert::stringToRentalStatus(const std::string& option)
{
	std::string toUpperCaseOption = StringToEnumConvert::toUpperCase(option);
	if (toUpperCaseOption == "ACTIVE")
	{
		return RentalStatus::ACTIVE;
	}
	else if (toUpperCaseOption == "CANCELLED")
	{
		return RentalStatus::CANCELLED;
	}
	else if (toUpperCaseOption == "COMPLETED")
	{
		return RentalStatus::COMPLETED;
	}
}

std::string StringToEnumConvert::rentalStatusToString(RentalStatus rentalStatus)
{
	if (rentalStatus == RentalStatus::ACTIVE)
	{
		return "ACTIVE";
	}
	else if (rentalStatus == RentalStatus::CANCELLED)
	{
		return "CANCELLED";
	}
	else if (rentalStatus == RentalStatus::COMPLETED)
	{
		return "COMPLETED";
	}
}