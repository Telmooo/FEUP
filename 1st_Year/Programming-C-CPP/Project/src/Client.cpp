/**
 * @file Client.cpp
 *
 * @author telmo
 * @since 23-03-2019
 * @version 1.0
 */

#include "../headers/Client.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>

/**
 * Accesses the client's address
 *
 * @brief getter for client's address
 * @return address
 */
const Address& Client::getAddress(void) const {
    return address;
}

/**
 * Defines the client's address to desired address
 *
 * @brief setter for client's adress
 * @param address to be defined to
 */
void Client::setAddress(const Address& address) {
    this->address = address;
}

/**
 * Accesses the client's family aggregate number
 *
 * @brief getter for client's family aggregate number
 * @return familyAggr
 */
UInt Client::getFamilyAggr(void) const {
    return familyAggr;
}

/**
 * Defines the client's family aggregate number
 *
 * @brief setter for client's family aggregate number
 * @param familyAggr value to be defined to
 */
void Client::setFamilyAggr(UInt familyAggr) {
    this->familyAggr = familyAggr;
}

/**
 * Accesses the client's name
 *
 * @brief getter for client's name
 * @return name
 */
const std::string& Client::getName(void) const {
    return name;
}

/**
 * Defines the client's name
 *
 * @brief setter for client's name
 * @param name to be defined to
 */
void Client::setName(const std::string& name) {
    this->name = name;
}

/**
 * Accesses the client's nif
 *
 * @brief getter for client's nif
 * @return nif
 */
ULLong Client::getNif(void) const {
    return nif;
}

/**
 * Defines the client's nif
 *
 * @brief setter for client's nif
 * @param nif value to be defined to
 */
void Client::setNif(ULLong nif) {
    this->nif = nif;
}

/**
 * Accesses all the travel packs the client bought
 *
 * @brief getter for the client's travel packs
 * @return packs
 */
const std::vector<TravelPack>& Client::getPacks(void) const {
    return packs;
}

/**
 * Defines all the travel packs of the client
 *
 * @brief setter for travel packs of the client
 * @param packs to be defined to
 */
void Client::setPacks(const std::vector<TravelPack> &packs) {
    this->packs = packs;
}

/**
 * Accesses the client's purchased packs
 *
 * @brief getter for client's purchased packs
 * @return packsPurchased
 */
const std::vector<int>& Client::getPacksPurchased(void) const {
    return packsPurchased;
}

/**
 * Defines all the client's purchased packs
 *
 * @brief setter for all client's purchased packs
 * @param packsPurchased to be defined to
 */
void Client::setPacksPurchased(const std::vector<int> &packsPurchased) {
    this->packsPurchased = packsPurchased;
}

/**
 * Accesses the client's number of purchases
 *
 * @brief getter for client's number of purchases
 * @return purchases
 */
UInt Client::getPurchasesValue(void) const {
    return purchasesValue;
}

/**
 * Defines the client's number of purchases
 *
 * @brief setter for client's number of purchases
 * @param purchases value to be defined to
 */
void Client::setPurchasesValue(UInt purchasesValue) {
    this->purchasesValue = purchasesValue;
}

/**
 * Accesses a specific pack purchased by the client
 *
 * @brief getter for specific client's pack purchased
 * @param at index of pack purchased to be accessed
 * @return pack accessed
 */
const TravelPack& Client::getPack(size_t at) const {
    return packs.at(at);
}

/**
 * Defines a client's specific pack purchased
 *
 * @brief setter for client's specific pack purchased
 * @param pack to be defined to
 * @param at index of pack to be defined to
 */
void Client::setPack(const TravelPack& pack, size_t at) {
    this->packs.at(at) = pack;
    this->packsPurchased.at(at) = std::abs(pack.getIdentifier());
}

/**
 * Accesses a specific pack purchased identifier
 *
 * @brief getter for specific client's pack purchased identifier
 * @param at index of pack purchased to be accessed
 * @return identifier of pack accessed
 */
int Client::getPackPurchased(size_t at) const {
    return packsPurchased.at(at);
}

/**
 * Defines a client's specific purchased pack identifier
 *
 * @brief setter for client's specific pack purchased
 * @param identifier to be defined to
 * @param at index of pack to be defined to
 */
void Client::setPackPurchased(int identifier, size_t at) {
    this->packsPurchased.at(at) = identifier;
}

