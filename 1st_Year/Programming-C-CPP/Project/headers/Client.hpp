/**
 * @file Client.hpp
 *
 * @author telmo
 * @since 23-03-2019
 * @version 1.0
 */

#pragma once

#include <cstddef>
#include <ostream>
#include <string>
#include <vector>

#include "TravelPack.hpp"
#include "Utils.hpp"
#include "Address.hpp"

/**
 * Container for every information about a client
 * Client has:
 *	- Name
 *	- NIF (Tax Identification Number)
 *	- Address @link Address
 *	- Number of people in the family aggregate
 *	- Travel packs purchased @link TravelPack
 *
 * @class Client
 * @brief container for client information
 */
class Client {
private:
    std::string name = "";
    ULLong nif = 0;
    Address address;
    UInt familyAggr = 0;
    std::vector<int> packsPurchased = { };
    std::vector<TravelPack> packs = { };
    UInt purchasesValue = 0;

public:
    /**
     * Accesses the client's address
     *
     * @brief getter for client's address
     * @return address
     */
    const Address& getAddress(void) const;

    /**
     * Defines the client's address to desired address
     *
     * @brief setter for client's adress
     * @param address to be defined to
     */
    void setAddress(const Address& address);

    /**
     * Accesses the client's family aggregate number
     *
     * @brief getter for client's family aggregate number
     * @return familyAggr
     */
    UInt getFamilyAggr(void) const;

    /**
     * Defines the client's family aggregate number
     *
     * @brief setter for client's family aggregate number
     * @param familyAggr value to be defined to
     */
    void setFamilyAggr(UInt familyAggr);

    /**
     * Accesses the client's name
     *
     * @brief getter for client's name
     * @return name
     */
    const std::string& getName(void) const;

    /**
     * Defines the client's name
     *
     * @brief setter for client's name
     * @param name to be defined to
     */
    void setName(const std::string& name);

    /**
     * Accesses the client's nif
     *
     * @brief getter for client's nif
     * @return nif
     */
    ULLong getNif(void) const;

    /**
     * Defines the client's nif
     *
     * @brief setter for client's nif
     * @param nif value to be defined to
     */
    void setNif(ULLong nif);

    /**
     * Accesses all the travel packs the client bought
     *
     * @brief getter for the client's travel packs
     * @return packs
     */
    const std::vector<TravelPack>& getPacks(void) const;

    /**
     * Defines all the travel packs of the client
     *
     * @brief setter for travel packs of the client
     * @param packs to be defined to
     */
    void setPacks(const std::vector<TravelPack> &packs);

    /**
     * Accesses the client's purchased packs
     *
     * @brief getter for client's purchased packs
     * @return packsPurchased
     */
    const std::vector<int>& getPacksPurchased(void) const;

    /**
     * Defines all the client's purchased packs
     *
     * @brief setter for all client's purchased packs
     * @param packsPurchased to be defined to
     */
    void setPacksPurchased(const std::vector<int> &packsPurchased);

    /**
     * Accesses the client's number of purchases
     *
     * @brief getter for client's number of purchases
     * @return purchasesValue
     */
    UInt getPurchasesValue(void) const;

    /**
     * Defines the client's number of purchases
     *
     * @brief setter for client's number of purchases
     * @param purchasesValue value to be defined to
     */
    void setPurchasesValue(UInt purchasesValue);

    /**
     * Accesses a specific pack purchased by the client
     *
     * @brief getter for specific client's pack purchased
     * @param at index of pack purchased to be accessed
     * @return pack accessed
     */
    const TravelPack& getPack(size_t at) const;

    /**
     * Defines a client's specific pack purchased
     *
     * @brief setter for client's specific pack purchased
     * @param pack to be defined to
     * @param at index of pack to be defined to
     */
    void setPack(const TravelPack& pack, size_t at);

    /**
     * Accesses a specific pack purchased identifier
     *
     * @brief getter for specific client's pack purchased identifier
     * @param at index of pack purchased to be accessed
     * @return identifier of pack accessed
     */
    int getPackPurchased(size_t at) const;

    /**
     * Defines a client's specific purchased pack identifier
     *
     * @brief setter for client's specific pack purchased
     * @param identifier to be defined to
     * @param at index of pack to be defined to
     */
    void setPackPurchased(int identifier, size_t at);

    /**
     * Inserts a pack to the end of client's travel packs purchased
     *
     * @brief pushes a travel pack to client
     * @param pack to be pushed
     */
    void pushPack(const TravelPack& pack);

    /**
     * Inserts a pack to the end of client's travel packs purchased identifiers
     *
     * @brief pushes a travel pack identifier to client travel pack's identifiers
     * @param pack identifier to be pushed
     */
    void pushPackPurchased(int identifier);

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
     * Resets all information about a client to the default
     * @see class Client for the default values
     * @brief resets all client information
     */
    void clear(void);

    /**
     * Creates a deep-copy of the client object
     * Each member of the new client is a copy of the original one
     *
     * @brief creates a copy of the client object
     * @override assignment operator to accept Client object
     * @param client Client object to be copied
     * @return copy of the original Client
     */
    Client& operator =(const Client &client);

    /**
     * Tests equality between two clients
     * Clients don't need to be totally equal
     * An equal NIF is sufficient
     *
     * @override equality operator equal-to
     * @brief asserts equality between clients
     * @param other client object to be compared to
     * @return true if clients are equal, otherwise false
     */
    bool operator ==(const Client &other) const;

    /**
     * Tests if two clients are different
     * Clients don't need to be totally equal
     * Just an equal NIF is sufficient
     *
     * @override equality operator not-equal-to
     * @brief asserts inequality between clients
     * @param other Client object to be compared to
     * @return true if clients are different, otherwise true
     */
    bool operator !=(const Client &other) const;

    /**
     * Inserts the Client in a formatted way to the output stream
     * Format used for Client:
     * 	{name}
     * 	{nif}
     * 	{family aggregate}
     * 	{address (formatted)}
     * 	{packs bought (basic information for each)}
     *
     * @override insertion operator to accept Client object
     * @brief inserts client to the output stream
     * @overload std::ostream& operator <<(std::ostream& stream, const Client& client)
     * @param os output stream (i.e: cout, ostringstream, ...)
     * @param client Client object
     * @return os object
     */
    friend std::ostream& operator <<(std::ostream& os, const Client& client);
};

/**
 * Given a vector containing all the information about a client
 *
 *
 * @brief reads client from vector
 * @param v vector containing the data to be read
 * @param client Client object to be used as container
 * @return 1 if operation was successful, otherwise 0
 */
int readClient(const std::vector<std::string> &v, Client &client);

/**
 * Writes all client information to a vector
 * Each element of the vector has a line corresponding to the formatted information
 * on the file
 *
 * @brief write client to vector (formatted)
 * @param client Client object
 * @param v container for all information about the client
 * @return if operation was successful
 */
int writeClient(const Client &client, std::vector<std::string> &v);
