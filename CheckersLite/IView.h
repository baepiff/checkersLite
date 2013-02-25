#ifndef VIEW_H
#define VIEW_H

#pragma once
class IView
{
public:
	virtual ~IView(void) {};
	virtual void draw() = 0;
	virtual void clear() = 0;
};

#endif