/**
 * Inserts a pack to the end of client's travel packs purchased
 *
 * @brief pushes a travel pack to client
 * @param pack to be pushed
 */
void Client::pushPack(const TravelPack& pack) {
    packs.push_back(pack);
}

/**
 * Inserts a pack to the end of client's travel packs purchased identifiers
 *
 * @brief pushes a travel pack identifier to client travel pack's identifiers
 * @param pack identifier to be pushed
 */
void Client::pushPackPurchased(int identifier) {
    packsPurchased.push_back(identifier);
}

/**
 * Deletes all travel packs of the client
 *
 * @brief remove all travel packs from client
 */
void Client::deletePacks(void) {
    this->packs.clear();
    this->packsPurchased.clear();
}

/**
 * Deletes pack at position @a at from client's packs
 *
 * @brief remove pack from client's packs
 * @param at position of pack to remove
 */
void Client::deletePack(size_t at) {
    if (at < this->packs.size())
        this->packs.erase(this->packs.begin() + at);

    if (at < this->packsPurchased.size())
        this->packsPurchased.erase(this->packsPurchased.begin() + at);
}

/**
 * Creates a deep-copy of the client object
 * Each member of the new client is a copy of the original one
 *
 * @brief creates a copy of the client object
 * @override assignment operator to accept Client object
 * @param client Client object to be copied
 * @return copy of the original Client
 */
Client& Client::operator =(const Client& client) {

    if (this == &client)
        return *this;

    this->name = client.getName();
    this->nif = client.getNif();
    this->address = client.getAddress();
    this->familyAggr = client.getFamilyAggr();
    this->packsPurchased = client.getPacksPurchased();
    this->packs = client.getPacks();
    this->purchasesValue = client.getPurchasesValue();
    return *this;
}

/**
 * Resets all information about a client to the default
 * @see class Client for the default values
 * @brief resets all client information
 */
void Client::clear(void) {
    Client newClearedClient;
    *this = newClearedClient;
}

/**
 * Tests equality between two clients
 * Clients don't need to be totally equal
 * An equal NIF is sufficient
 *
 * @override equality operator equal-to
 * @brief asserts equality between clients
 * @param other client object to be compared to
 * @return true if agencies are equal, otherwise false
 */
bool Client::operator ==(const Client &other) const {

    if (this == &other)
        return true;

    if (this->nif != other.nif) // NIF is unique to each client
        return false;

    return true;
}

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
bool Client::operator !=(const Client &other) const {
    return !(*this == other);
}

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
std::ostream& operator <<(std::ostream& os, const Client& client) {
    os << "Name: " << client.name << "\nNIF: " << client.nif << "\nFamily Aggregate: "
       << client.familyAggr << "\nAddress:\n" << client.address.formatTo_str("\t")
       << "Packs bought:" << (client.packs.size() == 0 ? " NULL" : "") << "\n";
    for (const TravelPack &pack : client.packs)
        pack.showBasic("\t");
    os << "Money spent: " << client.purchasesValue << "\n";
    std::cout << "\n";
    return os;
}

/**
 * Given a vector containing all the information about a client
 *
 *
 * @brief reads client from vector
 * @param v vector containing the data to be read
 * @param client Client object to be used as container
 * @return 1 if operation was successful, otherwise 0
 */
int readClient(const std::vector<std::string> &v, Client &client) {

    if (v.size() != 6)
        return 0;

    client.setName(v.at(0));

    client.setNif(std::stoull(v.at(1)));

    client.setFamilyAggr(std::stoul(v.at(2)));

    Address address;
    readAddress(v.at(3), address);
    client.setAddress(address);

    std::string str = v.at(4);
    std::replace(str.begin(), str.end(), ';', ' ');
    std::stringstream ss(str);
    int x;
    while (ss >> x)
        client.pushPackPurchased(x);

    client.setPurchasesValue(std::stoul(v.at(5)));

    return 1;
}

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
int writeClient(const Client &client, std::vector<std::string> &v) {

    v.push_back(client.getName());

    v.push_back(std::to_string(client.getNif()));

    v.push_back(std::to_string(client.getFamilyAggr()));

    v.push_back(client.getAddress().to_str());

    v.push_back(vectorToStr(client.getPacksPurchased(), " ; "));

    v.push_back(std::to_string(client.getPurchasesValue()));

    return 0;

}
