#ifndef CONSOLE_VIEW_H
#define CONSOLE_VIEW_H

#pragma once
#include "IView.h"
#include "Board.h"
#include <iostream>
#include <vector>

class ConsoleView : public IView
{
public:
	ConsoleView(void);
	~ConsoleView(void);
	void draw();
	void clear();
};

#endif