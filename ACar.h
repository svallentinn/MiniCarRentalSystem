#pragma once
#include <string>
#include "CarStatus.h"
#include "CarType.h"
class ACar
{
protected:
	short _id;
	std::string _model;
	float _pricePerDay;
	CarStatus _status;
public:
	ACar(short id, const std::string& model, float pricePerDay, CarStatus status);
	virtual ~ACar() = 0;
	short getId() const;
	const std::string& getTypeString() const;
	float getPricePerDay() const;
	CarStatus getStatus() const;
	virtual CarType getType() const = 0;
	virtual void printInfo() const;
	static bool isValid(short id, const std::string& model, float pricePerDay);
};