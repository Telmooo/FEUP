/**
 * @file Date.hpp
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
#include <sstream>

/**
 * Structure capable of storing dates, with methods for comparing dates
 * and output/input of dates
 *
 * @class Date
 * @brief Structure to store dates
 */
class Date {
private:
    UInt day = 0;
    UInt month = 0;
    int year = 0;
public:
    /**
     * Accesses the value of the day
     *
     * @brief getter for day
     * @return day
     */
    UInt getDay(void) const;

    /**
     * Sets the day to desired value
     * Must be an unsigned integer
     *
     * @brief setter for day
     * @param value to set to
     */
    void setDay(UInt day);

    /**
     * Accesses the value of the month
     *
     * @brief getter for month
     * @return month
     */
    UInt getMonth(void) const;

    /**
     * Sets the month to desired value
     * Must be an unsigned integer
     *
     * @brief setter for month
     * @param value to set to
     */
    void setMonth(UInt month);

    /**
     * Accesses the value of the year
     *
     * @brief getter for year
     * @return year
     */
    int getYear(void) const;

    /**
     * Sets the year to desired value
     * Must be an integer
     *
     * @brief setter for year
     * @param value to set to
     */
    void setYear(int year);

    /**
     * Allows to perform a copy (assign) of a Date object
     *
     * @override assignment operator to accept Date
     * @brief copy a date to another variable
     * @param date
     * @return copy of Date object
     */
    Date& operator =(const Date& date);

    /**
     * Converts a Date object to a string using the given delimiters
     * by default the delimiter is '/'
     * The format is {year}{delimiters}{month}{delimiters}{day}
     *
     * @brief converts a date object to a string
     * @param delimiters separators for each member of date
     * @return string with formatted date delimited by the given delimiters
     */
    std::string to_str(std::string delimiters = "/") const;

    /**
     * Tests equality between two dates
     * Dates don't need to be the same object
     *
     * @override equality operator equal-to
     * @brief asserts equality between dates
     * @param other date object to be compared to
     * @return true if dates are equal, otherwise false
     */
    bool operator ==(const Date &other) const;

    /**
     * Tests if two dates are different
     *
     * @override inequality operator not-equal-to
     * @brief asserts inequality between dates
     * @param other date object to be compared to
     * @return true if dates are different, otherwise true
     */
    bool operator !=(const Date &other) const;

    /**
     * Asserts if date is greater than other
     *
     * @override relational operator: greater than
     * @brief asserts if a date is after a second date
     * @param other date object to be compared to
     * @return true if first date is greater than second date, else false
     */
    bool operator >(const Date &other) const;

    /**
     * Asserts if date is less than other
     *
     * @override relational operator: less than
     * @brief asserts if a date is before a second date
     * @param other date object to be compared to
     * @return true if first date is less than second date, else false
     */
    bool operator <(const Date &other) const;

    /**
     * Asserts if date is greater than or equal to other
     *
     * @override relational operator: greater than or equal to
     * @brief asserts if a date is the same or after a second date
     * @param other date object to be compared to
     * @return true if first date is greater than or equal to second date, else false
     */
    bool operator >=(const Date &other) const;

    /**
     * Asserts if date is less than or equal to other
     *
     * @override relational operator: less than or equal to
     * @brief asserts if a date is the same or before a second date
     * @param other date object to be compared to
     * @return true if first date is less than or equal to second date, else false
     */
    bool operator <=(const Date &other) const;

    /**
     * Clears a date object giving it the default values for a date
     *
     * @brief clears a Date object
     */
    void clear(void);

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
    friend std::ostream& operator <<(std::ostream& os, const Date& date);

    /**
     * Allows to extract a date from an input stream
     * Each value must be separated by a space
     *
     * @override extract operator for input streams to accept Date object
     * @param is input stream containing the date
     * @param date Date object for values to be inserted to
     * @return istream object
     */
    friend std::istream& operator >>(std::istream& is, Date& date);

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
    friend std::stringstream& operator >>(std::stringstream& ss, Date& date);
};

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
int readDate(const std::string &str, Date &date);