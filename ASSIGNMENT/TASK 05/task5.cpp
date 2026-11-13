#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class Time {
    int hours, minutes, seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) {
        hours = h;
        minutes = m;
        seconds = s;

        int total = hours * 3600 + minutes * 60 + seconds;
        hours = total / 3600;
        minutes = (total % 3600) / 60;
        seconds = total % 60;
    }

    // Prefix increment
    Time& operator++() {
        seconds++;

        if (seconds == 60) {
            seconds = 0;
            minutes++;
        }

        if (minutes == 60) {
            minutes = 0;
            hours++;
        }

        return *this;
    }

    // Postfix increment
    Time operator++(int) {
        Time old = *this;
        ++(*this);
        return old;
    }

    // Equality operator
    bool operator==(const Time& t) const {
        return hours == t.hours &&
               minutes == t.minutes &&
               seconds == t.seconds;
    }

    // Less than operator
    bool operator<(const Time& t) const {
        if (hours != t.hours)
            return hours < t.hours;

        if (minutes != t.minutes)
            return minutes < t.minutes;

        return seconds < t.seconds;
    }

    void display() const {
        cout << hours << ":"
             << (minutes < 10 ? "0" : "") << minutes << ":"
             << (seconds < 10 ? "0" : "") << seconds << endl;
    }
};

class Playlist {
    vector<string> tracks;

public:
    Playlist(vector<string> t) {
        tracks = t;
    }

    // Non-const subscript operator
    string& operator[](int i) {
        if (i < 0 || i >= (int)tracks.size())
            throw out_of_range("Invalid playlist index");

        return tracks[i];
    }

    // Const subscript operator
    const string& operator[](int i) const {
        if (i < 0 || i >= (int)tracks.size())
            throw out_of_range("Invalid playlist index");

        return tracks[i];
    }

    int size() const {
        return tracks.size();
    }
};

int main() {

    // Time increment test
    Time t(0, 0, 5);

    Time a = t++;
    Time b = ++t;

    cout << "a = ";
    a.display();

    cout << "b = ";
    b.display();

    cout << "Current time = ";
    t.display();

    // Comparison test
    Time x(1, 0, 0);
    Time y(1, 0, 5);

    cout << boolalpha;
    cout << "Equal: " << (x == y) << endl;
    cout << "Less than: " << (x < y) << endl;

    // Playlist test
    Playlist p({"Song A", "Song B", "Song C"});

    cout << "Playing: " << p[0] << endl;
    cout << "Playing: " << p[1] << endl;

    // Modify playlist
    p[1] = "New Song";
    cout << "Updated track: " << p[1] << endl;

    // Invalid index tests
    try {
        cout << p[-1] << endl;
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    try {
        cout << p[p.size()] << endl;
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    // Minute and hour rollover
    Time rollover(0, 59, 59);
    ++rollover;

    cout << "After rollover: ";
    rollover.display();

    return 0;
}



#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

class Counter {
    long long value;

public:
    Counter() : value(0) {}

    Counter& operator++() {
        ++value;
        return *this;
    }

    Counter operator++(int) {
        Counter old = *this;
        ++value;
        return old;
    }

    long long get() const {
        return value;
    }
};

int main() {
    const int n = 10000000;

    Counter a, b;

    auto start1 = high_resolution_clock::now();

    for (int i = 0; i < n; i++)
        ++a;

    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();

    for (int i = 0; i < n; i++)
        b++;

    auto end2 = high_resolution_clock::now();

    cout << "Prefix time: "
         << duration_cast<microseconds>(end1 - start1).count()
         << " microseconds" << endl;

    cout << "Postfix time: "
         << duration_cast<microseconds>(end2 - start2).count()
         << " microseconds" << endl;

    cout << "Prefix value: " << a.get() << endl;
    cout << "Postfix value: " << b.get() << endl;

    return 0;
}

#include <iostream>

struct Counter {
    int v;

    Counter& operator++() {
        ++v;
        return *this;
    }

    Counter operator++(int) {
        Counter old = *this;
        ++v;
        return old;
    }
};

int main() {
    Counter c{5};

    Counter a = c++;
    Counter b = ++c;

    std::cout << a.v << ' '
              << b.v << ' '
              << c.v << '\n';
}
