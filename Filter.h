#ifndef FILTER_H
#define FILTER_H

#include "Listing.h"
#include <iostream>

// Base Filter class
class Filter {
public:
    virtual ~Filter() {}

    // Provide a default implementation that always returns true
    virtual bool matches(const Listing& listing) const {
        return true; 
    }

    // Provide a default print implementation
    virtual void print(std::ostream& os) const {
        os << "No specific filter applied."; 
    }
};

// Derived Cat_Filter class
class Cat_Filter : public virtual Filter {
private:
    cat::Category category;
public:
    Cat_Filter(cat::Category category);
    virtual bool matches(const Listing& listing) const override;
    virtual void print(std::ostream& os) const override;
};

// Derived Price_Filter class
class Price_Filter : public virtual Filter {
private:
    Price min, max;
public:
    Price_Filter(const Price& min, const Price& max);
    virtual bool matches(const Listing& listing) const override;
    virtual void print(std::ostream& os) const override;
};

// Derived PriceAndCat_Filter class
class PriceAndCat_Filter : public Cat_Filter, public Price_Filter {
public:
    PriceAndCat_Filter(const Price& min, const Price& max, cat::Category category);
    virtual bool matches(const Listing& listing) const override;
    virtual void print(std::ostream& os) const override;
};

// Overload operator<< for the base Filter class
std::ostream& operator<<(std::ostream& os, const Filter& filter);

// A simple filter that matches any listing
class NoFilter : public Filter {
public:
    virtual bool matches(const Listing& listing) const override {
        return true; // Matches any listing
    }
    virtual void print(std::ostream& os) const override {
        os << "No specific filter applied."; // Basic print implementation
    }
};


#endif // FILTER_H
