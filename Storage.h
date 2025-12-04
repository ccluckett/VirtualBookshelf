#pragma once

#include <string>
#include <vector>
#include "Book.h"

using namespace std;

class Storage {
public:
	static vector<Book> loadCsv(const string& path);
	static void saveCsv(const string& path, const vector<Book>& books);
};