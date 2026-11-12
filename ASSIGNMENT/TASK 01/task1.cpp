
#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    string author;
    int copies;

public:
    Book() : Book("Unknown", "Unknown", 0) {
    }

    Book(string t) : Book(t, "Unknown", 0) {
    }

    Book(string t, string a, int c)
        : title(t), author(a), copies(c >= 0 ? c : 0) {
    }

    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Copies: " << copies << endl;
        cout << endl;
    }
};

int main() {
    Book b1;
    Book b2("Harry Potter");
    Book b3("Wings of Fire", "APJ Abdul Kalam", 5);
    Book b4("C Programming", "Dennis Ritchie", -3);

    b1.display();
    b2.display();
    b3.display();
    b4.display();

    return 0;
}

*/Removing the default constructor/*

#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    Book(string t) {
        cout << t;
    }
};

int main() {
    Book b[3];
    return 0;
}


