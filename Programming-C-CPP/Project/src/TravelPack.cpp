/**
 * @file TravelPack.cpp
 *
 * @author telmo
 * @since 23-03-2019
 * @version 1.0
 */

#include "../headers/TravelPack.hpp"

#include <cstdlib>
#include <iostream>

/**
 * Accesses the travel pack begin date
 *
 * @brief getter for travel pack begin date
 * @return begin
 */
const Date& TravelPack::getBegin(void) const {
    return begin;
}

/**
 * Defines the travel pack begin date
 *
 * @brief setter for travel pack begin date
 * @param begin date to be defined to
 */
void TravelPack::setBegin(const Date& begin) {
    this->begin = begin;
}

/**
 * Accesses the travel pack end date
 *
 * @brief getter for travel pack end date
 * @return end
 */
const Date& TravelPack::getEnd(void) const {
    return end;
}

/**
 * Defines the travel pack end date
 *
 * @brief setter for travel pack end date
 * @param end date to be defined to
 */
void TravelPack::setEnd(const Date& end) {
    this->end = end;
}

/**
 * Accesses the travel pack unique identifier
 *
 * @brief getter for travel pack unique identifier
 * @return identifier
 */
int TravelPack::getIdentifier(void) const {
    return identifier;
}

/**
 * Defines the travel pack unique identifier
 *
 * @brief setter for travel pack unique identifier
 * @param identifier unique identifier to be defined to
 */
void TravelPack::setIdentifier(int identifier) {
    this->identifier = identifier;
}

/**
 * Accesses the travel pack max number of people
 *
 * @brief getter for travel pack max number of people
 * @return maxPeople
 */
UInt TravelPack::getMaxPeople(void) const {
    return maxPeople;
}

/**
 * Defines the travel pack max number of people
 *
 * @brief setter for travel max number of people
 * @param maxPeople max number of people to be defined to
 */
void TravelPack::setMaxPeople(UInt maxPeople) {
    this->maxPeople = maxPeople;
    if (maxPeople <= sold && identifier > 0) {
        identifier = -identifier;
    }
}

/**
 * Gets the value of tickets sold for this travel pack
 *
 * @brief getter for number of tickets sold
 * @return number of tickets sold
 */
UInt TravelPack::getSold(void) const {
    return sold;
}

/**
 * Sets the number of tickets sold to the specified value given
 *
 * @brief setter for the number of tickets sold for the travel pack
 * @param sold number to be set to
 */
void TravelPack::setSold(UInt sold) {
    this->sold = sold;
    if (maxPeople <= sold && identifier > 0) {
        identifier = -identifier;
    }
}

/**
 * @brief getter for main destiny of travel pack
 * @return destiny
 */
const std::string& TravelPack::getDestiny(void) const {
    return destiny;
}

/**
 * Defines the main destiny of the travel pack to the value given
 *
 * @brief setter for the main destiny of travel pack
 * @param destiny Destiny to be set to
 */
void TravelPack::setDestiny(const std::string &destiny) {
    this->destiny = destiny;
}

/**
 * Accesses the travel pack places that will be visited
 * during the trip
 *
 * @brief getter for travel pack places to be visited
 * @return places
 */
const std::vector<std::string>& TravelPack::getPlaces(void) const {
    return places;
}

/**
 * Defines the travel pack places to be visited
 *
 * @brief setter for travel pack places to be visited
 * @param places all places that will be visited
 */
void TravelPack::setPlaces(const std::vector<std::string>& places) {
    this->places = places;
}

/**
 * Accesses the travel pack price
 *
 * @brief getter for travel pack price
 * @return price
 */
UInt TravelPack::getPrice(void) const {
    return price;
}

/**
 * Defines the travel pack price
 *
 * @brief setter for travel pack price
 * @param price date to be defined to
 */
void TravelPack::setPrice(UInt price) {
    this->price = price;
}

/**
 * Accesses the travel pack specific place that will be visited
 *
 * @brief getter for travel pack specific place
 * @param at index of place to be accessed
 * @return place accessed
 */
const std::string& TravelPack::getPlace(size_t at) const {
    return places.at(at);
}

/**
 * Defines a specific place that will be visited on the travel pack
 *
 * @brief setter for travel pack specific place
 * @param place to be defined to
 * @param at index of place to be defined to
 */
void TravelPack::setPlace(const std::string &place, size_t at) {
    this->places.at(at) = place;
}

/**
 * Inserts a place to the end of travel pack's places to visit
 *
 * @brief pushes place to travel pack places
 * @param place to be pushed
 */
void TravelPack::pushPlace(const std::string &place) {
    places.push_back(place);
}

/**
 * Creates a deep-copy of the Travel Pack object
 * Each member of the new travel pack is a copy of the original one
 *
 * @brief creates a copy of the travel pack object
 * @override assignment operator to accept Travel Pack object
 * @param pack Travel pack object to be copied
 * @return copy of the original travel pack
 */
TravelPack& TravelPack::operator =(const TravelPack& pack) {

    if (this == &pack)
        return *this;

    this->identifier = pack.getIdentifier();
    this->destiny = pack.getDestiny();
    this->places = pack.getPlaces();
    this->begin = pack.getBegin();
    this->end = pack.getEnd();
    this->price = pack.getPrice();
    this->maxPeople = pack.getMaxPeople();
    this->sold = pack.getSold();
    return *this;
}

