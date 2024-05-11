#include "Filter.h"

Cat_Filter::Cat_Filter(cat::Category category) : category(category) {}

bool Cat_Filter::matches(const Listing& listing) const {
    return listing.getCategory() == this->category;
}

void Cat_Filter::print(std::ostream& os) const {
    os << "Category Filter: " << cat::categoryToString(category);
}

// Price_Filter implementation
Price_Filter::Price_Filter(const Price& min, const Price& max) : min(min), max(max) {}

bool Price_Filter::matches(const Listing& listing) const {
    return listing.getPrice().inRange(this->min, this->max);
}

void Price_Filter::print(std::ostream& os) const {
    os << "Price Filter: " << this->min << " - " << this->max;
}

// PriceAndCat_Filter implementation
PriceAndCat_Filter::PriceAndCat_Filter(const Price& min, const Price& max, cat::Category category)
: Cat_Filter(category), Price_Filter(min, max) {}

bool PriceAndCat_Filter::matches(const Listing& listing) const {
    // Use both category and price range for matching
    return Cat_Filter::matches(listing) && Price_Filter::matches(listing);
}

void PriceAndCat_Filter::print(std::ostream& os) const {
    os << "Price and Category Filter: ";
    Price_Filter::print(os);
    os << ", ";
    Cat_Filter::print(os);
}

// Implement the overloaded << operator for the Filter class
std::ostream& operator<<(std::ostream& os, const Filter& filter) {
    filter.print(os);
    return os;
}
