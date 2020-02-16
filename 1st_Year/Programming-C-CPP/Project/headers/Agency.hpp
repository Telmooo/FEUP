/**
 * @file Agency.hpp
 *
 * @author telmo
 * @since 23-03-2019
 * @version 1.0
 */

#pragma once

#include <array>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

#include "Client.hpp"
#include "TravelPack.hpp"
#include "Utils.hpp"
#include "Date.hpp"
#include "Address.hpp"

/**
 * Agency has all values default to null
 * Null -> 0, {}, ... (depending on the type)
 * Except the updated flag which is by default set as 1 (true)
 *
 * @brief container for an Agency
 * @class Agency
 */
class Agency {
private:
    /// path for the file containing all the information about the agency
    std::string path = "";
    std::string name = "";
    ULLong nif = 0;
    Address address;
    std::string website = "";
    /// path for the file containing all the information about the agency's travel packs
    std::string packsFile = "";
    std::vector<TravelPack> packs = { };
    int lastUpdatedPack = 0;
    /// path for the file containing all the information about the agency's clients
    std::string clientsFile = "";
    std::vector<Client> clients = { };
    /// whether there was changes since last save
    bool updated = true;

    std::map<std::string, UInt> visitedPlaces = { };

public:
    /**
     * Access value of path of agency file
     *
     * @brief getter for path
     * @return path for the agency file
     */
    const std::string getPath(void) const;

    /**
     * Sets the path for the agency file
     *
     * @brief setter for path
     * @param str path to be set to
     */
    void setPath(const std::string &str);

    /**
     * Accesses the address of the agency
     *
     * @brief getter for the agency's address
     * @return address
     */
    const Address& getAddress(void) const;

    /**
     * Defines the address of the agency
     *
     * @brief setter for address of agency
     * @param address to be defined to
     */
    void setAddress(const Address& address);

    /**
     * Accesses the clients of the agency
     *
     * @brief getter for the agency's clients
     * @return clients
     */
    const std::vector<Client>& getClients(void) const;

    /**
     * Defines all the clients of the agency
     *
     * @brief setter for all the clients of the agency
     * @param clients to be defined to
     */
    void setClients(const std::vector<Client>& clients);

    /**
     * Accesses the path for the file containing all the clients
     * of the agency
     *
     * @brief getter for the agency's clients file
     * @return clientsFile
     */
    const std::string& getClientsFile(void) const;

    /**
     * Defines the new path for file of the clients of the agency
     *
     * @brief setter for path of the clients file of agency
     * @param path to be defined to
     */
    void setClientsFile(const std::string& clientsFile);

    /**
     * Accesses the name of the agency
     *
     * @brief getter for the agency's name
     * @return name
     */
    const std::string& getName(void) const;

    /**
     * Defines the name of the agency
     *
     * @brief setter for name of agency
     * @param name to be defined to
     */
    void setName(const std::string& name);

    /**
     * Accesses the NIF of the agency
     *
     * @brief getter for the agency's NIF
     * @return nif
     */
    ULLong getNif(void) const;

    /**
     * Defines the NIF of the agency
     *
     * @brief setter for NIF of agency
     * @param nif to be defined to
     */
    void setNif(ULLong nif);

    /**
     * Accesses all the travel packs of the agency
     *
     * @brief getter for the agency's travel packs
     * @return packs
     */
    const std::vector<TravelPack>& getPacks(void) const;

    /**
     * Defines all the travel packs of the agency
     *
     * @brief setter for travel packs of agency
     * @param packs to be defined to
     */
    void setPacks(const std::vector<TravelPack>& packs);

    /**
     * Accesses the path for the file containing all the travel packs
     * of the agency
     *
     * @brief getter for the agency's travel packs file
     * @return packsFile
     */
    const std::string& getPacksFile(void) const;

    /**
     * Defines the new path for file of the travel packs of the agency
     *
     * @brief setter for path of the travel packs file of agency
     * @param path to be defined to
     */
    void setPacksFile(const std::string& packsFile);

    /**
     * Access value of last updated pack identifier
     *
     * @brief getter for value of last updated pack identifier
     * @return last updated pack identifier of the agency
     */
    int getLastUpdatedPack(void) const;

    /**
     * Sets the last updated pack to the identifier of last updated pack
     *
     * @brief setter last updated pack identifier
     * @param identifier of last updated pack
     */
    void setLastUpdatedPack(int identifier);

    /**
     /**
     * Accesses the website link of the agency
     *
     * @brief getter for the agency's website
     * @return website
     */
    const std::string& getWebsite(void) const;

    /**
     * Defines the website of the agency
     *
     * @brief setter for website of agency
     * @param website to be defined to
     */
    void setWebsite(const std::string& website);

    /**
     * Accesses the specific client in the position specified in the vector
     *
     * @brief getter for specific client
     * @param at index of the client to be accessed
     * @return client accessed
     */
    const Client& getClient(size_t at) const;

    /**
     * Defines a specific client at the specified position
     *
     * @brief setter for specific client
     * @param client to be defined to
     * @param at index of client to be defined in vector
     */
    void setClient(const Client& client, size_t at);

    /**
     * Inserts a client to the end of agency's clients
     *
     * @brief pushes a client to agency
     * @param client Client to be pushed
     */
    void pushClient(const Client& client);

    /**
     * Accesses the specific pack in the position specified in the vector
     *
     * @brief getter for specific pack
     * @param at index of the pack to be accessed
     * @return pack accessed
     */
    const TravelPack& getPack(size_t at) const;

