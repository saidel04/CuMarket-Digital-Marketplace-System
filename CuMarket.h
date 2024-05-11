#ifndef CUMARKET_H
#define CUMARKET_H

#include "List.h" 
#include "Listing.h" 
#include "Filter.h" 
#include <string>

class CuMarket {
private:
    List<Listing*> listings; 

public:
    CuMarket();
    ~CuMarket();

    void addListing(const std::string& userName, const std::string& title, const cat::Category& category, const std::string& description, const Price& price);
    void removeListing(const std::string& title);
    void searchListings(const Filter& filter, List<Listing*>& searchList) const;
};

#endif // CUMARKET_H
