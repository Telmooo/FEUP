/**
 * @file Menu.hpp
 *
 * @author telmo
 * @since 29/03/2019
 * @version 1.0
 */

#pragma once

#include <string>
#include <vector>

#include "Agency.hpp"
#include "Utils.hpp"

/// Text delimiter to format and beautify the text
const std::string TEXT_DELIMITER = std::string(50, '=');

/**
 * Runs the main menu allowing user to create/modify agencies
 * All data must be saved using the options given
 * All unsaved data on exit is lost
 *
 * @brief main menu for multiple agency management
 */
void runMainMenu(void);

/**
 * Runs the agency management menu, giving options to add/edit clients/travel packs
 * Data may be saved in the main menu or in the specific agency menu
 * All unsaved data is lost
 *
 * @brief specific agency management menu
 */
void runAgencyMenu(Agency &agency);

/**
 * Runs menu to edit agency information
 * Options available in menu is editing name, NIF, address, etc...
 *
 * @brief edit agency information
 * @param agency
 */
void runAgencyEditMenu(Agency &agency);

/**
 * Runs the agency menu allowing user to create/modify agency's clients
 * Data may be saved in the main menu or in the specific agency menu
 * On creating/modifying client's information, be sure to save the edits
 * All unsaved data is lost
 *
 * @brief agency's client management menu
 */
void runAgencyClientMenu(Agency &agency);

/**
 * Runs the agency menu allowing user to create/modify agency's travel packs
 * Data may be saved in the main menu or in the specific agency menu
 * On creating/modifying travel pack's information, be sure to save the edits
 * All unsaved data is lost
 *
 * @brief agency's client management menu
 */
void runAgencyPackMenu(Agency &agency);

/**
 * Validate dates
 * Date must follow the format {year}/{month}/{day}
 * Year -> any integer
 * Month -> Integer between 1 and 12 (inclusive)
 * Day -> Integer between 1 and the number of days in that month of that year
 * Spaces are ignored
 *
 * @param str container to deposit the date
 * @return whether the input was successful or not
 */
int inputDate(std::string &str);

/**
 * Validate zip-code
 * Date must follow the format {first code}-{second code}
 * Codes must be positive integers
 * Delimiter must be '-' otherwise operation fails
 * Spaces are ignored
 *
 * @param str container to deposit the zip-code
 * @return whether the input was successful or not
 */
int inputZipCode(std::string &str);

/**
 * Evaluates if the year specified is a leap year
 *
 * @brief evaluates year as leap year or common year
 * @param year value of year (can be negative or positive (must be whole number))
 * @return if year is a leap year (1-> is leap; 0-> is common)
 */
bool leapYear(int year);

/**
 * Get the number of days of specified month of the specified year, number of days varies depending
 * if the year is leap or common (this variance only applies to one month)
 *
 * @brief number of days in a month
 * @param month a number between 1-12 representing the month
 * @param year value of year (can be negative or positive (must be whole number))
 * @return number of days
 */
UInt days(UInt month, int year);

/**
 * Allows user to add/edit a client in the agency
 * For adding a new client position must be specified as -1 (or any negative number)
 * By default the value is already set to add a new client
 *
 * @brief allows user to add/edit a client in the agency
 * @param agency Agency object
 * @param at index to access client in the agency
 */
void clientMenu(Agency &agency, int at = -1);

/**
 * Allows user to add/edit a travel pack in the agency
 * For adding a new travel pack position must be specified as -1 (or any negative number)
 * By default the value is already set to add a new travel pack
 *
 * @brief allows user to add/edit a travel pack in the agency
 * @param agency Agency object
 * @param at index to access travel pack in the agency
 */
void packMenu(Agency &agency, int at = -1);

/**
 * Allows user to add/edit address of a client
 *
 * @brief menu to edit address of a client
 * @overload void addressMenu(Client &client)
 * @param client Client object to be modified
 */
void addressMenu(Client &client);

/**
 * Allows user to add/edit address of an agency
 *
 * @brief menu to edit address of a agency
 * @overload void addressMenu(Agency &agency)
 * @param agency Agency object to be modified
 */
void addressMenu(Agency &agency);

/**
 * Shows all packs, only showing the essential
 * "TravelPack {number of order}:
 * 		{Travel pack identifier}
 * 		{Travel pack destiny}
 * 		{Travel pack tickets left}"
 *
 * @brief show all available packs options in agency
 * @param agency Agency object
 * @see Agency
 * @see TravelPack::showBasic
 */
void showPacksOptions(const Agency &agency);

/**
 * Shows all clients available, only showing the essential
 * "Client {number of order}: {client's name}"
 *
 * @brief show all client options in agency
 * @param agency Agency object
 * @see Agency
 */
void showClientOptions(const Agency &agency);

/**
 * Shows all packs available, only showing the essential
 * If pack has sold out, it is ignored and not shown
 * "TravelPack {number of order}:
 * 		{Travel pack identifier}
 * 		{Travel pack destiny}
 * 		{Travel pack tickets left}"
 *
 * @brief show all available packs options in agency
 * @param agency Agency object
 * @see Agency
 * @see TravelPack::showBasic
 * @return indexes of available packs
 */
std::vector<size_t> showPacksAvailableOptions(const Agency &agency);

/**
 * If anything is still on the input buffer it gets ignored
 *
 * @brief clears std::cin input buffer
 * @see std::cin
 */
void clearInputBuffer(void);

/**
 * Asks user to input an answer to a question passed as a message
 * The only answers accepted are 'y' or 'n' (not case-sensitive)
 * If answer doesn't match, it keeps asking till user forfeits
 *
 * @brief asks user to input 'y' or 'n' (not case-sensitive)
 * @param message Message to display to user before asking
 * @return client's choice
 */
char askYesNo(const std::string &message);

/**
 * Asks user to input an answer to a question passed as a message
 * The answer can be any number in the range of signed integer
 * If any error occurs during input, choice is automatically put as -1
 *
 * @brief asks user to input his choice
 * @param message Message to display to user before asking
 * @return client's choice (-1 if error on reading)
 */
int askChoice(const std::string &message);

/**
 * Tests if an agency given already exists in the container of agencies (vector)
 * Returning true if it already exists, otherwise false
 *
 * @brief tests if vector already contains the agency given
 * @param agencies Vector of agencies containing all the agencies open
 * @param agency Agency to test if already exists if vector
 * @return if agency already exists
 */
bool containsAgency(const std::vector<Agency> &agencies, const Agency &agency);

void showStatistics(Agency &agency);

struct RetrieveKey {
    const std::string operator()(std::pair<std::string, UInt> pair) const {
        return pair.first;
    }
};
