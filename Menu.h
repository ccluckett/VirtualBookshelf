#pragma once
#include "Shelf.h"

class Menu {
private:
	Shelf& shelf;

public:
	Menu(Shelf& s);

	void mainMenu();
	void showMenuOptions() const;
	void sortingMenu();
};