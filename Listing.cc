#include "Listing.h"
#include <iomanip>

// Constructor implementation
Listing::Listing(const std::string& user, const std::string& title, cat::Category category,
                 const std::string& description, const Price& price)
    : user(user), title(title), category(category), description(description), price(price) {}

// Getters implementation
const std::string& Listing::getUser() const {
    return user;
}

const std::string& Listing::getTitle() const {
    return title;
}

const std::string& Listing::getDescription() const {
    return description;
}

cat::Category Listing::getCategory() const {
    return category;
}

const Price& Listing::getPrice() const {
    return price;
}

// Overloaded << operator for Listing
std::ostream& operator<<(std::ostream& os, const Listing& listing) {
    os << "User: " << listing.getUser() << std::endl
       << "Title: " << listing.getTitle() << std::endl
       << "Category: " << cat::categoryToString(listing.getCategory()) << std::endl
       << "Description: " << listing.getDescription() << std::endl
       << "Price: ";
    os << listing.getPrice();
    return os;
}
