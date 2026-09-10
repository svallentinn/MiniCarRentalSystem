#include<iostream>
#include "ACar.h"
#include "Constants.h"
#include "StringToEnumConvert.h"

ACar::ACar(short id, const std::string& model, float pricePerDay, CarStatus status):
	_id{ id }, _model{ model }, _pricePerDay{ pricePerDay }, _status{status} {}

ACar::~ACar() {}

short ACar::getId() const
{
	return _id;
}

const std::string& ACar::getTypeString() const
{
	return _model;
}

float ACar::getPricePerDay() const
{
	return _pricePerDay;
}

CarStatus ACar::getStatus() const
{
	return _status;
}

void ACar::printInfo() const
{
	StringToEnumConvert converter;
	std::cout << "Car " << Constants::PIPE_DELIMITER << " " << _model << " " << Constants::PIPE_DELIMITER <<
		converter.carTypeToString(getType()) << " " << Constants::PIPE_DELIMITER << " " << _pricePerDay << " "
		<< Constants::RON_CURRENCY<< "/" << Constants::DAY << " " << Constants::PIPE_DELIMITER << " " 
		<< converter.carStatusToString(_status) << std::endl;	
}

bool ACar::isValid(short id, const std::string& model, float pricePerDay)
{
	if (id <= 0)
	{
		return false;
	}
	if (model.empty())
	{
		return false;
	}
	if (pricePerDay <= 0)
	{
		return false;
	}
	return true;
}
