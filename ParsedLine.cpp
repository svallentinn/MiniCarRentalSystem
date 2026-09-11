#include "ParsedLine.h"
ParsedLine::ParsedLine() :_kind{ FileLineKind::INVALID }, _car{ nullptr }, _rental{ nullptr } {}

ParsedLine::ParsedLine(ACar* car) :_kind{ FileLineKind::CAR }, _car{ car }, _rental{ nullptr } {}

ParsedLine::ParsedLine(Rental* rental) :_kind{ FileLineKind::RENTAL }, _car{ nullptr}, _rental{ rental } {}