/**
 * Tests equality between two travel packs
 * Travel packs don't need to be totally equal
 * An equal identifier is sufficient
 *
 * @override equality operator equal-to
 * @brief asserts equality between travel packs
 * @param other travel pack object to be compared to
 * @return true if travel packs are equal, otherwise false
 */
bool TravelPack::operator ==(const TravelPack &other) const {

    if (this == &other)
        return true;

    if (std::abs(this->identifier) != std::abs(other.identifier))
        return false;

    return true;
}

/**
 * Tests if two travel packs are different
 * Clients don't need to be totally different
 * Just a different identifier  is sufficient
 *
 * @override equality operator not-equal-to
 * @brief asserts inequality between travel packs
 * @param other Travel Pack object to be compared to
 * @return true if travel packs are different, otherwise true
 */
bool TravelPack::operator !=(const TravelPack &other) const {
    return !(*this == other);
}

/**
 * Resets all Travel Pack information giving the default values
 *
 * @brief resets travel pack
 */
void TravelPack::clear(void) {
    TravelPack newClearedTravelPack;
    *this = newClearedTravelPack;
}

/**
 * Shows only the basic information about a travel pack
 * That includes:
 * 	{identifier}
 * 	{destiny}
 * 	{tickets left}
 *
 * @brief shows travel pack basic information
 * @param additionalChars additional characters to add at the beggining of each line
 */
void TravelPack::showBasic(std::string additionalChars) const {
    std::cout << additionalChars << "Identifier: " << this->identifier << "\n" << additionalChars
              << "Destiny: " << this->destiny << "\n" << additionalChars << "Places: " << vectorToStr(this->places, ", ") << additionalChars << "\nsBegin Date: " << this->begin << "\n" << additionalChars
              << "Tickets left: " << this->maxPeople - this->sold << "\n\n";
}

/**
 * Inserts the Travel Pack in a formatted way to the output stream
 * Format used for Travel Pack:
 * 	{identifier}
 * 	{destiny}
 * 	{begin date}
 * 	{end date}
 * 	{max capacity}
 * 	{tickets sold}
 * 	{tickets left}
 *
 * @override insertion operator to accept Travel Pack object
 * @brief inserts travel pack to the output stream
 * @param os output stream (i.e: cout, ostringstream, ...)
 * @param pack Travel Pack object
 * @return os object
 */
std::ostream& operator <<(std::ostream& os, const TravelPack& pack) {
    os << "Identifier: " << pack.identifier << "\nDestiny: " << pack.getDestiny() << "\nPlaces: "
       << vectorToStr(pack.getPlaces(), ", ") << "\nBegin Date: " << pack.begin
       << "\nEnd Date: " << pack.end << "\nPrice: " << pack.price << "\nMax Capacity: "
       << pack.maxPeople << "\nSold: " << pack.sold << "\nLeft: " << pack.maxPeople - pack.sold
       << "\n";
    return os;
}

/**
 * Given a vector containing all the information about a travel pack
 *
 *
 * @brief reads travel pack from vector
 * @param v vector containing the data to be read
 * @param travel pack Travel Pack object to be used as container
 * @return 1 if operation was successful, otherwise 0
 */
int readTravelPack(const std::vector<std::string> &v, TravelPack &pack) {

    if (v.size() != 7)
        return 0;

    pack.setIdentifier(std::stoi(v.at(0)));

    std::vector<std::string> destiny, places;
    split(destiny, v.at(1), "-");
    if (destiny.size() > 1) {
        split(places, destiny.at(1), ",");
        for (std::string &place : places)
            place = trimNorm(place, " ");

        pack.setPlaces(places);
    }
    if (destiny.size())
        pack.setDestiny(trimNorm(destiny.at(0), " "));

    Date start, end;
    readDate(v.at(2), start);
    readDate(v.at(3), end);

    pack.setBegin(start);
    pack.setEnd(end);

    pack.setPrice(std::stoul(v.at(4)));

    pack.setMaxPeople(std::stoul(v.at(5)));

    pack.setSold(std::stoul(v.at(6)));

    return 1;
}

/**
 * Writes all travel pack information to a vector
 * Each element of the vector has a line corresponding to the formatted information
 * on the file
 *
 * @brief write travel pack to vector (formatted)
 * @param pack Travel Pack object
 * @param v container for all information about the travel pack
 * @return if operation was successful
 */
int writeTravelPack(const TravelPack &pack, std::vector<std::string> &v) {

    v.push_back(std::to_string(pack.getIdentifier()));

    std::string places = pack.getDestiny();
    if (pack.getPlaces().size())
        places += " - " + vectorToStr(pack.getPlaces(), ", ");
    v.push_back(places);

    v.push_back(pack.getBegin().to_str());

    v.push_back(pack.getEnd().to_str());

    v.push_back(std::to_string(pack.getPrice()));

    v.push_back(std::to_string(pack.getMaxPeople()));

    v.push_back(std::to_string(pack.getSold()));

    return 1;
}
