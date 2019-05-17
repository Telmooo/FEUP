/**
 * @file Utils.hpp
 *
 *  @author telmo
 *  @since 23-03-2019
 *  @version 1.0
 */

#pragma once

#include <array>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief unsigned int alias
 */
typedef unsigned int UInt;

/**
 * @brief unsigned long long alias
 */
typedef unsigned long long ULLong;

/**
 * Splits a string into substring delimited by any of the characters specified
 *
 * @brief splits string by given delimiters
 * @param container deposit for all the substrings
 * @param str string with the content to split
 * @param delimiters characters that separate each substring
 */
void split(std::vector<std::string> &container, const std::string &str, std::string delimiters);

/**
 * Removes every character that is specified till the first occurrence of a character not specified
 *
 * @brief trims all specified characters on the left
 * @param str string containing the content to trim
 * @param chars characters to trim from the string
 * @return trimmed string
 */
std::string trimLeft(const std::string &str, std::string chars);

/**
 * Removes every character that is specified after the last character not specified
 *
 * @brief trims all specified characters on the right
 * @param str string containing the content to trim
 * @param chars characters to trim from the string
 * @return trimmed string
 */
std::string trimRight(const std::string &str, std::string chars);

/**
 * Removes all the leading and trailing characters specified
 * And normalises the string, replacing all the consecutives repeated characters
 * that are specified into a single character
 *
 * @brief trims all specified characters and normalises string
 * @param str string containing the content to trim and normalise
 * @param chars characters to trim from the string
 * @return trimmed normalised string
 */
std::string trimNorm(const std::string &str, std::string chars = " ");

/**
 * Reads all content from file specified by their path
 * All content stored in an already declared vector
 * Returns whether the operation was successful or not (1 if successful, otherwise 0)
 *
 * @brief reads all content from file
 * @param file path and filename for the file to read
 * @param container vector of strings to deposit the content of the file
 * @return whether operation was successful or not
 */
int readFile(const std::string &file, std::vector<std::string> &container);


/**
 * Converts a vector of strings into a string, each element is separated by
 * the given delimiters
 *
 * @brief conversion from vector to string
 * @overload std::string vectorToStr(const std::vector<std::string> &v, std::string delimiters)
 * @param v data to be converted to string
 * @param delimiters separators of each element
 * @return the resulting string
 */
std::string vectorToStr(const std::vector<std::string> &v, std::string delimiters);

/**
 * Converts a vector of integers into a string, each element is separated by
 * the given delimiters
 *
 * @brief conversion from vector to string
 * @overload std::string vectorToStr(const std::vector<int> &v, std::string delimiters)
 * @param v data to be converted to string
 * @param delimiters separators of each element
 * @return the resulting string
 */
std::string vectorToStr(const std::vector<int> &v, std::string delimiters);

/**
 * Writes a file with content stored
 * If file already exists, all data is overridden, otherwise a new file is created
 * Process of writing is crash-safe: If program closes mid process the data stored
 * in the original file (if there was one) is not lost
 *
 * Each element of the vector is considered a separate line on the file
 *
 * @brief writes content onto a file
 * @param path full path for location where writing will take place
 * @param content vector containing the content to be written
 * @return 1 if the process was successful, otherwise 0
 */
int writeFile(const std::string &path, const std::vector<std::string> &content);

template <class T>
bool vectorContains(const std::vector<T> &v, const T &element) {
    for (auto it = v.begin(); it != v.end(); it++)
        if (*it == element)
            return true;

    return false;
}