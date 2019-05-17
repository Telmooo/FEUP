/**
 * @file Address.cpp
 *
 *  @author telmo
 *  @since 23-03-2019
 *  @version 1.0
 */

#include "../headers/Address.hpp"

#include <sstream>
#include <algorithm>

/**
 * Accesses the name of the city
 *
 * @brief getter for city
 * @return city
 */
const std::string& Address::getCity(void) const {
    return city;
}

/**
 * Sets the city name to desired name
 *
 * @brief setter for city
 * @param value to set to
 */
void Address::setCity(const std::string& city) {
    this->city = city;
}

/**
 * Accesses the value of the door number
 *
 * @brief getter for door number
 * @return doorNumber
 */
UInt Address::getDoorNumber(void) const {
    return doorNumber;
}

/**
 * Sets the door number to desired value
 *
 * @brief setter for doorNumber
 * @param value to set to
 */
void Address::setDoorNumber(UInt doorNumber) {
    this->doorNumber = doorNumber;
}

/**
 * Accesses the floor information
 * If floor is not specified or doesn't exist is represented as:
 * 		-> "-" <-
 *
 * @brief getter for floor
 * @return floor
 */
const std::string& Address::getFloor(void) const {
    return floor;
}

/**
 * Sets the floor to the desired value
 * If floor doesn't exist or is not specified, then it is represented as:
 * 		-> "-" <-
 *
 * @brief setter for floor
 * @param value to set to
 */
void Address::setFloor(const std::string& floor) {
    this->floor = floor;
}

/**
 * Accesses the name of the road
 *
 * @brief getter for road
 * @return road
 */
const std::string& Address::getRoad(void) const {
    return road;
}

/**
 * Sets the road name to desired name
 *
 * @brief setter for road
 * @param value to set to
 */
void Address::setRoad(const std::string& road) {
    this->road = road;
}

/**
 * Accesses the value of the zipCode
 *
 * @brief getter for zip code
 * @return zipCode
 * @see std::array
 */

const std::array<UInt, 2>& Address::getZipCode(void) const {
    return zipCode;
}

/**
 * Sets the zip code to the values desired
 *
 * @brief setter for zip code
 * @param values to set to
 * @see std::array
 * @overload void setZipCode(const std::array<UInt, 2>& zipCode)
 */
void Address::setZipCode(const std::array<UInt, 2>& zipCode) {
    this->zipCode = zipCode;
}

/**
 * Sets the zip code to the values desired
 *
 * @brief setter for zip code
 * @param a first value of zip code
 * @param b second value of zip code
 * @overload void Address::setZipCode(UInt a, UInt b)
 */
void Address::setZipCode(UInt a, UInt b) {
    this->zipCode.at(0) = a;
    this->zipCode.at(1) = b;
}

/**
 * Assigns a address to another variable
 * All the content is a copy of the original (deep copy)
 *
 * @override assignment operator to accept Address
 * @brief assigns a copy of an address to another
 * @param address original address to be copied
 * @return copy of the original address
 */
Address& Address::operator =(const Address& address) {

    if (this == &address)
        return *this;

    this->road = address.getRoad();
    this->doorNumber = address.doorNumber;
    this->floor = address.floor;
    this->zipCode = address.getZipCode();
    this->city = address.city;
    return *this;
}

/**
 * Tests equality between two addresses
 *
 * @override equality operator equal-to
 * @brief asserts equality between addresses
 * @param other address object to be compared to
 * @return true if addresses are equal, otherwise false
 */
bool Address::operator ==(const Address &other) const {

    if (this == &other)
        return true;

    if (this->road != other.road)
        return false;

    if (this->doorNumber != other.doorNumber)
        return false;

    if (this->floor != other.floor)
        return false;

    if (this->zipCode != other.zipCode)
        return false;

    if (this->city != other.city)
        return false;

    return true;
}

/**
 * Tests if two addresses are different
 *
 * @override equality operator not-equal-to
 * @brief asserts equality between addresses
 * @param other address object to be compared to
 * @return true if addresses are different, otherwise true
 */
bool Address::operator !=(const Address &other) const {
    return !(*this == other);
}

/**
 * Clears an address object giving it the default values for an address
 *
 * @brief clears an Address object
 */
void Address::clear(void) {
    Address newClearedAddress;
    *this = newClearedAddress;
}

/**
 * Converts the adress to a string following the address format
 *
 * @brief conversion from address to string
 * @param delimiters separators for each element that composes an address
 * @see Address
 * @return address in string format
 */
std::string Address::to_str(std::string delimiters) const {
    std::string str = this->road + delimiters + std::to_string(this->doorNumber) + delimiters
                      + this->floor + delimiters + zipCodeTo_str() + delimiters + this->city;

    return str;
}

/**
 * Converts the address to a string following the address format
 * and adding the @a additionalChars to the beginning of each line
 *
 * @brief converts address to string adding characters at beginning
 * @param additionalChars characters to add at the beginning
 * @return string with address formatted
 */
std::string Address::formatTo_str(std::string additionalChars) const {
    return additionalChars + "City: " + this->city + "\n" + additionalChars + "Road: " + this->road
           + "\n" + additionalChars + "Door Number: " + std::to_string(this->doorNumber) + "\n"
           + additionalChars + "Floor: " + this->floor + "\n" + additionalChars + "Zip-Code: "
           + zipCodeTo_str() + "\n";
}

/**
 * Converts the zip-code to a string following the zip-code format
 *
 * @brief conversion from address to string
 * @param delimiters separators for zip-code
 * @return zip-code in string format
 */
std::string Address::zipCodeTo_str(std::string delimiters) const {
    std::string code1 = std::to_string(this->zipCode.at(0));
    std::string code2 = std::to_string(this->zipCode.at(1));
    // FILLING ZIP-CODE
    if (code1.size() < 4)
        code1 = std::string(4 - code1.size(), '0') + code1;
    if (code1.size() < 3)
        code2 = std::string(3 - code2.size(), '0') + code2;
    return code1 + delimiters + code2;
}

/**
 * Inserts the address formatted to the out stream specified
 *
 * @override insertion operator for out stream to accept Address
 * @param os out stream to which address is inserted to
 * @param address the address to be inserted
 * @return ostream object
 */
std::ostream& operator <<(std::ostream& os, const Address& address) {
    os << "City: " << address.city << "\nRoad: " << address.road << "\nDoor Number: "
       << address.doorNumber << "\nFloor: " << address.floor << "\nZip Code: "
       << address.zipCode.at(0) << "-" << address.zipCode.at(1);
    return os;
}

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
int readAddress(const std::string &str, Address &address) {

    // TODO: refactor to handle errors

    std::vector<std::string> content;
    split(content, str, "/");

    if (content.size() == 0)
        return 0;

    address.setRoad(trimNorm(content.at(0), " "));
    address.setDoorNumber(std::stoul(content.at(1)));
    address.setFloor(trimNorm(content.at(2), " "));

    // TODO: refactor this
    {
        std::string str = content.at(3);
        std::replace(str.begin(), str.end(), '-', ' ');
        std::stringstream ss(str);
        UInt x, y;
        ss >> x >> y;
        address.setZipCode(x, y);
    }

    address.setCity(trimNorm(content.at(4), " "));

    return 1;
}