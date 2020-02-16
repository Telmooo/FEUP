/**
 * @file Utils.cpp
 *
 *  @author telmo
 *  @since 23-03-2019
 *  @version 1.0
 */

#include "../headers/Utils.hpp"

#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iterator>
#include <sstream>

/**
 * Splits a string into substring delimited by any of the characters specified
 *
 * @brief splits string by given delimiters
 * @param container deposit for all the substrings
 * @param str string with the content to split
 * @param delimiters characters that separate each substring
 */
void split(std::vector<std::string>& container, const std::string& str, std::string delimiters) {

    if (str.empty())
        return;

    size_t pivot = str.find(delimiters);

    size_t start = 0;
    while (pivot != std::string::npos) {
        container.push_back(str.substr(start, pivot - start));
        start = pivot + delimiters.length();
        pivot = str.find(delimiters, start);
    }
    container.push_back(str.substr(start));
}

/**
 * Removes every character that is specified till the first occurrence of a character not specified
 *
 * @brief trims all specified characters on the left
 * @param str string containing the content to trim
 * @param chars characters to trim from the string
 * @return trimmed string
 */
std::string trimLeft(const std::string& str, std::string chars) {
    return str.substr(str.find_first_not_of(chars));
}

/**
 * Removes every character that is specified after the last character not specified
 *
 * @brief trims all specified characters on the right
 * @param str string containing the content to trim
 * @param chars characters to trim from the string
 * @return trimmed string
 */
std::string trimRight(const std::string& str, std::string chars) {
    return str.substr(0, str.find_last_not_of(chars) + 1);
}

/**
 * Removes all the leading and trailing characters specified
 * And normalises the string, replacing all the consecutive repeated characters
 * that are specified into a single character
 *
 * @brief trims all specified characters and normalises string
 * @param str string containing the content to trim and normalise
 * @param chars characters to trim from the string
 * @return trimmed normalised string
 */
std::string trimNorm(const std::string& str, std::string chars) {

    std::string trimmed = trimLeft(str, chars);
    trimmed = trimRight(trimmed, chars);

    size_t start = trimmed.find_first_of(chars);
    size_t end;

    while (start != std::string::npos) {
        end = trimmed.find_first_not_of(chars, start + 1);

        if (end == std::string::npos)
            break;

        trimmed.replace(start, end - start, chars);

        start = trimmed.find_first_of(chars, end);
    }
    return trimmed;
}

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
int readFile(const std::string& file, std::vector<std::string>& container) {

    std::ifstream inFile;
    inFile.open(file, std::ios::in);

    if (inFile.fail() || !inFile.is_open())
        return 0;

    std::string line;
    while (std::getline(inFile, line, '\n'))
        container.push_back(line);

    return 1;
}

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
std::string vectorToStr(const std::vector<std::string> &v, std::string delimiters) {

    if (v.empty())
        return "";

    std::string str;
    auto iter = v.begin();
    str = *iter++;
    for (; iter != v.end(); iter++)
        str += delimiters + *iter;

    return str;
}

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
std::string vectorToStr(const std::vector<int> &v, std::string delimiters) {

    if (v.empty())
        return "";

    std::string str;
    auto iter = v.begin();
    str = std::to_string(*iter++);
    for (; iter != v.end(); iter++)
        str += delimiters + std::to_string(*iter);

    return str;
}

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
int writeFile(const std::string &path, const std::vector<std::string> &content) {

    std::ofstream outFile;

    std::string tempPath = path + ".TEMP";

    outFile.open(tempPath, std::ios::out);

    for (const std::string &str : content)
        outFile << str << "\n";

    outFile.close();

    std::remove(path.c_str());

    std::rename(tempPath.c_str(), path.c_str());

    return 1;
}
