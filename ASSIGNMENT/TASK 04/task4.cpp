#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Money {
    long long paise;

public:
    Money(long long rupees = 0, int p = 0) {
        paise = rupees * 100 + p;
    }

    // Addition operator
    Money operator+(const Money& m) const {
        return Money(0, paise + m.paise);
    }

    // Subtraction operator
    Money operator-(const Money& m) const {
        return Money(0, paise - m.paise);
    }

    // Addition assignment operator
    Money& operator+=(const Money& m) {
        paise += m.paise;
        return *this;
    }

    // Equality operator
    bool operator==(const Money& m) const {
        return paise == m.paise;
    }

    // Less than operator
    bool operator<(const Money& m) const {
        return paise < m.paise;
    }

    // Output operator
    friend ostream& operator<<(ostream& out, const Money& m) {
        long long amount = m.paise;

        if (amount < 0) {
            out << "Rs -";
            amount = -amount;
        } else {
            out << "Rs ";
        }

        out << amount / 100 << "."
            << setw(2) << setfill('0') << amount % 100
            << setfill(' ');

        return out;
    }

    // Input operator
    friend istream& operator>>(istream& in, Money& m) {
        string value;
        in >> value;

        bool negative = false;

        if (value[0] == '-') {
            negative = true;
            value.erase(0, 1);
        }

        int dot = value.find('.');
        long long rupees;
        int p = 0;

        if (dot == string::npos) {
            rupees = stoll(value);
        } else {
            rupees = stoll(value.substr(0, dot));
            string fraction = value.substr(dot + 1);

            if (fraction.length() == 1)
                fraction += "0";

            p = stoi(fraction);
        }

        m.paise = rupees * 100 + p;

        if (negative)
            m.paise = -m.paise;

        return in;
    }
};

int main() {
    Money a(120, 75);
    Money b(79, 25);

    // Addition
    Money c = a + b;
    cout << c << endl;

    // Equality
    cout << boolalpha << (c == Money(200)) << endl;

    // Paise carry test
    Money x(0, 75);
    Money y(0, 50);

    cout << x + y << endl;

    // Subtraction
    Money d = Money(5, 20) - Money(7, 50);
    cout << d << endl;

    // Addition assignment
    c += Money(10, 50);
    cout << c << endl;

    // Less than comparison
    cout << (a < b) << endl;

    // Input test
    Money entered;
    cout << "Enter amount: ";
    cin >> entered;
    cout << "Entered amount: " << entered << endl;

    return 0;
}


#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main() {
    double d = 0.0;
    long long p = 0;

    auto start1 = high_resolution_clock::now();

    for (int i = 0; i < 1000000; i++)
        d += 0.01;

    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();

    for (int i = 0; i < 1000000; i++)
        p += 1;

    auto end2 = high_resolution_clock::now();

    cout << "Double result: " << d << endl;
    cout << "Money result in paise: " << p << endl;

    cout << "Double time: "
         << duration_cast<microseconds>(end1 - start1).count()
         << " microseconds" << endl;

    cout << "Integer time: "
         << duration_cast<microseconds>(end2 - start2).count()
         << " microseconds" << endl;

    return 0;
}


