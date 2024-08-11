#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Book class representing individual books in the library
class Book {
private:
    string title;
    string author;
    string ISBN;
    bool isIssued;

public:
    // Constructor
    Book(string t, string a, string isbn) : title(t), author(a), ISBN(isbn), isIssued(false) {}

    // Getters
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return ISBN; }
    bool getIsIssued() const { return isIssued; }

    // Methods to issue and return a book
    void issueBook() {
        if (!isIssued) {
            isIssued = true;
            cout << "Book issued successfully.\n";
        } else {
            cout << "Book is already issued.\n";
        }
    }

    void returnBook() {
        if (isIssued) {
            isIssued = false;
            cout << "Book returned successfully.\n";
        } else {
            cout << "Book was not issued.\n";
        }
    }

    // Display book details
    void displayBook() const {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << ISBN << ", "
             << (isIssued ? "Issued" : "Available") << endl;
    }
};

// Library class representing the library system
class Library {
private:
    vector<Book> books;

public:
    // Add a new book to the library
    void addBook(const Book &book) {
        books.push_back(book);
        cout << "Book added successfully.\n";
    }

    // Search for a book by title
    void searchByTitle(const string &title) const {
        bool found = false;
        for (const auto &book : books) {
            if (book.getTitle() == title) {
                book.displayBook();
                found = true;
            }
        }
        if (!found) {
            cout << "No book found with the title \"" << title << "\".\n";
        }
    }

    // Search for a book by ISBN
    void searchByISBN(const string &isbn) const {
        bool found = false;
        for (const auto &book : books) {
            if (book.getISBN() == isbn) {
                book.displayBook();
                found = true;
            }
        }
        if (!found) {
            cout << "No book found with the ISBN \"" << isbn << "\".\n";
        }
    }

    // Issue a book by ISBN
    void issueBook(const string &isbn) {
        for (auto &book : books) {
            if (book.getISBN() == isbn) {
                book.issueBook();
                return;
            }
        }
        cout << "No book found with the ISBN \"" << isbn << "\".\n";
    }

    // Return a book by ISBN
    void returnBook(const string &isbn) {
        for (auto &book : books) {
            if (book.getISBN() == isbn) {
                book.returnBook();
                return;
            }
        }
        cout << "No book found with the ISBN \"" << isbn << "\".\n";
    }

    // Display all books in the library
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "No books available in the library.\n";
            return;
        }

        for (const auto &book : books) {
            book.displayBook();
        }
    }
};

// Main function
int main() {
    Library library;

    // Add books to the library
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565"));
    library.addBook(Book("1984", "George Orwell", "9780451524935"));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", "9780060935467"));

    // Display all books
    cout << "\nAll books in the library:\n";
    library.displayAllBooks();

    // Search for a book by title
    cout << "\nSearching for '1984':\n";
    library.searchByTitle("1984");

    // Issue a book
    cout << "\nIssuing '1984':\n";
    library.issueBook("9780451524935");

    // Try issuing the same book again
    cout << "\nTrying to issue '1984' again:\n";
    library.issueBook("9780451524935");

    // Return the book
    cout << "\nReturning '1984':\n";
    library.returnBook("9780451524935");

    // Display all books after issuing and returning
    cout << "\nAll books in the library after issuing and returning:\n";
    library.displayAllBooks();

    return 0;
}
