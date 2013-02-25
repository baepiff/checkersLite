#ifndef VIEW_FACTORY_H
#define VIEW_FACTORY_H

#pragma once
#include "IView.h"
#include "ConsoleView.h"

class ViewFactory
{
public:
	ViewFactory(void);
	~ViewFactory(void);
	static IView* createView(enum VIEW_TYPE type);
};
	enum VIEW_TYPE {
		CONSOLE_VIEW
	};
#endif

