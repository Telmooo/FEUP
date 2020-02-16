/**
 * @file TravelPack.hpp
 *
 * @author telmo
 * @since 23-03-2019
 * @version 1.0
 */

#pragma once

#include "Utils.hpp"
#include "Date.hpp"

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

class TravelPack {
private:
    int identifier = 0;
    /// main touristic destiny
    std::string destiny = "";
    std::vector<std::string> places = { };
    Date begin;
    Date end;
    UInt price = 0;
    UInt maxPeople = 0;
    UInt sold = 0;

public:
    /**
     * Accesses the travel pack begin date
     *
     * @brief getter for travel pack begin date
     * @return begin
     */
    const Date& getBegin(void) const;

    /**
     * Defines the travel pack begin date
     *
     * @brief setter for travel pack begin date
     * @param begin date to be defined to
     */
    void setBegin(const Date& begin);

    /**
     * Accesses the travel pack end date
     *
     * @brief getter for travel pack end date
     * @return end
     */
    const Date& getEnd(void) const;

    /**
     * Defines the travel pack end date
     *
     * @brief setter for travel pack end date
     * @param end date to be defined to
     */
    void setEnd(const Date& end);

    /**
     * Accesses the travel pack unique identifier
     *
     * @brief getter for travel pack unique identifier
     * @return identifier
     */
    int getIdentifier(void) const;

    /**
     * Defines the travel pack unique identifier
     *
     * @brief setter for travel pack unique identifier
     * @param identifier unique identifier to be defined to
     */
    void setIdentifier(int identifier);

    /**
     * Accesses the travel pack max number of people
     *
     * @brief getter for travel pack max number of people
     * @return maxPeople
     */
    UInt getMaxPeople(void) const;

    /**
     * Defines the travel pack max number of people
     *
     * @brief setter for travel max number of people
     * @param maxPeople max number of people to be defined to
     */
    void setMaxPeople(UInt maxPeople);

    /**
     * Gets the value of tickets sold for this travel pack
     *
     * @brief getter for number of tickets sold
     * @return number of tickets sold
     */
    UInt getSold(void) const;

    /**
     * Sets the number of tickets sold to the specified value given
     *
     * @brief setter for the number of tickets sold for the travel pack
     * @param sold number to be set to
     */
    void setSold(UInt sold);

    /**
     * @brief getter for main destiny of travel pack
     * @return destiny
     */
    const std::string& getDestiny(void) const;

    /**
     * Defines the main destiny of the travel pack to the value given
     *
     * @brief setter for the main destiny of travel pack
     * @param destiny Destiny to be set to
     */
    void setDestiny(const std::string &destiny);

    /**
     * Accesses the travel pack places that will be visited
     * during the trip
     *
     * @brief getter for travel pack places to be visited
     * @return places
     */
    const std::vector<std::string>& getPlaces(void) const;

    /**
     * Defines the travel pack places to be visited
     *
     * @brief setter for travel pack places to be visited
     * @param places all places that will be visited
     */
    void setPlaces(const std::vector<std::string>& places);

    /**
     * Accesses the travel pack price
     *
     * @brief getter for travel pack price
     * @return price
     */
    UInt getPrice(void) const;

    /**
     * Defines the travel pack price
     *
     * @brief setter for travel pack price
     * @param price date to be defined to
     */
    void setPrice(UInt price);

    /**
     * Accesses the travel pack specific place that will be visited
     *
     * @brief getter for travel pack specific place
     * @param at index of place to be accessed
     * @return place accessed
     */
    const std::string& getPlace(size_t at) const;

    /**
     * Defines a specific place that will be visited on the travel pack
     *
     * @brief setter for travel pack specific place
     * @param place to be defined to
     * @param at index of place to be defined to
     */
    void setPlace(const std::string& place, size_t at);

    /**
     * Inserts a place to the end of travel pack's places to visit
     *
     * @brief pushes place to travel pack places
     * @param place to be pushed
     */
    void pushPlace(const std::string& place);

    /**
     * Creates a deep-copy of the Travel Pack object
     * Each member of the new travel pack is a copy of the original one
     *
     * @brief creates a copy of the travel pack object
     * @override assignment operator to accept Travel Pack object
     * @param pack Travel pack object to be copied
     * @return copy of the original travel pack
     */
    TravelPack& operator =(const TravelPack& pack);

    /**
     * Resets all Travel Pack information giving the default values
     *
     * @brief resets travel pack
     */
    void clear(void);

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
    bool operator ==(const TravelPack &other) const;

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
    bool operator !=(const TravelPack &other) const;

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
    void showBasic(std::string additionalChars = "") const;

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
    friend std::ostream& operator <<(std::ostream& os, const TravelPack& pack);
};

/**
 * Given a vector containing all the information about a travel pack
 *
 *
 * @brief reads travel pack from vector
 * @param v vector containing the data to be read
 * @param travel pack Travel Pack object to be used as container
 * @return 1 if operation was successful, otherwise 0
 */
int readTravelPack(const std::vector<std::string> &v, TravelPack &pack);

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
int writeTravelPack(const TravelPack &pack, std::vector<std::string> &v);
