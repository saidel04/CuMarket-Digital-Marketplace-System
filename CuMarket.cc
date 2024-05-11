#include "CuMarket.h"
#include <iostream>

CuMarket::CuMarket() {}

CuMarket::~CuMarket() {
    // Destructor implementation - Make sure to deallocate any dynamically allocated memory
    for (int i = 0; i < listings.getSize(); ++i) {
        delete listings[i]; // Delete each dynamically allocated Listing
    }
}

void CuMarket::addListing(const std::string& userName, const std::string& title, const cat::Category& category, const std::string& description, const Price& price) {
    if (listings.isFull()) {
        std::cout << "List is full, cannot add more listings." << std::endl;
        return;
    }
    Listing* newListing = new Listing(userName, title, category, description, price);
    listings += newListing;
}

void CuMarket::removeListing(const std::string& title) {
    for (int i = 0; i < listings.getSize(); ++i) {
        if (listings[i]->getTitle() == title) {
            delete listings[i]; // Delete the Listing object
            listings -= listings[i]; // Remove from the list
            return;
        }
    }
    std::cout << "No listing found with the title: " << title << std::endl;
}

void CuMarket::searchListings(const Filter& filter, List<Listing*>& searchList) const {
    for (int i = 0; i < listings.getSize(); ++i) {
        if (filter.matches(*listings[i])) {
            searchList += listings[i];
        }
    }
}