    /**
     * Defines a specific pack at the specified position
     *
     * @brief setter for specific pack
     * @param pack to be defined to
     * @param at index of pack to be defined in vector
     */
    void setPack(const TravelPack& pack, size_t at);

    const std::map<std::string, UInt>& getVisitedPlaces() const;

    void updateVisitedPlaces(void);

    /**
     * Inserts a pack to the end of agency's travel packs
     *
     * @brief pushes a travel pack to agency
     * @param pack to be pushed
     */
    void pushPack(const TravelPack& pack);

    /**
     * Access value of update status of agency
     *
     * @brief getter for update status
     * @return update status of agency
     */
    bool upToDate(void) const;

    /**
     * Sets agency to updated or not updated
     * If updated -> set to true
     * Else -> set to false
     *
     * @brief setter updated status of agency
     * @param updated state to be set to
     */
    void setUpdated(bool updated = true);

    /**
     * Creates a deep-copy of the agency object
     * Each member of the new agency is a copy of the original one
     *
     * @brief creates a copy of the agency object
     * @override assignment operator to accept Agency object
     * @param agency Agency object to be copied
     * @return copy of the original Agency
     */
    Agency& operator =(const Agency &agency);

    /**
     * Tests equality between two agencies
     * Agencies don't need to be totally equal
     * An equal NIF is sufficient
     *
     * @override equality operator equal-to
     * @brief asserts equality between agencies
     * @param other Agency object to be compared to
     * @return true if agencies are equal, otherwise false
     */
    bool operator ==(const Agency &agency) const;

    /**
     * Tests if two agencies are different
     * Agencies don't need to be totally equal
     * Just an equal NIF is sufficient
     *
     * @override equality operator not-equal-to
     * @brief asserts inequality between agencies
     * @param other Agency object to be compared to
     * @return true if agencies are different, otherwise true
     */
    bool operator !=(const Agency &agency) const;

    /**
     * Giving a client, tests if agency already contains the given client
     * Returning true if it contains else false
     *
     * @brief tests if agency already contains a client
     * @param client Client to compare
     * @return if @a client is already on the agency's clients
     */
    bool containsClient(const Client &client);

    /**
     * Giving a travel pack, tests if agency already contains the given pack
     * Returning true if it contains else false
     *
     * @brief tests if agency already contains a pack
     * @param pack Travel Pack to compare
     * @return if @a pack is already on the agency's travel packs
     */
    bool containsPack(const TravelPack &pack);

    /**
     * Deletes all clients of the agency
     *
     * @brief remove all clients of the agency
     */
    void deleteClients(void);

    /**
     * Deletes client at position @a at from the agency's clients
     *
     * @brief remove client from agency's clients
     * @param at position of client to remove
     */
    void deleteClient(size_t at);

    /**
     * Deletes all travel packs of the agency
     *
     * @brief remove all travel packs from agency
     */
    void deletePacks(void);

    /**
     * Deletes pack at position @a at from agency's packs
     *
     * @brief remove pack from agency's packs
     * @param at position of pack to remove
     */
    void deletePack(size_t at);

    /**
     * Gets the number of sales for an agency and the accumulated value of all packs sold
     *
     * @brief getter for number of sales and value of sales of agency
     * @return array sold and total value of packs
     */
    std::array<ULLong, 2> getPackSold(void) const;

    /**
     * Inserts the Agency in a formatted way to the output stream
     * Format used for agency:
     * 	{agency information}
     * 	{agency clients information}
     *
     *
     * @override insertion operator to accept Date object
     * @brief inserts date to the output stream
     * @overload std::ostream& operator <<(std::ostream& stream, const Date& date)
     * @param os output stream (i.e: cout, ostringstream, ...)
     * @param date Date object
     * @return os object
     */
    friend std::ostream& operator <<(std::ostream& os, const Agency& agency);

};

/**
 * Given a vector containing all the information about an agency
 *
 *
 * @brief reads agency from vector
 * @param v vector containing the data to be read
 * @param agency Agency object to be used as container
 * @return 1 if operation was successful, otherwise 0
 */
int readAgency(const std::vector<std::string> &v, Agency &agency);

/**
 * Writes all agency information to a vector
 * Each element of the vector has a line corresponding to the formatted information
 * on the file
 *
 * @brief write agency to vector (formatted)
 * @param agency Agency object
 * @param v container for all information about the agency
 * @return if operation was successful
 */
int writeAgency(const Agency &agency, std::vector<std::string> &v);

/**
 * Tests if all agencies have any change since last save
 * If there is some change, false is returned
 * Else the return is true (if vector is empty, true is also returned)
 *
 * @brief tests if any agency has a change since last save
 * @param agencies Vector containing all agencies being managed
 * @return if all agencies are updated
 */
bool isAllUpToDate(const std::vector<Agency> &agencies);

/**
 * Saves all agency information to respective file including agency's clients and travel packs
 * If agency is already updated, no save is done (already is up do date)
 *
 * @brief saves all changes of the agency
 * @param agency Agency to be saved
 * @return if operation was successful
 */
int saveAgency(Agency &agency);

/**
 * Saves all agencies to their respective files including agencies' clients and travel packs
 * If all agencies are already updated, no save is done (already is up do date)
 *
 * @brief saves all changes of all the agencies
 * @param agencies Vector containing all agencies being managed
 * @return if operation was successful
 */
int saveAgencies(std::vector<Agency> &agencies);
