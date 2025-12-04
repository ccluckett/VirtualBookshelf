#include "Storage.h"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

vector<Book> Storage::loadCsv(const string& path) {
	vector<Book> out;
	ifstream file(path);

	if (!file.is_open()) {
		cout << "No data file found at " << path << ". Starting fresh.\n";
		return out;
	}

	string line;
	while (getline(file, line)) {
		if (line.size() < 3) continue;      //ignore empty lines
		out.push_back(Book::fromCsv(line));
	}
	
	return out;
}

void Storage::saveCsv(const string& path, const vector<Book>& books) {
	ofstream file(path, ios::trunc);

	if (!file.is_open()) {
		cout << "ERROR: Could not save file.\n";
		return;
	}

	for (const auto& b : books) {
		file << b.toCsv() << "\n";
	}
}