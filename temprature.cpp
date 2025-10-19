#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

class TemperatureConverter {
public:
    static double celsiusToFahrenheit(double celsius) {
        return (celsius * 9.0 / 5.0) + 32.0;
    }

    static double fahrenheitToCelsius(double fahrenheit) {
        return (fahrenheit - 32.0) * 5.0 / 9.0;
    }

    static double celsiusToKelvin(double celsius) {
        return celsius + 273.15;
    }

    static double kelvinToCelsius(double kelvin) {
        if (kelvin < 0)
            throw invalid_argument("Kelvin cannot be negative");
        return kelvin - 273.15;
    }

    static bool nearlyEqual(double a, double b, double epsilon = 0.001) {
        return fabs(a - b) < epsilon;
    }
};

int main() {
    double c = 25.0;
    double f = TemperatureConverter::celsiusToFahrenheit(c);
    double k = TemperatureConverter::celsiusToKelvin(c);

    cout << c << "°C = " << f << "°F" << endl;
    cout << c << "°C = " << k << "K" << endl;
    cout << "Check back conversion: " 
         << TemperatureConverter::nearlyEqual(c, TemperatureConverter::fahrenheitToCelsius(f))
         << endl;

    return 0;
}
