#pragma once
#include <string>
#include<vector>
#include "IDataSource.h"
#include "FileReader.h"
#include "ACar.h"
class FileAdapter :public IDataSource
{
private:
	FileReader _reader;
	std::string _currentLine;
	bool _hasNextLine;
	const std::vector<ACar*>& _cars;
	void readNextLine();
	static std::vector<std::string> splitFields(const std::string& line);
	static ParsedLine parseCarLine(const std::vector<std::string>& fields);
	static ParsedLine parseRentalLine(const std::vector<std::string>& fields, const std::vector<ACar*>& cars);
public:
	FileAdapter(const std::string& filePath, const std::vector<ACar*>& cars);
	bool isReady() const;
	bool hasNext() const;
	ParsedLine readNext();
};

