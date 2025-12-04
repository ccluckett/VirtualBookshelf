#include <iostream>
#include "Shelf.h"
#include "Storage.h"
#include <algorithm>

using namespace std;


Shelf::Shelf()
{

}

void Shelf::addBook(const Book& b)
{
	books.push_back(b);
	cout << "Book added to shelf.\n";
}

bool Shelf::deleteBook(int id) {
	for (size_t i = 0; i < books.size(); i++) {
		if (books[i].getId() == id) {
			books.erase(books.begin() + i);
			cout << "Book with ID " << id << " deleted.\n";
			return true;
		}
	}

	cout << "No Book with ID " << id << "found.\n";
	return false;   
}

void Shelf::updateBook(int id) {
	for (auto& b : books) {
		if (b.getId() == id) {

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			int id;
			int year;
			int pages;
			int rating;

			string title;
			string author;
			string genre;
			string status;
			string input;

			cout << "Leave a Field Blank to Keep The Current Value.\n\n";

			cout << "New Title (" << b.getTitle() << "): ";
			getline(cin, input);
			if (!input.empty()) b.setTitle(input);


			cout << "New Author (" << b.getAuthor() << "): ";
			getline(cin, input);
			if (!input.empty()) b.setAuthor(input);


			cout << "New Genre (" << b.getGenre() << "): ";
			getline(cin, input);
			if (!input.empty()) b.setGenre(input);

			cout << "New Status (" << b.getStatus() << "): ";
			getline(cin, input);
			if (!input.empty()) b.setStatus(input);

			cout << "New Year (" << b.getYear() << "): ";
			getline(cin, input);
			if (!input.empty()) b.setYear(stoi(input));

			cout << "New Pages (" << b.getPages() << "): ";
			getline(cin, input);
			if (!input.empty()) b.setPages(stoi(input));

			cout << "New Rating (" << b.getRating() << "): ";
			getline(cin, input);
			if (!input.empty()) b.setRating(stoi(input));
			
			cout << "Book updated.\n";
			return;
		}
	}
	cout << "Book with ID " << id << " not found.\n";
}

void Shelf::viewBookDetails(int id) const {
	for (const auto& b : books) {
		if (b.getId() == id) {
			
			cout << "\n======================== Book Details =======================\n";
			cout << "ID: " << b.getId() << "\n";
			cout << "Title: " << b.getTitle() << "\n";
			cout << "Author: " << b.getAuthor() << "\n";
			cout << "Genre: " << b.getGenre() << "\n";
			cout << "Year: " << b.getYear() << "\n";
			cout << "Pages: " << b.getPages() << "\n";
			cout << "Rating: " << b.getRating() << "\n";
			cout << "Status: " << b.getStatus() << "\n";
			cout << "================================================================\n";
			return;
		}

		cout << "Book with ID" << id << "not found\n";
	}
}

void Shelf::showStatistics() const {
	if (books.empty()) {
		cout << "There are not any Books on the shelf.\n";
		return;
	}

	int total = books.size();
	int finished = 0;
	int reading = 0;
	int toBeRead = 0;
	int totalPages = 0;
	double totalRating = 0;
	int longest = 0;
	int shortest = INT_MAX;

	for (const auto& b : books) {
		totalPages += b.getPages();
		totalRating += b.getRating();
		 
		if (b.getPages() > longest)
			longest = b.getPages();
		if (b.getPages() < shortest)
			shortest = b.getPages();

		string bookStatus = b.getStatus();
		transform(bookStatus.begin(), bookStatus.end(), bookStatus.begin(), ::tolower);

		if (bookStatus == "finished") finished++;
		else if (bookStatus == "reading") reading++;
		else toBeRead++;
	}

	cout << "\n============ Statistics ================\n";
	cout << "Total Books: " << total << "\n";
	cout << "Finished Books: " << finished << "\n";
	cout << "Books Currently Reading: " << reading << "\n";
	cout << "To Be Read: " << toBeRead << "\n";
	cout << "Total Pages: " << totalPages << "\n";
	cout << "Average Rating: " << totalRating / total << "\n";
	cout << "Longest Book: " << longest << "\n";
	cout << "Shortest Book: " << shortest << "\n";
	cout << "\n========================================\n";
}

Book* Shelf::findBookById(int id) {
	for (auto& b : books) {
		if (b.getId() == id) {
			return &b;
		}
	}

	return nullptr;
}

vector<Book*> Shelf::findBookByTitle(const string& title) {
	vector<Book*> results;
	string lowerSearch = title;

	transform(lowerSearch.begin(), lowerSearch.end(), lowerSearch.begin(), ::tolower);

	for (auto& b : books) {
		string t = b.getTitle();   
		transform(t.begin(), t.end(), t.begin(), ::tolower);

		if (t.find(lowerSearch) != string::npos) {
			results.push_back(&b);
		}
	}

	return results;
}

