# Virtual Bookshelf – Final Project (COSC 2436)

This project is a Virtual Bookshelf application written in C++ for my Programming Fundamentals III course. The program allows users to maintain a personal digital library with full support for adding books, updating existing entries, removing books, searching by title or author, sorting the library by different criteria, viewing detailed information, and tracking reading statistics. All data is stored in a CSV file for persistence between program runs.

The project is built using an object-oriented structure split across multiple classes:
- **Book** – Represents a single book and handles conversions to/from CSV format.
- **Shelf** – Manages the full collection using a vector and implements all functional features (add, remove, update, search, sort, statistics, etc.).
- **Storage** – Handles loading and saving the collection to a CSV file.
- **Menu** – Controls the user interface, input validation, and routing of user choices.
- **main.cpp** – Initializes the program and starts the main menu loop.


## Demo Video  
**View Presentation:**  
👉 (https://drive.google.com/file/d/1GNijwSRuWGvBbqEpHOgBanyr9SRPY16R/view?usp=sharing)

