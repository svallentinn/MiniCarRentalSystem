#include <iostream>
#include <string>
#include "AppFacade.h"
#include "StringToEnumConvert.h"
#include "ACar.h"
#include "CarCreatorDispatcher.h"
CarType AppFacade::readCarType() const
{
	std::string option;
	while (true)
	{
		std::cout << std::endl << "Enter car type(only HATCHBACK, SEDAN or SUV): " << std::endl;
		std::cin >> option;
		std::string toUpperCaseOption = StringToEnumConvert::toUpperCase(option);
		if (toUpperCaseOption =="HATCHBACK" || toUpperCaseOption =="SEDAN"|| toUpperCaseOption =="SUV")
		{
			return StringToEnumConvert::stringToCarType(option);
		}
		std::cout << std::endl << "Invalid car type. try again:" << std::endl;
	}
}
CarStatus AppFacade::readCarStatus() const
{
	std::string option;
	while (true)
	{
		std::cout << std::endl << "Enter car status (only AVAILABLE, RENTED or SERVICE): " << std::endl;
		std::cin >> option;
		std::string toUpperCaseOption = StringToEnumConvert::toUpperCase(option);
		if (toUpperCaseOption == "AVAILABLE" || toUpperCaseOption == "RENTED" || toUpperCaseOption == "SERVICE")
		{
			return StringToEnumConvert::stringToCarStatus(option);
		}
		std::cout << std::endl << "Invalid car status. try again:" << std::endl;
	}
}
RentalStatus AppFacade::readRentalStatus() const
{
	std::string option;
	while (true)
	{
		std::cout << std::endl << "Enter rental status (only ACTIVE, CANCELLED or COMPLETED): " << std::endl;
		std::cin >> option;
		std::string toUpperCaseOption = StringToEnumConvert::toUpperCase(option);
		if (toUpperCaseOption == "ACTIVE" || toUpperCaseOption == "CANCELLED" || toUpperCaseOption == "COMPLETED")
		{
			return StringToEnumConvert::stringToRentalStatus(option);
		}
		std::cout << std::endl << "Invalid rental status. try again:" << std::endl;
	}
}
void AppFacade::appCreateCar()
{
	short id;
	std::string model;
	float pricePerDay;
	std::cout << std::endl << "Enter car id: " << std::endl;
	std::cin >> id;
	std::cout << std::endl << " Enter car model: " << std::endl;
	std::cin >> model;
	std::cout << std::endl << " Enter price per day: " << std::endl;
	std::cin >> pricePerDay;
	CarType type = readCarType();
	CarStatus status = readCarStatus();
	ACarCreator* creator = CarCreatorDispatcher::getCreator(type);
	if (creator == nullptr)
	{
		std::cout << std::endl << "Could not create car." << std::endl;
		return;
	}
	ACar* car = creator->getCar(id, model, pricePerDay, status);
	if (car != nullptr)
	{
		_cars.push_back(car);
		std::cout << std::endl << "Car created successfully: " << std::endl;
		car->printInfo();
	}
	else
	{
		std::cout << std::endl << "Car creation failed." << std::endl;
	}
}
void AppFacade::appCreateRental()
{
	short rentalId;
	short carId;
	std::string customerName;
	short numberOfDays;
	std::cout << std::endl << "Enter Rental id: " << std::endl;
	std::cin >> rentalId;
	std::cout << std::endl << "Enter car id: " << std::endl;
	std::cin >> carId;
	std::cout << std::endl << "Enter customer name: " << std::endl;
	std::cin >> customerName;
	std::cout << std::endl << "Enter number of days: " << std::endl;
	std::cin >> numberOfDays;
	RentalStatus status = readRentalStatus();
	Rental* rental = Rental::create(rentalId, carId, customerName, numberOfDays, status, _cars );
	if (rental != nullptr)
	{
		_rentals.push_back(rental);
		std::cout << std::endl << "Rental created succesfully.";
		rental->printRentalInfo();
	}
	else
	{
		std::cout << "Rental creation failed.";
	}
}
void AppFacade::appStart()
{
	short option;
	do
	{
		std::cout << std::endl << "MINI CAR RENTAL SYSTEM" << std::endl << "1. Create Car" << std::endl <<
			"2. Create Rental" << std::endl << "3. Exit" << std::endl << "Choose an option:" << std::endl;
		std::cin >> option;
		if (option == 1)
		{
			appCreateCar();
		}
		else if (option == 2)
		{
			appCreateRental();
		}
		else if (option == 3)
		{
			std::cout << std::endl << "Exiting!";
		}
		else
		{
			std::cout << std::endl << "Invalid option." << std::endl;
		}
	} while (option != 3);
}

AppFacade::~AppFacade()
{
	for (short i = 0; i < _cars.size(); i++)
	{
		delete _cars[i];
	}

	for (short i = 0; i < _rentals.size(); i++)
	{
		delete _rentals[i];
	}
}