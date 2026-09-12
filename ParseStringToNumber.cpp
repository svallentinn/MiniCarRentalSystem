#include "ParseStringToNumber.h"
#include "Constants.h"
bool ParseStringToNumber::isConvertedToShort(const std::string& text, short& outputValue)
{
	if (text.empty())
	{
		return false;
	}
	short index = 0;
	bool isNegative = false;
	if (text[0] == '-')
	{
		isNegative = true;
		index = 1;
	}
	if (index >= text.size())
	{
		return false;
	}
	for (; index < text.size(); index++)
	{
		char ch = text[index];
		if (ch < '0' || ch>'9')
		{
			return false;
		}
		outputValue = outputValue * Constants::DECIMAL_BASE + (ch-'0');
	}
	if (isNegative)
	{
		outputValue = -outputValue;
	}	
	return true;
}

bool ParseStringToNumber::isConvetedToFloat(const std::string& text, float& outputValue)
{
	if (text.empty())
	{
		return false;
	}
	unsigned short i = 0;
	bool isNegative = (text[0] == '-');
	if (isNegative)
	{
		i = 1;
	}
	bool hasDigits = false;
	bool hasDot = false;
	double shortPart = 0;
	double fractionPart = 0;
	double fractionDivisor = 1;
	for (; i < text.size(); i++)
	{
		char ch = text[i];
		if (ch == '.')
		{
			if (hasDot)
			{
				return false;
			}
			hasDot = true;
		}
		else if (ch >= '0' && ch <= '9')
		{
			hasDigits = true;
			if (hasDot)
			{
				fractionDivisor *= Constants::DECIMAL_BASE;
				fractionPart = fractionPart * Constants::DECIMAL_BASE + (ch - '0');
			}
			else
			{
				shortPart = shortPart * Constants::DECIMAL_BASE + (ch - '0');
			}
		}
	}
	if (!hasDigits)
	{
		return false;
	}
	outputValue = shortPart + fractionPart / fractionDivisor;
	if (isNegative)
	{
		outputValue = -outputValue;
	}
	return true;
}