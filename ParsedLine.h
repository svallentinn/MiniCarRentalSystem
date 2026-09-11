#pragma once
#include "ACar.h"
#include "FileLineKind.h"
#include "Rental.h"
class ParsedLine
{
public:
	FileLineKind _kind;
	ACar* _car;
	Rental* _rental;
	ParsedLine();
	ParsedLine(ACar* car);
	ParsedLine(Rental* rental);
};

