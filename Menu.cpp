#include <iostream>
#include "Menu.h"


using namespace std;


Menu::Menu(Shelf& s) : shelf(s)
{

}

void Menu::mainMenu() {
	int choice = 0;

	while (true) {
		showMenuOptions();
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case 1:
			shelf.inputNewBook();
			break;

		case 2:
			shelf.inputDeleteBook();
			break;

		case 3:
			shelf.inputUpdateBook();
			break;

		case 4:
			shelf.inputSearchByTitle();
			break;
		case 5:
			shelf.inputSearchByAuthor();
			break;

		case 6:
			shelf.inputViewBookDetails();
			break;

		case 7 :
			sortingMenu();
			break;

		case 8:
			shelf.showStatistics();
			break;
			
		case 9:
			shelf.listBooks();
			break;

		case 10:
			cout << "Saving Books..... \n";
			shelf.save("books.csv");
			cout << "Goodbye!\n";
			return;

		default:
			cout << "Invalid option. Try again.\n";

		}
	}
}


void Menu::showMenuOptions() const {
	cout << "\n================= Virtual BookShelf ====================\n";
	cout << "1. Add New Book\n";
	cout << "2. Remove Book From Shelf\n";
	cout << "3. Update Book\n";
	cout << "4. Search Books By Title\n";
	cout << "5. Search Books By Author\n";
	cout << "6. View Book Details\n";
	cout << "7. Sorting Options\n";
	cout << "8. View Statistics\n";
	cout << "9. List All Books on The Shelf\n";
	cout << "10. Save & Exit\n";
	cout << "===========================================================\n";
	cout << "Choose an option: ";
}

void Menu::sortingMenu() {
	int choice;

	cout << "\n============== Sorting Options ==============\n";
	cout << "1. Sort By Title\n";
	cout << "2. Sort By Author\n";
	cout << "3. Sort By Year\n";
	cout << "4. Sort By Number of Pages\n";
	cout << "5. Sort By Genre\n";
	cout << "5. Sort By Rating\n";
    cout << "5. Sort By Status\n";
	cout << "6. Back to the Main Menu\n";
	cout << "Choose: ";

	cin >> choice;
	cin.ignore();

	switch (choice) {
	case 1:
		shelf.sortByTitle();
		break;
	case 2:
		shelf.sortByAuthor();
		break;
	case 3:
		shelf.sortByYear();
		break;
	case 4:
		shelf.sortByPages();
		break;
	case 5:
		shelf.sortByGenre();
		break;
	case 6:
		shelf.sortByRating();
		break;
	case 7:
		shelf.sortByStatus();
		break;
	default:
		return;
	}
}