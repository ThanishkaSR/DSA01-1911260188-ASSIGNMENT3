#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>
using namespace std;

class Complex {
    double real, imag;

public:
    // Default constructor
    Complex() {
        real = 0;
        imag = 0;
    }

    // Constructor with real part
    Complex(double r) {
        real = r;
        imag = 0;
    }

    // Constructor with real and imaginary parts
    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    // Addition
    Complex operator+(Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }

    // Subtraction
    Complex operator-(Complex c) {
        return Complex(real - c.real, imag - c.imag);
    }

    // Multiplication
    Complex operator*(Complex c) {
        return Complex(real * c.real - imag * c.imag,
                       real * c.imag + imag * c.real);
    }

    // Division
    Complex operator/(Complex c) {
        double denominator = c.real * c.real + c.imag * c.imag;

        if (denominator == 0) {
            throw runtime_error("Division by zero impedance!");
        }

        return Complex((real * c.real + imag * c.imag) / denominator,
                       (imag * c.real - real * c.imag) / denominator);
    }

    // Equality
    bool operator==(Complex c) {
        return fabs(real - c.real) < 0.000001 &&
               fabs(imag - c.imag) < 0.000001;
    }

    // Magnitude
    double magnitude() {
        return sqrt(real * real + imag * imag);
    }

    // Display
    friend ostream& operator<<(ostream& out, Complex c) {
        out << c.real;

        if (c.imag >= 0)
            out << " + j" << c.imag;
        else
            out << " - j" << fabs(c.imag);

        return out;
    }
};

int main() {
    const double pi = 3.141592653589793;
    double frequency = 50;
    double R = 10;
    double L = 0.1;
    double C = 0.0001;

    double w = 2 * pi * frequency;

    Complex resistor(R, 0);
    Complex inductor(0, w * L);
    Complex capacitor(0, -1 / (w * C));

    // Series RLC impedance
    Complex series = resistor + inductor + capacitor;

    // Parallel RLC impedance
    Complex parallel = (resistor * inductor) /
                       (resistor + inductor);

    parallel = (parallel * capacitor) /
               (parallel + capacitor);

    cout << fixed << setprecision(4);

    cout << "Resistor: " << resistor << endl;
    cout << "Inductor: " << inductor << endl;
    cout << "Capacitor: " << capacitor << endl;

    cout << "\nSeries impedance: " << series << endl;
    cout << "Series magnitude: " << series.magnitude() << endl;

    cout << "\nParallel impedance: " << parallel << endl;
    cout << "Parallel magnitude: " << parallel.magnitude() << endl;

    // Testing equality
    Complex a(10, 5);
    Complex b(10, 5);

    cout << "\nEquality: " << boolalpha << (a == b) << endl;

    // Testing division by zero
    try {
        Complex zero(0, 0);
        Complex result = a / zero;
        cout << result << endl;
    }
    catch (runtime_error e) {
        cout << "\nError: " << e.what() << endl;
    }

    return 0;
}




#include <iostream>
#include <complex>
using namespace std;

int main() {
    complex<double> a(10, 5);
    complex<double> b(4, 2);

    complex<double> sum = a + b;
    complex<double> product = a * b;

    cout << "Addition: " << sum << endl;
    cout << "Multiplication: " << product << endl;

    return 0;
}


#include <iostream>
#include <complex>
using namespace std;

int main() {
    complex<double> a(10, 5);
    complex<double> b(4, 2);

    complex<double> sum = a + b;
    complex<double> product = a * b;

    cout << "Addition: " << sum << endl;
    cout << "Multiplication: " << product << endl;

    return 0;
}


