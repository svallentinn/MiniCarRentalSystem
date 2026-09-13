#include "FileAdapter.h"
#include "Constants.h"
#include "ParseStringToNumber.h"
#include "StringToEnumConvert.h"
#include "ACarCreator.h"
#include "CarCreatorDispatcher.h"
void FileAdapter::readNextLine()
{
	_hasNextLine = _reader.getNextLine(_currentLine);
}
std::vector<std::string> FileAdapter::splitFields(const std::string& line)
{
	std::vector<std::string> fields;
	std::string currentField;
	for (short i = 0; i < line.size(); i++)
	{
		char ch = line[i];
		if (ch == Constants::PIPE_DELIMITER)
		{
			fields.push_back(currentField);
			currentField.clear();
		}
		else
		{
			currentField += ch;
		}
	}
	fields.push_back(currentField);
	return fields;
}

ParsedLine FileAdapter::parseCarLine(const std::vector<std::string>& fields)
{
	ParsedLine result;
	if (fields.size() != 6)
	{
		return result;
	}
	short id=0;
	if (!ParseStringToNumber::isConvertedToShort(fields[1], id))
	{
		return result;
	}
	const std::string& model = fields[2];
	CarType type = StringToEnumConvert::stringToCarType(fields[3]);
	float price;
	if (!ParseStringToNumber::isConvetedToFloat(fields[4], price))
	{
		return result;
	}
	std::string upperStatus = StringToEnumConvert::toUpperCase(fields[5]);
	if(upperStatus!= StringToEnumConvert::carStatusToString(CarStatus::AVAILABLE)&&
		upperStatus != StringToEnumConvert::carStatusToString(CarStatus::RENTED) &&
		upperStatus != StringToEnumConvert::carStatusToString(CarStatus::SERVICE))
	{
		return result;
	}	
	CarStatus status = StringToEnumConvert::stringToCarStatus(fields[5]);
	ACarCreator* creator = CarCreatorDispatcher::getCreator(type);
	if (creator == nullptr)
	{
		return result;
	}
	ACar* car = creator->getCar(id, model, price, status);
	if (car == nullptr)
	{
		return result;
	}
	result._kind = FileLineKind::CAR;
	result._car = car;
	return result;
}

ParsedLine FileAdapter::parseRentalLine(const std::vector<std::string>& fields, const std::vector<ACar*>& cars)
{
	ParsedLine result;
	if (fields.size() != 6)
	{
		return result;
	}
	short rentalId=0;
	if (!ParseStringToNumber::isConvertedToShort(fields[1], rentalId))
	{
		return result;
	}
	short carId=0;
	if (!ParseStringToNumber::isConvertedToShort(fields[2], carId))
	{
		return result;
	}
	const std::string& customerName = fields[3];
	short numerOfDays;
	if (!ParseStringToNumber::isConvertedToShort(fields[4], numerOfDays))
	{
		return result;
	}
	std::string upperStatus = StringToEnumConvert::toUpperCase(fields[5]);
	if (upperStatus != StringToEnumConvert::rentalStatusToString(RentalStatus::ACTIVE)&& 
		upperStatus != StringToEnumConvert::rentalStatusToString(RentalStatus::CANCELLED)&&
		upperStatus != StringToEnumConvert::rentalStatusToString(RentalStatus::COMPLETED))
	{
		return result;
	}
	RentalStatus status = StringToEnumConvert::stringToRentalStatus(fields[5]);
	Rental* rental = Rental::create(rentalId, carId, customerName, numerOfDays, status, cars);
	if (rental == nullptr)
	{
		return result;
	}
	result._kind = FileLineKind::RENTAL;
	result._rental = rental;
	return result;
}

FileAdapter::FileAdapter(const std::string& filePath, const std::vector<ACar*>& cars) :_reader(filePath), 
			_currentLine(), _hasNextLine(false), _cars(cars)
{
	readNextLine();
}

bool FileAdapter::isReady() const
{
	return _reader.isOpen();
}

bool FileAdapter::hasNext() const
{
	return _hasNextLine;
}

ParsedLine FileAdapter::readNext()
{
	std::string line = _currentLine;
	readNextLine();
	std::vector<std::string> fields = splitFields(line);
	if (fields[0] == StringToEnumConvert::fileLineKindToString(FileLineKind::CAR))
	{
		return parseCarLine(fields);
	}
	if (fields[0] == StringToEnumConvert::fileLineKindToString(FileLineKind::RENTAL))
	{
		return parseRentalLine(fields, _cars);
	}
	return ParsedLine{};
}