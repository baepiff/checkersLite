#include "stdafx.h"
#include "ConsoleIO.h"
#include <iostream>

using std::cout;
using std::cin;

ConsoleIO::ConsoleIO(void)
{
}


ConsoleIO::~ConsoleIO(void)
{
}

uint ConsoleIO::selectNotation() {
	uint notation;
	cin >> notation;
	return notation;
}

void ConsoleIO::showMessage(const string& message) {
	cout << message;
}