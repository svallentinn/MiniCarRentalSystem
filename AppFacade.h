#pragma once
#include <vector>
#include "CarStatus.h"
#include "CarType.h"
#include "RentalStatus.h"
#include "Rental.h"
class AppFacade
{
private:
	std::vector<ACar*> _cars;
	std::vector<Rental*> _rentals;

	CarType readCarType() const;
	CarStatus readCarStatus() const;
	RentalStatus readRentalStatus() const;
	void appCreateCar();
	void appCreateRental();
	void appFileImport();
public:
	void appStart();
	~AppFacade();
};

