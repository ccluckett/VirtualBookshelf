#include <iostream>
#include "Shelf.h"
#include "Menu.h"

using namespace std;


int main() {

	Shelf shelf;

	shelf.load("books.csv");

	Menu menu(shelf);
	menu.mainMenu();

	return 0;
}