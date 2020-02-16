/**
 * @file Address.hpp
 *
 *  @author telmo
 *  @since 23-03-2019
 *  @version 1.0
 */

#pragma once

#include "Utils.hpp"

#include <array>
#include <iostream>
#include <string>
#include <vector>

/**
 * Structure capable of storing addresses
 * with methods for formatting and output address object
 *
 * @class Address
 * @brief Structure to store addresses
 */
class Address {
private:
    std::string road = "";
    UInt doorNumber = 0;
    std::string floor = "-";
    std::array<UInt, 2> zipCode = { 0, 0 };
    std::string city = "";

public:
    /**
     * Accesses the name of the city
     *
     * @brief getter for city
     * @return city
     */
    const std::string& getCity(void) const;

    /**
     * Sets the city name to desired name
     *
     * @brief setter for city
     * @param value to set to
     */
    void setCity(const std::string& city);

    /**
     * Accesses the value of the door number
     *
     * @brief getter for door number
     * @return doorNumber
     */
    UInt getDoorNumber(void) const;

    /**
     * Sets the door number to desired value
     *
     * @brief setter for doorNumber
     * @param value to set to
     */
    void setDoorNumber(UInt doorNumber);

    /**
     * Accesses the floor information
     * If floor is not specified or doesn't exist is represented as:
     * 		-> "-" <-
     *
     * @brief getter for floor
     * @return floor
     */
    const std::string& getFloor(void) const;

    /**
     * Sets the floor to the desired value
     * If floor doesn't exist or is not specified, then it is represented as:
     * 		-> "-" <-
     *
     * @brief setter for floor
     * @param value to set to
     */
    void setFloor(const std::string& floor);

    /**
     * Accesses the name of the road
     *
     * @brief getter for road
     * @return road
     */
    const std::string& getRoad(void) const;

    /**
     * Sets the road name to desired name
     *
     * @brief setter for road
     * @param value to set to
     */
    void setRoad(const std::string& road);

    /**
     * Accesses the value of the zipCode
     *
     * @brief getter for zip code
     * @return zipCode
     * @see std::array
     */
    const std::array<UInt, 2> &getZipCode(void) const;

    /**
     * Sets the zip code to the values desired
     *
     * @brief setter for zip code
     * @param values to set to
     * @see std::array
     * @overload void setZipCode(const std::array<UInt, 2>& zipCode)
     */
    void setZipCode(const std::array<UInt, 2>& zipCode);

    /**
     * Sets the zip code to the values desired
     *
     * @brief setter for zip code
     * @param a first value of zip code
     * @param b second value of zip code
     * @overload void Address::setZipCode(UInt a, UInt b)
     */
    void setZipCode(UInt a, UInt b);

    /**
     * Assigns a address to another variable
     * All the content is a copy of the original (deep copy)
     *
     * @override assignment operator to accept Address
     * @brief assigns a copy of an address to another
     * @param address original address to be copied
     * @return copy of the original address
     */
    Address& operator =(const Address &address);

    /**
     * Tests equality between two addresses
     *
     * @override equality operator equal-to
     * @brief asserts equality between addresses
     * @param other address object to be compared to
     * @return true if addresses are equal, otherwise false
     */
    bool operator ==(const Address &other) const;

    /**
     * Tests if two addresses are different
     *
     * @override inequality operator not-equal-to
     * @brief asserts inequality between addresses
     * @param other address object to be compared to
     * @return true if addresses are different, otherwise true
     */
    bool operator !=(const Address &other) const;

    /**
     * Converts the address to a string following the address format
     *
     * @brief conversion from address to string
     * @param delimiters separators for each element that composes an address
     * @see Address
     * @return address in string format
     */
    std::string to_str(std::string delimiters = " / ") const;

    /**
     * Converts the address to a string following the address format
     * and adding the @a additionalChars to the beginning of each line
     *
     * @brief converts address to string adding characters at beginning
     * @param additionalChars characters to add at the beginning
     * @return string with address formatted
     */
    std::string formatTo_str(std::string additionalChars) const;

    /**
     * Converts the zip-code to a string following the zip-code format
     *
     * @brief conversion from address to string
     * @param delimiters separators for zip-code
     * @return zip-code in string format
     */
    std::string zipCodeTo_str(std::string delimiters = "-") const;

    /**
     * Clears an address object giving it the default values for an address
     *
     * @brief clears an Address object
     */
    void clear(void);

    /**
     * Inserts the address formatted to the out stream specified
     *
     * @override insertion operator for out stream to accept Address
     * @param os out stream to which address is inserted to
     * @param address the address to be inserted
     * @return ostream object
     */
    friend std::ostream& operator <<(std::ostream& os, const Address& address);
};

/**
 * Given a string formatted to the exact format of an Address
 * Format: {road} / {door number} / {floor} / {zip-code} / {city}
 * Spaces separating the elements are optional, the slash is obligatory
 * Floor can be undefined if its value is '-'
 *
 * @brief reads an address from a string
 * @see Address
 * @param str string containing the address
 * @param address container for the address
 * @return 1 if process was successful, otherwise 0
 */
int readAddress(const std::string &str, Address &address);