#include <iostream>
#include <string>
#include "AppFacade.h"
#include "StringToEnumConvert.h"
#include "ACar.h"
#include "CarCreatorDispatcher.h"
#include "FileAdapter.h"
#include "Constants.h"
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
	short id=0;
	std::string model;
	float pricePerDay = 0;
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
	short rentalId=0;
	short carId=0;
	std::string customerName;
	short numberOfDays=0;
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
	short option=0;
	do
	{
		std::cout << std::endl << "MINI CAR RENTAL SYSTEM" << std::endl << "1. Create Car" << std::endl <<
			"2. Create Rental" << std::endl << "3. Import data from file" << std::endl <<
			"4. Exit" << std::endl << "Choose an option:" << std::endl;
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
			appImportFile();
		}
		else if (option == 4)
		{
			std::cout << std::endl << "Exiting!";
		}
		else
		{
			std::cout << std::endl << "Invalid option." << std::endl;
		}
	} while (option != 4);
}

void AppFacade::appImportFile()
{
	std::cin.ignore(1, '\n');
	std::cout << std::endl << "Enter file path(empty for default " << Constants::DEFAULT_DATA_FILE << " ):" << std::endl;
	std::string filePath;
	std::getline(std::cin, filePath);
	if (filePath.empty())
	{
		filePath = Constants::DEFAULT_DATA_FILE;
	}
	FileAdapter fileSource(filePath, _cars);
	if (!fileSource.isReady())
	{
		std::cout << std::endl << "The file could not be opened." << std::endl;
		return;
	}
	short carsLoaded = 0;
	short validRentals = 0;
	short invalidLines = 0;
	while (fileSource.hasNext())
	{
		ParsedLine result = fileSource.readNext();
		if (result._kind==FileLineKind::CAR)
		{
			_cars.push_back(result._car);
			carsLoaded++;
		}
		else if (result._kind == FileLineKind::RENTAL)
		{
			_rentals.push_back(result._rental);
			validRentals++;
		}
		else if (result._kind == FileLineKind::INVALID)
		{
			invalidLines++;
		}
	}
	std::cout << std::endl << "Cars Loaded " << carsLoaded << std::endl << "Rentals Loaded " << validRentals << std::endl
		<< "Invalid Lines " << invalidLines << std::endl;
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