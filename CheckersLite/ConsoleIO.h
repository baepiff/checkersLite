#ifndef CONSOLE_IO_H
#define CONSOLE_IO_H

#pragma once
#include "IIO.h"

class ConsoleIO : public IIO
{
public:
	ConsoleIO(void);
	~ConsoleIO(void);
	uint selectNotation();
	void showMessage(const string& message);
};

#endif