#include "stdafx.h"
#include "ViewFactory.h"


ViewFactory::ViewFactory(void)
{
}


ViewFactory::~ViewFactory(void)
{
}

IView* ViewFactory::createView(enum VIEW_TYPE type) {
	IView* view = NULL;
	switch (type) {
	case VIEW_TYPE::CONSOLE_VIEW:
		view = new ConsoleView();
		break;
	default:
		view = new ConsoleView();
	}
	return view;
}