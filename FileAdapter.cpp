#include "FileAdapter.h"
#include "Constants.h"
#include "ParseStringToNumber.h"
#include "StringToEnumConvert.h"
#include "ACarCreator.h"
#include "CarCreatorDispatcher.h"
void FileAdapter::nextLine()
{
	_hasCurrentLine = _reader.getNextLine(_currentLine);
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
}

ParsedLine FileAdapter::parseCarLine(const std::vector<std::string>& fields)
{
	ParsedLine result;
	if (fields.size() != 6)
	{
		return result;
	}
	short id;
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

ParsedLine FileAdapter::parseRentalLine(const std::vector<std::string>& fields)
{

}

FileAdapter::FileAdapter(const std::string& filePath) :_reader(filePath), _currentLine(), _hasCurrentLine(false)
{
	nextLine();
}

bool isReady() const
{

}

bool hasNext() const
{

}

ParsedLine readNext()
{

}