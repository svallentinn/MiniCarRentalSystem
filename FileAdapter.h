#pragma once
#include <string>
#include<vector>
#include "IDataSource.h"
#include "FileReader.h"
class FileAdapter :public IDataSource
{
private:
	FileReader _reader;
	std::string _currentLine;
	bool _hasCurrentLine;
	void nextLine();
	static std::vector<std::string> splitFields(const std::string& line);
	static ParsedLine parseCarLine(const std::vector<std::string>& fields);
	static ParsedLine parseRentalLine(const std::vector<std::string>& fields);
public:
	FileAdapter(const std::string& filePath);
	bool isReady() const;
	bool hasNext() const;
	ParsedLine readNext();
};

