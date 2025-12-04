#pragma once

#include <string>
#include <vector>

using namespace std;

class Book {
private:
	int id;
	int year;
	int pages;
	int rating;

	string title;
	string author;
	string genre;
	string status;

public:
	Book();

	Book(int id, int year, int pages, int rating, const string& title, const string& author, const string& genre, const string& status);

	// Getters
	int getId() const;
	int getYear() const;
	int getPages() const;
	int getRating() const;

	string getTitle() const;
	string getAuthor() const;
	string getGenre() const;
	string getStatus() const;

	// Setters
	void setId(int bookId);
	void setYear(int bookYear);
	void setPages(int bookPages);
	void setRating(int bookRating);

	void setTitle(const string& bookTitle);
	void setAuthor(const string& bookAuthor);
	void setGenre(const string& bookGenre);
	void setStatus(const string& bookStatus);

	string toCsv() const;
	static Book fromCsv(const string& line);



};