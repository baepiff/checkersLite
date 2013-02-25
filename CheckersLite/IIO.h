#ifndef IO_H
#define IO_H

#pragma once
#include "Type.h"
#include "Position.h"
#include <string>
using std::string;

class IIO
{
public:
	virtual ~IIO(void) {};
	virtual uint selectNotation() = 0;
	virtual void showMessage(const string& message) = 0;
};

#endif