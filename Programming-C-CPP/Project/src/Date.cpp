/**
 * @file Date.cpp
 *
 *  @author telmo
 *  @since 23-03-2019
 *  @version 1.0
 */

#include "../headers/Date.hpp"

#include <algorithm>
#include <regex>

/**
 * Accesses the value of the day
 *
 * @brief getter for day
 * @return day
 */
UInt Date::getDay(void) const {
    return day;
}

/**
 * Sets the day to desired value
 * Must be an unsigned integer
 *
 * @brief setter for day
 * @param value to set to
 */
void Date::setDay(UInt day) {
    this->day = day;
}

/**
 * Accesses the value of the month
 *
 * @brief getter for month
 * @return month
 */
UInt Date::getMonth(void) const {
    return month;
}

/**
 * Sets the month to desired value
 * Must be an unsigned integer
 *
 * @brief setter for month
 * @param value to set to
 */
void Date::setMonth(UInt month) {
    this->month = month;
}

/**
 * Accesses the value of the year
 *
 * @brief getter for year
 * @return year
 */
int Date::getYear(void) const {
    return year;
}

/**
 * Sets the year to desired value
 * Must be an integer
 *
 * @brief setter for year
 * @param value to set to
 */
void Date::setYear(int year) {
    this->year = year;
}

/**
 * Allows to perform a copy (assign) of a Date object
 *
 * @override assignment operator to accept Date
 * @brief copy a date to another variable
 * @param date
 * @return copy of Date object
 */
Date& Date::operator =(const Date& date) {

    if (this == &date)
        return *this;

    this->day = date.getDay();
    this->month = date.getMonth();
    this->year = date.getYear();
    return *this;
}

/**
 * Tests equality between two dates
 * Dates don't need to be the same object
 *
 * @override equality operator equal-to
 * @brief asserts equality between dates
 * @param other date object to be compared to
 * @return true if dates are equal, otherwise false
 */
bool Date::operator ==(const Date &other) const {

    if (this == &other)
        return true;

    if (this->day == other.day)
        if (this->month == other.month)
            if (this->year == other.year)
                return true;

    return false;
}

/**
 * Tests if two dates are different
 *
 * @override equality operator not-equal-to
 * @brief asserts equality between dates
 * @param other date object to be compared to
 * @return true if dates are different, otherwise true
 */
bool Date::operator !=(const Date &other) const {

    return !(*this == other);
}

/**
 * Asserts if date is greater than other
 *
 * @override relational operator: greater than
 * @brief asserts if a date is after a second date
 * @param other date object to be compared to
 * @return true if first date is greater than second date, else false
 */
bool Date::operator >(const Date &other) const {

    if (this == &other)
        return false;

    if (this->year > other.year)
        return true;

    else if (this->year == other.year) {
        if (this->month > other.month)
            return true;
        else if (this->month == other.month && this->day > other.day)
            return true;
    }

    return false;
}

/**
 * Asserts if date is less than other
 *
 * @override relational operator: less than
 * @brief asserts if a date is before a second date
 * @param other date object to be compared to
 * @return true if first date is less than second date, else false
 */
bool Date::operator <(const Date &other) const {

    if (this == &other)
        return false;

    if (this->year < other.year)
        return true;
    else if (this->year == other.year) {
        if (this->month < other.month)
            return true;
        else if (this->month == other.month && this->day < other.day)
            return true;
    }

    return false;
}

/**
 * Asserts if date is greater than or equal to other
 *
 * @override relational operator: greater than or equal to
 * @brief asserts if a date is the same or after a second date
 * @param other date object to be compared to
 * @return true if first date is greater than or equal to second date, else false
 */
bool Date::operator >=(const Date& other) const {
    return *this == other || *this > other;
}

/**
 * Asserts if date is less than or equal to other
 *
 * @override relational operator: less than or equal to
 * @brief asserts if a date is the same or before a second date
 * @param other date object to be compared to
 * @return true if first date is less than or equal to second date, else false
 */
bool Date::operator <=(const Date& other) const {
    return *this == other || *this < other;
}

/**
 * Clears a date object giving it the default values for a date
 *
 * @brief clears a Date object
 */
void Date::clear(void) {
    Date newClearDate;
    *this = newClearDate;
}

/**
 * Converts a Date object to a string using the given delimiters
 * by default the delimiter is '/'
 * The format is {year}{delimiters}{month}{delimiters}{day}
 *
 * @brief converts a date object to a string
 * @param delimiters separators for each member of date
 * @return string with formatted date delimited by the given delimiters
 */
std::string Date::to_str(std::string delimiters) const {
    return std::to_string(year) + delimiters + (month < 10 ? "0" : "") + std::to_string(month)
           + delimiters + (day < 10 ? "0" : "") + std::to_string(day);
}

/**
 * Inserts the date in a formatted way to the output stream
 * Format used for date:
 * 	{year}/{month}/{day}
 *
 * @override insertion operator to accept Date object
 * @brief inserts date to the output stream
 * @overload std::ostream& operator <<(std::ostream& stream, const Date& date)
 * @param os output stream (i.e: cout, ostringstrea, ...)
 * @param date Date object
 * @return os object
 */
std::ostream& operator <<(std::ostream& os, const Date& date) {
    os << date.year << "/" << date.month << "/" << date.day;
    return os;
}

/**
 * Allows to extract a date from an input stream
 * Each value must be separated by a space
 *
 * @override extract operator for input streams to accept Date object
 * @param is input stream containing the date
 * @param date Date object for values to be inserted to
 * @return istream object
 */
std::istream& operator >>(std::istream& is, Date& date) {
    is >> date.year >> date.month >> date.day;
    return is;
}

/**
 * Extracts a date from a string-stream
 * For reading to be successful the date in the stream must be formatted
 * {year} {month} {day}
 * No '/' separator for simplicity
 *
 * @override extractor operator to accept Date object
 * @param ss string-stream object
 * @param date Date object
 * @return ss object
 */
std::stringstream& operator >>(std::stringstream& ss, Date& date) {
    static std::regex r("(-?[0-9]+) ([0-9]+) ([0-9]+)");
    std::smatch sm;
    std::string s = ss.str();
    if(!std::regex_match (s,sm,r)) {
        //handle error
        throw 1;
    }
    unsigned m=::atoi(sm[2].str().c_str()),d=::atoi(sm[3].str().c_str());
    int y=::atoi(sm[1].str().c_str());
    //ss >> y >> m >> d;
    date.year = y;
    date.month = m;
    date.day = d;
    return ss;
}

/**
 * Given a string formatted to the exact format of an date
 * Format: {year}/{month}/{day}
 * Spaces are ignored, the slash is obligatory
 *
 * @brief reads an date from a string
 * @see Date
 * @param str string containing the date
 * @param address container for the date
 * @return 1 if process was successful, otherwise 0
 */
int readDate(const std::string &str, Date &date) {

    if (str.empty())
        return 0;

    // TODO: refactor to handle errors
    std::string copy = str;
    std::replace(copy.begin(), copy.end(), '/', ' ');
    std::stringstream ss(copy);
    ss >> date;

    return 1;
}