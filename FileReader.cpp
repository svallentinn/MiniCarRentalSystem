#include "FileReader.h"
FileReader::FileReader(const std::string& filepath): _file(filepath){}

bool FileReader::getNextLine(std::string& outputLine)
{
	if (std::getline(_file, outputLine))
	{
		return true;
	}
	return false;
}