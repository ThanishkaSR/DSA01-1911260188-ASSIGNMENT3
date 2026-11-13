#include <iostream>
#include <cstring>
using namespace std;

class Text {
    char* data;
    static int copies;

public:
    // Constructor
    Text(const char* s = "") {
        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }

    // Copy constructor
    Text(const Text& t) {
        data = new char[strlen(t.data) + 1];
        strcpy(data, t.data);
        copies++;
        cout << "Copy constructor called" << endl;
    }

    // Copy assignment operator
    Text& operator=(const Text& t) {
        if (this != &t) {
            char* temp = new char[strlen(t.data) + 1];
            strcpy(temp, t.data);

            delete[] data;
            data = temp;
        }
        return *this;
    }

    // Addition operator
    Text operator+(const Text& t) const {
        int len = strlen(data) + strlen(t.data);
        char* temp = new char[len + 1];

        strcpy(temp, data);
        strcat(temp, t.data);

        Text result(temp);
        delete[] temp;

        return result;
    }

    // Equality operator
    bool operator==(const Text& t) const {
        return strcmp(data, t.data) == 0;
    }

    // Not equal operator
    bool operator!=(const Text& t) const {
        return !(*this == t);
    }

    // Output operator
    friend ostream& operator<<(ostream& out, const Text& t) {
        out << t.data;
        return out;
    }

    // Destructor
    ~Text() {
        delete[] data;
    }

    static int getCopies() {
        return copies;
    }
};

int Text::copies = 0;

int main() {
    Text a("Hello");
    Text b(" World");
    Text c("!");

    // Concatenation
    Text result = a + b + c;
    cout << "Combined text: " << result << endl;

    // Comparison
    Text x("Hello");
    Text y("Hello");

    cout << boolalpha;
    cout << "Equal: " << (x == y) << endl;
    cout << "Not equal: " << (x != y) << endl;

    // Assignment
    Text d;
    d = a;
    cout << "Assigned text: " << d << endl;

    // Self-assignment
    d = d;
    cout << "After self-assignment: " << d << endl;

    // Empty message
    Text empty("");
    cout << "Empty message: [" << empty << "]" << endl;

    // Long message
    Text longText("This is a long SMS message for testing.");
    cout << "Long message: " << longText << endl;

    cout << "Total copies: " << Text::getCopies() << endl;

    return 0;
}


#include <iostream>
#include <string>
#include <chrono>
#include <cstring>
using namespace std;
using namespace chrono;

class Text {
    char* data;

public:
    Text(const char* s = "") {
        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }

    Text(const Text& t) {
        data = new char[strlen(t.data) + 1];
        strcpy(data, t.data);
    }

    Text& operator=(const Text& t) {
        if (this != &t) {
            char* temp = new char[strlen(t.data) + 1];
            strcpy(temp, t.data);
            delete[] data;
            data = temp;
        }
        return *this;
    }

    Text operator+(const Text& t) const {
        int len = strlen(data) + strlen(t.data);
        char* temp = new char[len + 1];

        strcpy(temp, data);
        strcat(temp, t.data);

        Text result(temp);
        delete[] temp;
        return result;
    }

    ~Text() {
        delete[] data;
    }
};

int main() {
    const int n = 100000;

    Text a("A"), b("B");
    string x = "A", y = "B";

    auto start1 = high_resolution_clock::now();

    for (int i = 0; i < n; i++)
        a = a + b;

    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();

    for (int i = 0; i < n; i++)
        x = x + y;

    auto end2 = high_resolution_clock::now();

    cout << "Text time: "
         << duration_cast<milliseconds>(end1 - start1).count()
         << " ms" << endl;

    cout << "String time: "
         << duration_cast<milliseconds>(end2 - start2).count()
         << " ms" << endl;

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main() {
    string a = "Hello";
    string b = " World";
    string c = "!";

    string result = a + b + c;

    cout << result << endl;
    return 0;
}
