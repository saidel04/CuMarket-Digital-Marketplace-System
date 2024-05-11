#ifndef Price_H
#define Price_H

#include <iostream> // Required for overloading << and >>

class Price {
public:
    Price(double value);
    Price();
    
    void print(); 
    bool inRange(const Price& min, const Price& max) const;
    double getValue() const; 

    // Overloading comparison operators
    bool operator<(const Price& p) const;
    bool operator==(const Price& p) const;

    // Overloading stream insertion and extraction operators
    friend std::ostream& operator<<(std::ostream& os, const Price& p);
    friend std::istream& operator>>(std::istream& is, Price& p);

private:
    double value;
};

#endif
