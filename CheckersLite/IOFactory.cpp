#include "stdafx.h"
#include "IOFactory.h"


IOFactory::IOFactory(void)
{
}


IOFactory::~IOFactory(void)
{
}

IIO* IOFactory::createIO(enum IO_TYPE type) {
	IIO* io = NULL;
	switch (type) {
	case IO_TYPE::CONSOLE_IO:
		io = new ConsoleIO();
		break;
	default:
		io = new ConsoleIO();
		break;
	}
	return io;
}
