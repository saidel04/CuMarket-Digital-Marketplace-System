#ifndef LISTING_H
#define LISTING_H

#include "Price.h"
#include "Category.h"
#include <string>
#include <iostream>

#include "Category.h"

using cat::computers;
using cat::cars;
using cat::books;
using cat::music;
using cat::clothing;
using cat::furniture;
using cat::misc;

class Listing {
private:
    std::string user;
    std::string title;
    std::string description;
    cat::Category category;
    Price price;

public:
    // Constructor
    Listing(const std::string& user, const std::string& title, cat::Category category,
            const std::string& description, const Price& price);

    // Getter functions for the private members
    const std::string& getUser() const;
    const std::string& getTitle() const;
    const std::string& getDescription() const;
    cat::Category getCategory() const;
    const Price& getPrice() const;

    // Overloaded << operator for easy printing
    friend std::ostream& operator<<(std::ostream& os, const Listing& listing);
};

#endif // LISTING_H
