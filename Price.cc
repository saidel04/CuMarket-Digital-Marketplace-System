#include "Price.h"
#include <iostream>
#include <iomanip>
#include <sstream> 

using namespace std;

Price::Price(double value) : value(value) {}

Price::Price() : value(0.0) {}

double Price::getValue() const {
    return value;
}

void Price::print() {
    cout << fixed << setprecision(2) << "$" << value << endl;
}

bool Price::inRange(const Price& min, const Price& max) const {
    return value >= min.getValue() && value <= max.getValue();
}


// Implementing overloaded operators
bool Price::operator<(const Price& p) const {
    return value < p.value;
}

bool Price::operator==(const Price& p) const {
    return value == p.value;
}

ostream& operator<<(ostream& os, const Price& p) {
    os << fixed << setprecision(2) << "$" << p.value;
    return os;
}

istream& operator>>(istream& is, Price& p) {
    string input;
    is >> input; 

    // Remove dollar sign if present
    if (input[0] == '$') {
        input.erase(0, 1);
    }

    // Convert to double and set value
    stringstream(input) >> p.value;
    return is;
}
