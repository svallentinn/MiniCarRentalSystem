#pragma once
#include <fstream>
#include <string>
class FileReader
{
private:
	std::ifstream _file;
public:
	FileReader(const std::string& filepath);
	bool isOpen() const;
	bool getNextLine(std::string& outputLine);
};

