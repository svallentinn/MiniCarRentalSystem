#pragma once
#include "ParsedLine.h"
class IDataSource
{
public:
	virtual ~IDataSource() = 0;
	virtual bool isReady() const = 0;
	virtual bool hasNext() const = 0;
	virtual ParsedLine readNext() = 0;
};

