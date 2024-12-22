
#include <iostream>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    string publication;
    int quantity;
    bool isAvailable;
};

void addBook(Book books[], int& size) {
    cout << "Enter book title: ";
    cin >> books[size].title;
    cout << "Enter book author: ";
    cin >> books[size].author;
    cout << "Enter book publication: ";
    cin >> books[size].publication;
    cout << "Enter book quantity: ";
    cin >> books[size].quantity;
    books[size].isAvailable = true;
    size++;
}

void displayBooks(Book books[], int size) {
    cout << "Library Book List:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Title: " << books[i].title << endl;
        cout << "Author: " << books[i].author << endl;
        cout << "Publication: " << books[i].publication << endl;
        cout << "Quantity: " << books[i].quantity << endl;
        cout << "Availability: " << (books[i].isAvailable ? "Available" : "Not Available") << endl;
        cout << endl;
    }
}

void searchBook(Book books[], int size) {
    string title;
    cout << "Enter book title to search: ";
    cin >> title;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (books[i].title == title) {
            cout << "Book found!" << endl;
            cout << "Title: " << books[i].title << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "Publication: " << books[i].publication << endl;
            cout << "Quantity: " << books[i].quantity << endl;
            cout << "Availability: " << (books[i].isAvailable ? "Available" : "Not Available") << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found!" << endl;
    }
}

void borrowBook(Book books[], int size) {
    string title;
    cout << "Enter book title to borrow: ";
    cin >> title;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (books[i].title == title && books[i].isAvailable) {
            cout << "Book is available for borrowing!" << endl;
            books[i].quantity--;
            books[i].isAvailable = (books[i].quantity > 0);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book is not available for borrowing!" << endl;
    }
}

void returnBook(Book books[], int size) {
    string title;
    cout << "Enter book title to return: ";
    cin >> title;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (books[i].title == title) {
            cout << "Book returned successfully!" << endl;
            books[i].quantity++;
            books[i].isAvailable = true;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found!" << endl;
    }
}

int main() {
    const int MAX_BOOKS = 100;
    Book books[MAX_BOOKS];
    int size = 0;
    int choice;
    do {
        cout << "Library Management System" << endl;
        cout << "1. Add book" << endl;
        cout << "2. Display books" << endl;
        cout << "3. Search book" << endl;
        cout << "4. Borrow book" << endl;
        cout << "5. Return book" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addBook(books, size);
                break;
            case 2:
                displayBooks(books, size);
                break;
            case 3:
                searchBook(books, size);
                break;
            case 4:
                borrowBook(books, size);
                break;
            case 5:
                returnBook(books, size);
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
    return 0;
}
