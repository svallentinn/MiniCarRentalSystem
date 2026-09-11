#include "CarCreatorDispatcher.h"
#include "SedanCarCreator.h"
#include "HatchbackCarCreator.h"
#include "SuvCarCreator.h"
ACarCreator* CarCreatorDispatcher::getCreator(CarType type)
{
	static HatchbackCarCreator hatchbackCreator;
	static SedanCarCreator sedanCreator;
	static SuvCarCreator suvCreator;
	if (type == CarType::HATCHBACK)
	{
		return& hatchbackCreator;
	}
	else if (type == CarType::SEDAN)
	{
		return& sedanCreator;
	}
	else if (type == CarType::SUV)
	{
		return&suvCreator;
	}
	return nullptr;
}