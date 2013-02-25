#ifndef IO_FACTORY_H
#define IO_FACTORY_H

#pragma once
#include "IIO.h"
#include "ConsoleIO.h"

class IOFactory
{
public:
	IOFactory(void);
	~IOFactory(void);
	static IIO* createIO(enum IO_TYPE type);
};

enum IO_TYPE {
	CONSOLE_IO
};
#endif
