#pragma once
#include <vector>
#include <string>
#include "Book.h"

class Shelf {
private:
	vector<Book> books;

public:
	Shelf();


	//Core Functions
	void addBook(const Book& b);
	bool deleteBook(int id);
	void updateBook(int id);
	void viewBookDetails(int id) const;
	void showStatistics() const;

	// search
	Book* findBookById(int id);
	vector<Book*> findBookByTitle(const string& title);
	vector<Book*> findBookByAuthor(const string& author);

	// sort
	void sortByTitle();
	void sortByAuthor();
	void sortByYear();
	void sortByPages();
	void sortByGenre();
	void sortByRating();
	void sortByStatus();


	// User input Versions
	void inputNewBook();
	void inputDeleteBook();
	void inputUpdateBook();
	void inputSearchByTitle();
	void inputSearchByAuthor();
	void inputViewBookDetails();

	// Display
	void listBooks() const;

	// File I/O
	void load(const string& path);
	void save(const string& path) const;


};