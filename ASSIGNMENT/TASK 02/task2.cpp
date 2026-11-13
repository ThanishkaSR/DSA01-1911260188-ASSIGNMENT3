#include <iostream>
#include <string>
using namespace std;

class Prescription {
    int n;
    string* medicines;

public:
    Prescription(int count) {
        n = count;
        medicines = new string[n];
    }

    void set(int i, string m) {
        medicines[i] = m;
    }

    void display() {
        for (int i = 0; i < n; i++)
            cout << medicines[i] << " ";
        cout << endl;
    }

    ~Prescription() {
        delete[] medicines;
    }
};

int main() {
    Prescription p(2);

    p.set(0, "Paracetamol");
    p.set(1, "ORS");

    Prescription q = p;  // Shallow copy

    q.set(1, "Cetirizine");

    cout << "Original: ";
    p.display();

    cout << "Copied: ";
    q.display();

    return 0;
}

#include <iostream>
using namespace std;

class Test {
public:
    Test() {}

    Test(const Test& t) {
        cout << "Copy constructor called" << endl;
    }
};

void passValue(Test t) {
    cout << "Passed by value" << endl;
}

void passReference(const Test& t) {
    cout << "Passed by const reference" << endl;
}

int main() {
    Test a;

    passValue(a);
    passReference(a);

    return 0;
}

#include <iostream>
#include <string>
#include <chrono>
using namespace std;
using namespace chrono;

class Prescription {
    int n;
    string* medicines;

public:
    Prescription(int count) {
        n = count;
        medicines = new string[n];
    }

    Prescription(const Prescription& p) {
        n = p.n;
        medicines = new string[n];

        for (int i = 0; i < n; i++)
            medicines[i] = p.medicines[i];
    }

    ~Prescription() {
        delete[] medicines;
    }
};

int main() {
    int sizes[] = {10, 1000, 100000};

    for (int i = 0; i < 3; i++) {
        Prescription p(sizes[i]);

        auto start = high_resolution_clock::now();

        for (int j = 0; j < 100; j++) {
            Prescription q = p;
        }

        auto stop = high_resolution_clock::now();

        auto time = duration_cast<microseconds>(stop - start);

        cout << "Medicines: " << sizes[i]
             << " Time: " << time.count()
             << " microseconds" << endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Prescription {
    vector<string> medicines;

public:
    Prescription(int n) {
        medicines.resize(n);
    }

    void set(int i, string m) {
        medicines[i] = m;
    }

    string get(int i) {
        return medicines[i];
    }
};

int main() {
    Prescription p(2);

    p.set(0, "Paracetamol");
    p.set(1, "ORS");

    Prescription q = p;

    q.set(1, "Cetirizine");

    cout << p.get(0) << " " << p.get(1) << endl;
    cout << q.get(0) << " " << q.get(1) << endl;

    return 0;
}


