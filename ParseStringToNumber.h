#pragma once
#include <string>
class ParseStringToNumber
{
public:
	static bool isConvertedToShort(const std::string& text, short& outputValue);
	static bool isConvetedToFloat(const std::string& text, float& outputValue);
};

