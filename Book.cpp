#include "Book.h"
#include <sstream>

#include <string>
using namespace std;

Book::Book()
	:id(-1), year(0), pages(0), rating(0)
{

}

Book::Book(int id, int year, int pages, int rating, const string& title, const string& author, const string& genre, const string& status)
	: id(id), year(year), pages(pages), rating(rating), title(title), author(author), genre(genre), status(status)
{

}

// Getters

int Book::getId() const
{
	return id;
}

int Book::getYear() const
{
	return year;
}

int Book::getPages() const
{
	return pages;
}

int Book::getRating() const
{
	return rating;
}

string Book::getTitle() const
{
	return title;
}

string Book::getAuthor() const
{
	return author;
}

string Book::getGenre() const
{
	return genre;
}

string Book::getStatus() const
{
	return status;
}



//setters

void Book::setId(int bookId)
{
	id = bookId;
}

void Book::setYear(int bookYear)
{
	author = bookYear;
}

void Book::setPages(int bookPages)
{
	pages = bookPages;
}

void Book::setRating(int bookRating)
{
	rating = bookRating;
}

void Book::setTitle(const string& bookTitle)
{
	title = bookTitle;
}

void Book::setAuthor(const string& bookAuthor)
{
	author = bookAuthor;
}

void Book::setGenre(const string& bookGenre)
{
	genre = bookGenre;
}

void Book::setStatus(const string& bookStatus)
{
	status = bookStatus;
}


string Book::toCsv() const
{
	ostringstream os;

	os << id << "," << year << "," << pages << "," << rating << ","
		<< title << "," << author << "," << genre << "," << status;

	return os.str();
}

Book Book::fromCsv(const string& line)
{
	Book b;
	stringstream ss(line);
	string token;

	getline(ss, token, ',');
	b.id = stoi(token);

	getline(ss, token, ',');
	b.year = stoi(token);

	getline(ss, token, ',');
	b.pages = stoi(token);

	getline(ss, token, ',');
	b.rating = stoi(token);


	getline(ss, b.title, ',');
	getline(ss, b.author, ',');
	getline(ss, b.genre, ',');
	getline(ss, b.status, ',');
	
	return b;
}