#include <iostream>
#include <string>
using namespace std;

class Event {
    int rows, seats, booked;
    char** seatMap;
    string name;

public:
    // Dynamic constructor
    Event(string n, int r, int s)
        : rows(r), seats(s), booked(0), seatMap(nullptr), name(n) {

        cout << "Event created: " << name << endl;

        if (rows > 0 && seats > 0) {
            seatMap = new char*[rows];

            for (int i = 0; i < rows; i++) {
                seatMap[i] = new char[seats];

                for (int j = 0; j < seats; j++)
                    seatMap[i][j] = 'O';
            }
        }
    }

    // Book a seat
    void bookSeat(int r, int s) {
        if (r >= 0 && r < rows && s >= 0 && s < seats
            && seatMap[r][s] == 'O') {
            seatMap[r][s] = 'X';
            booked++;
            cout << "Seat booked" << endl;
        }
        else {
            cout << "Invalid or occupied seat" << endl;
        }
    }

    // Cancel a seat
    void cancelSeat(int r, int s) {
        if (r >= 0 && r < rows && s >= 0 && s < seats
            && seatMap[r][s] == 'X') {
            seatMap[r][s] = 'O';
            booked--;
            cout << "Booking cancelled" << endl;
        }
        else {
            cout << "Seat is not booked" << endl;
        }
    }

    // Destructor
    ~Event() {
        if (seatMap != nullptr) {
            for (int i = 0; i < rows; i++)
                delete[] seatMap[i];

            delete[] seatMap;
        }

        cout << "Event closed: " << name << endl;
        cout << "Total booked seats: " << booked << endl;
    }
};

int main() {

    // Stack object
    Event e1("College Event", 2, 3);

    e1.bookSeat(0, 1);
    e1.bookSeat(1, 2);
    e1.cancelSeat(0, 1);

    // Heap object
    Event* e2 = new Event("Music Event", 3, 4);

    e2->bookSeat(1, 1);
    delete e2;

    // Block scope object
    {
        Event e3("Dance Event", 2, 2);
        e3.bookSeat(0, 0);
    }

    // Zero-row event
    Event e4("Empty Event", 0, 5);

    return 0;
}



#include <iostream>
#include <string>
using namespace std;

struct Logger {
    string n;

    Logger(const string& s) : n(s) {
        cout << '+' << n << ' ';
    }

    Logger(const Logger& o) : n(o.n + "c") {
        cout << "copy" << n << ' ';
    }

    ~Logger() {
        cout << '-' << n << ' ';
    }
};

void use(Logger) {
    cout << "use ";
}

int main() {
    Logger a("A");

    {
        Logger b("B");
    }

    use(a);

    Logger* p = new Logger("P");

    delete p;

    cout << "end ";
}