vector<Book*> Shelf::findBookByAuthor(const string& author) {
	vector<Book*> results;
	string lowerSearch = author;

	transform(lowerSearch.begin(), lowerSearch.end(), lowerSearch.begin(), ::tolower);

	for (auto& b : books) {
		string t = b.getAuthor();
		transform(t.begin(), t.end(), t.begin(), ::tolower);

		if (t.find(lowerSearch) != string::npos) {
			results.push_back(&b);
		}
	}

	return results;
}

void Shelf::sortByTitle() {
	sort(books.begin(), books.end(), []
	(const Book& a, const Book& b) {
			return a.getTitle() < b.getTitle();
		});
	
	cout << "Books sorted by Title.\n";
}

void Shelf::sortByAuthor() {
	sort(books.begin(), books.end(), []
	(const Book& a, const Book& b) {
			return a.getAuthor() < b.getAuthor();
		});

	cout << "Books sorted by Author.\n";
}

void Shelf::sortByYear() {
	sort(books.begin(), books.end(), []
	(const Book& a, const Book& b) {
			return a.getYear() < b.getYear();
		});

	cout << "Books sorted by Year Released.\n";
}

void Shelf::sortByPages() {
	sort(books.begin(), books.end(), []
	(const Book& a, const Book& b) {
			return a.getPages() < b.getPages();
		});

	cout << "Books sorted by Page Count.\n";
}

void Shelf::sortByGenre() {
	sort(books.begin(), books.end(), []
	(const Book& a, const Book& b) {
			return a.getGenre() < b.getGenre();
		});

	cout << "Books sorted by Genre.\n";
}

void Shelf::sortByRating() {
	sort(books.begin(), books.end(), []
	(const Book& a, const Book& b) {
			return a.getRating() < b.getRating();
		});

	cout << "Books sorted by Rating.\n";
}

void Shelf::sortByStatus() {
	sort(books.begin(), books.end(), []
	(const Book& a, const Book& b) {
			return a.getStatus() < b.getStatus();
		});

	cout << "Books sorted by Status.\n";
}
void Shelf::inputNewBook() {
	int id;
	int year;
	int pages;
	int rating;

	string title;
	string author;
	string genre;
	string status;

	cout << "Enter ID: ";     
	cin >> id;
	cin.ignore();

	cout << "Enter Year: ";
	cin >> year;

	cout << "Enter the Number of Pages: ";
	cin >> pages;

	cout << "How Would You Rate This Book (1-5): ";
	cin >> rating;

	cin.ignore();

	cout << "Enter Title: ";
	getline(cin, title);
	
	cout << "Enter Author: ";
	getline(cin, author);

	cout << "Enter Genre: ";
	getline(cin, genre);

	cout << "Enter Status: ";
	getline(cin, status);


	Book b(id, year, pages, rating, title, author, genre, status);
	addBook(b);

	cout << "New Book Added to the Shelf!\n";

}

void Shelf::inputDeleteBook() {
	int id;
	
	cout << "Enter the ID of the Book you would like to remove from the shelf: ";
	cin >> id;
	cin.ignore();
	deleteBook(id);
}

void Shelf::inputUpdateBook() {
	int id;

	cout << " Enter the ID of the Book You WOuld Like to Update: ";
	cin >> id;
	updateBook(id);
}

void Shelf::inputSearchByTitle() {
	cout << "Enter title or part of a Title: ";

	cin.ignore();
	string title;

	getline(cin, title);

	auto results = findBookByTitle(title);

	if (results.empty()) {
		cout << "No matching books.\n";
		return;
	}

	cout << "\nSearch Results:\n";
	for (auto* b : results) {
		cout << b->getId() << "|" << b->getTitle() << " | " << b->getAuthor() << "\n";
	}
}

void Shelf::inputSearchByAuthor() {
	cout << "Enter author name or part of the authors name: ";

	cin.ignore();
	string author;

	getline(cin, author);

	auto results = findBookByAuthor(author);

	if (results.empty()) {
		cout << "No matching books found written by that author.\n";
		return;
	}

	cout << "\nSearch Results:\n";
	for (auto* b : results) {
		cout << b->getId() << "|" << b->getTitle() << " | " << b->getAuthor() << "\n";
	}
}

void Shelf::inputViewBookDetails() {
	int id;
	cout << "Enter Book ID to View Details: ";
	cin >> id;
	cin.ignore();
	viewBookDetails(id);
}

void Shelf::listBooks() const
{
	if (books.empty()) {
		cout << "No books available.\n";
		return;
	}

	for (const auto& b : books) {
		cout << b.getId() << " | " << b.getYear() << " | "
			<< b.getPages() << " | " << b.getRating() << " | "
			<< b.getTitle() << " | " << b.getAuthor() << " | "
			<< b.getGenre() << " | " << b.getStatus() << "\n";
	}
}


void Shelf::load(const string& path) {
	books = Storage::loadCsv(path);
}

void Shelf::save(const string& path) const {
	Storage::saveCsv(path, books);
}



