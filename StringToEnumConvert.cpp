#include "StringToEnumConvert.h"
CarStatus StringToEnumConvert::stringToCarStatus(const std::string& option)
{
	//upper case transf for options!!!
	if (option == "AVAILABLE")
	{
		return CarStatus::AVAILABLE;
	}
	else if (option == "RENTED")
	{
		return CarStatus::RENTED;
	}
	else if (option == "SERVICE")
	{
		return CarStatus::SERVICE;
	}
}

std::string StringToEnumConvert::CarStatusToString(CarStatus status)
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
	if (option == "HATCHBACK")
	{
		return CarType::HATCHBACK;
	}
	else if (option == "SEDAN")
	{
		return CarType::SEDAN;
	}
	else if (option == "SUV")
	{
		return CarType::SUV;
	}
}

std::string StringToEnumConvert::CarTypetoString(CarType type)
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
	if (option == "ACTIVE")
	{
		return RentalStatus::ACTIVE;
	}
	else if (option == "CANCELLED")
	{
		return RentalStatus::CANCELLED;
	}
	else if (option == "COMPLETED")
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