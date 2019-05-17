/**
 * @file Agency.cpp
 *
 * @author telmo
 * @since 23-03-2019
 * @version 1.0
 */

#include "../headers/Agency.hpp"

#include <algorithm>
#include <cstdlib>
#include <iterator>

/**
 * Access value of path of agency file
 *
 * @brief getter for path
 * @return path for the agency file
 */
const std::string Agency::getPath(void) const {
    return path;
}

/**
 * Sets the path for the agency file
 *
 * @brief setter for path
 * @param str
 */
void Agency::setPath(const std::string &str) {
    this->path = str;
}

/**
 * Accesses the address of the agency
 *
 * @brief getter for the agency's address
 * @return address
 */
const Address& Agency::getAddress(void) const {
    return address;
}

/**
 * Defines the address of the agency
 *
 * @brief setter for address of agency
 * @param address to be defined to
 */
void Agency::setAddress(const Address& address) {
    this->address = address;
}

/**
 * Accesses the clients of the agency
 *
 * @brief getter for the agency's clients
 * @return clients
 */
const std::vector<Client>& Agency::getClients(void) const {
    return clients;
}

/**
 * Defines all the clients of the agency
 *
 * @brief setter for all the clients of the agency
 * @param clients to be defined to
 */
void Agency::setClients(const std::vector<Client>& clients) {
    this->clients = clients;
}

/**
 * Accesses the path for the file containing all the clients
 * of the agency
 *
 * @brief getter for the agency's clients file
 * @return clientsFile
 */
const std::string& Agency::getClientsFile(void) const {
    return clientsFile;
}

/**
 * Defines the new path for file of the clients of the agency
 *
 * @brief setter for path of the clients file of agency
 * @param path to be defined to
 */
void Agency::setClientsFile(const std::string& clientsFile) {
    this->clientsFile = clientsFile;
}

/**
 * Accesses the name of the agency
 *
 * @brief getter for the agency's name
 * @return name
 */
const std::string& Agency::getName(void) const {
    return name;
}

/**
 * Defines the name of the agency
 *
 * @brief setter for name of agency
 * @param name to be defined to
 */
void Agency::setName(const std::string& name) {
    this->name = name;
}

/**
 * Accesses the NIF of the agency
 *
 * @brief getter for the agency's NIF
 * @return nif
 */
ULLong Agency::getNif(void) const {
    return nif;
}

/**
 * Defines the NIF of the agency
 *
 * @brief setter for NIF of agency
 * @param nif to be defined to
 */
void Agency::setNif(ULLong nif) {
    this->nif = nif;
}

/**
 * Accesses all the travel packs of the agency
 *
 * @brief getter for the agency's travel packs
 * @return packs
 */
const std::vector<TravelPack>& Agency::getPacks(void) const {
    return packs;
}

/**
 * Defines all the travel packs of the agency
 *
 * @brief setter for travel packs of agency
 * @param packs to be defined to
 */
void Agency::setPacks(const std::vector<TravelPack>& packs) {
    this->packs = packs;
}

/**
 * Accesses the path for the file containing all the travel packs
 * of the agency
 *
 * @brief getter for the agency's travel packs file
 * @return packsFile
 */
const std::string& Agency::getPacksFile(void) const {
    return packsFile;
}

/**
 * Defines the new path for file of the travel packs of the agency
 *
 * @brief setter for path of the travel packs file of agency
 * @param path to be defined to
 */
void Agency::setPacksFile(const std::string& packsFile) {
    this->packsFile = packsFile;
}

/**
 * Access value of last updated pack identifier
 *
 * @brief getter for value of last updated pack identifier
 * @return last updated pack identifier of the agency
 */
int Agency::getLastUpdatedPack(void) const {
    return lastUpdatedPack;
}

/**
 * Sets the last updated pack to the identifier of last updated pack
 *
 * @brief setter last updated pack identifier
 * @param identifier of last updated pack
 */
void Agency::setLastUpdatedPack(int identifier) {
    this->lastUpdatedPack = identifier;
}

/**
 * Accesses the website link of the agency
 *
 * @brief getter for the agency's website
 * @return website
 */
const std::string& Agency::getWebsite(void) const {
    return website;
}

/**
 * Defines the website of the agency
 *
 * @brief setter for website of agency
 * @param website to be defined to
 */
void Agency::setWebsite(const std::string& website) {
    this->website = website;
}

/**
 * Accesses the specific client in the position specified in the vector
 *
 * @brief getter for specific client
 * @param at index of the client to be accessed
 * @return client accessed
 */
const Client& Agency::getClient(size_t at) const {
    return clients.at(at);
}

/**
 * Defines a specific client at the specified position
 *
 * @brief setter for specific client
 * @param client to be defined to
 * @param at index of client to be defined in vector
 */
void Agency::setClient(const Client& client, size_t at) {
    this->clients.at(at) = client;
}

/**
 * Inserts a client to the end of agency's clients
 *
 * @brief pushes a client to agency
 * @param client Client to be pushed
 */
void Agency::pushClient(const Client& client) {
    this->clients.push_back(client);
}

/**
 * Accesses the specific pack in the position specified in the vector
 *
 * @brief getter for specific pack
 * @param at index of the pack to be accessed
 * @return pack accessed
 */
const TravelPack& Agency::getPack(size_t at) const {
    return packs.at(at);
}

/**
 * Defines a specific pack at the specified position
 *
 * @brief setter for specific pack
 * @param pack to be defined to
 * @param at index of pack to be defined in vector
 */
void Agency::setPack(const TravelPack& pack, size_t at) {
    this->packs.at(at) = pack;
}

/**
 * Inserts a pack to the end of agency's travel packs
 *
 * @brief pushes a travel pack to agency
 * @param pack to be pushed
 */
void Agency::pushPack(const TravelPack& pack) {
    this->packs.push_back(pack);
}

/**
 * Access value of update status of agency
 *
 * @brief getter for update status
 * @return update status of agency
 */
bool Agency::upToDate(void) const {
    return updated;
}

/**
 * Sets agency to updated or not updated
 * If updated -> set to true
 * Else -> set to false
 *
 * @brief setter updated status of agency
 * @param updated state to be set to
 */
void Agency::setUpdated(bool updated) {
    this->updated = updated;
}

/**
 * Creates a deep-copy of the agency object
 * Each member of the new agency is a copy of the original one
 *
 * @brief creates a copy of the agency object
 * @override assignment operator to accept Agency object
 * @param agency Agency object
 * @return copy of the original Agency
 */
Agency& Agency::operator =(const Agency &agency) {

    if (this == &agency)
        return *this;

    this->name = agency.getName();
    this->nif = agency.getNif();
    this->address = agency.getAddress();
    this->website = agency.getWebsite();
    this->packsFile = agency.getPacksFile();
    this->packs = agency.getPacks();
    this->lastUpdatedPack = agency.getLastUpdatedPack();
    this->clientsFile = agency.getClientsFile();
    this->clients = agency.getClients();
    return *this;
}

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
bool Agency::operator ==(const Agency &other) const {

    if (this == &other)
        return true;

    if (this->nif != other.nif)
        return false;

    return true;
}

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
bool Agency::operator !=(const Agency &other) const {
    return !(*this == other);
}

/**
 * Giving a client, tests if agency already contains the given client
 * Returning true if it contains else false
 *
 * @brief tests if agency already contains a client
 * @param client Client to compare
 * @return if @a client is already on the agency's clients
 */
bool Agency::containsClient(const Client &client) {
    if (this->clients.size() == 0)
        return false;

    for (const Client &agencyClient : this->clients)
        if (agencyClient == client)
            return true;

    return false;
}

/**
 * Giving a travel pack, tests if agency already contains the given pack
 * Returning true if it contains else false
 *
 * @brief tests if agency already contains a pack
 * @param pack Travel Pack to compare
 * @return if @a pack is already on the agency's travel packs
 */
bool Agency::containsPack(const TravelPack &pack) {
    if (this->packs.size() == 0)
        return false;

    for (const TravelPack &agencyPack : this->packs)
        if (agencyPack == pack)
            return true;

    return false;
}

/**
 * Deletes all clients of the agency
 *
 * @brief remove all clients of the agency
 */
void Agency::deleteClients(void) {
    this->clients.clear();
}

/**
 * Deletes client at position @a at from the agency's clients
 *
 * @brief remove client from agency's clients
 * @param at position of client to remove
 */
void Agency::deleteClient(size_t at) {
    if (at >= this->clients.size())
        return;

    this->clients.erase(this->clients.begin() + at);
}

/**
 * Deletes all travel packs of the client
 *
 * @brief remove all travel packs from client
 */
void Agency::deletePacks(void) {
    this->packs.clear();
}

/**
 * Deletes pack at position @a at from client's packs
 *
 * @brief remove pack from client's packs
 * @param at position of pack to remove
 */
void Agency::deletePack(size_t at) {
    if (at >= this->packs.size())
        return;

    this->packs.erase(this->packs.begin() + at);
}

/**
 * Gets the number of sales for an agency and the accumulated value of all packs sold
 *
 * @brief getter for number of sales and value of sales of agency
 * @return array sold and total value of packs
 */
std::array<ULLong, 2> Agency::getPackSold(void) const {
    ULLong sold = 0, money = 0;
    for (const TravelPack &pack : packs) {
        sold += pack.getSold();
        money += pack.getSold() * pack.getPrice();
    }
    std::array<ULLong, 2> arr = { sold, money };
    return arr;
}

const std::map<std::string, UInt>& Agency::getVisitedPlaces() const {
    return visitedPlaces;
}

void Agency::updateVisitedPlaces(void) {

    visitedPlaces.clear();

    for (const TravelPack &pack : packs)
        for (const std::string &str : pack.getPlaces())
            visitedPlaces[str] += pack.getSold();
}

/**
 * Inserts the Agency in a formatted way to the output stream
 * Format used for agency:
 * 	{agency information}
 * 	{agency clients information}
 *
 *
 * @override insertion operator to accept Agency object
 * @brief inserts date to the output stream
 * @param os output stream (i.e: cout, ostringstream, ...)
 * @param agency Agency object
 * @return os object
 */
std::ostream& operator <<(std::ostream& os, const Agency& agency) {
    std::array<ULLong, 2> aux = agency.getPackSold();
    os << "Agency Name: " << agency.name << "\nNIF: " << agency.nif << "\nWebsite: "
       << agency.website << "\nAddress:\n" << agency.address.formatTo_str("\t")
       << "\nPacks sold: " << aux.at(0) << "\nMoney gained: " << aux.at(1) << "\n";
    return os;
}

/**
 * Given a vector containing all the information about an agency
 *
 *
 * @brief reads agency from vector
 * @param v vector containing the data to be read
 * @param agency Agency object to be used as container
 * @return 1 if operation was successful, otherwise 0
 */
int readAgency(const std::vector<std::string> &v, Agency &agency) {

    if (v.size() != 6)
        return 0;

    agency.setName(v.at(0));

    agency.setNif(std::stoull(v.at(1)));

    agency.setWebsite(v.at(2));

    Address address;
    readAddress(v.at(3), address);
    agency.setAddress(address);

    agency.setPacksFile(v.at(5));

    {
        std::vector<std::string> lines;
        if (!readFile(agency.getPacksFile(), lines))
            return 0;

        agency.setLastUpdatedPack(std::stoi(lines.at(0)));

        lines.erase(lines.begin());

        auto iter = std::find(lines.begin(), lines.end(), "::::::::::");
        std::vector<std::string> packInfo;
        TravelPack pack;
        while (iter != lines.end()) {
            pack.clear();
            packInfo.clear();
            packInfo.assign(lines.begin(), iter);

            if (!readTravelPack(packInfo, pack))
                return 0;
            agency.pushPack(pack);
            lines.erase(lines.begin(), iter + 1);
            iter = std::find(lines.begin(), lines.end(), "::::::::::");
        }
        pack.clear();
        packInfo.clear();
        packInfo.assign(lines.begin(), lines.end());
        readTravelPack(packInfo, pack);
        agency.pushPack(pack);
    }

    agency.setClientsFile(v.at(4));

    {
        std::vector<std::string> lines;
        if (!readFile(agency.getClientsFile(), lines))
            return 0;
        auto iter = std::find(lines.begin(), lines.end(), "::::::::::");
        std::vector<std::string> clientInfo;
        Client client;
        int auxIdentifier;
        bool control;
        while (iter != lines.end()) {
            client.clear();
            clientInfo.assign(lines.begin(), iter);

            if (!readClient(clientInfo, client))
                return 0;
            // VERIFY PACKS
            for (size_t i = 0; i < client.getPacksPurchased().size(); i++) {
            	auxIdentifier = client.getPackPurchased(i);
            	control = true;
                for (const TravelPack &pack : agency.getPacks()) {
                    if (std::abs(pack.getIdentifier()) == auxIdentifier) {
                        control = false;
                        client.pushPack(pack);
                        client.setPurchasesValue(client.getPurchasesValue() + 1);
                        break;
                    }
                }

                if (control) {
            	    client.deletePack(i);
            	    i--;
                }
            }
            agency.pushClient(client);
            lines.erase(lines.begin(), iter + 1);

            iter = std::find(lines.begin(), lines.end(), "::::::::::");
        }
        client.clear();
        clientInfo.assign(lines.begin(), lines.end());
        readClient(clientInfo, client);
        agency.pushClient(client);
    }

    return 1;
}

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
int writeAgency(const Agency &agency, std::vector<std::string> &v) {

    v.push_back(agency.getName());

    v.push_back(std::to_string(agency.getNif()));

    v.push_back(agency.getWebsite());

    v.push_back(agency.getAddress().to_str());

    v.push_back(agency.getClientsFile());

    v.push_back(agency.getPacksFile());

    return 1;
}

/**
 * Tests if all agencies have any change since last save
 * If there is some change, false is returned
 * Else the return is true (if vector is empty, true is also returned)
 *
 * @brief tests if any agency has a change since last save
 * @param agencies Vector containing all agencies being managed
 * @return if all agencies are updated
 */
//bool isAllUpToDate(const std::vector<Agency> &agencies) {
//    return (agencies.empty()
//            || std::all_of(agencies.begin(), agencies.end(),
//                           [](const Agency& agency) {return agency.upToDate();}));
//}

/**
 * Saves all agency information to respective file including agency's clients and travel packs
 * If agency is already updated, no save is done (already is up do date)
 *
 * @brief saves all changes of the agency
 * @param agency Agency to be saved
 * @return if operation was successful
 */
int saveAgency(Agency &agency) {

    std::vector<std::string> content;

    writeAgency(agency, content);

    writeFile(agency.getPath(), content);

    content.clear();

    for (const Client &client : agency.getClients()) {
        writeClient(client, content);
        content.push_back("::::::::::");
    }

    content.erase(content.end() - 1);

    writeFile(agency.getClientsFile(), content);

    content.clear();

    content.push_back(std::to_string(agency.getLastUpdatedPack()));

    for (const TravelPack &pack : agency.getPacks()) {
        writeTravelPack(pack, content);
        content.push_back("::::::::::");
    }

    content.erase(content.end() - 1);

    writeFile(agency.getPacksFile(), content);

    agency.setUpdated();

    return 1;
}

/**
 * Saves all agencies to their respective files including their clients and travel packs
 * If all agencies are already updated, no save is done (already is up do date)
 *
 * @brief saves all changes to all the agencies
 * @param agencies Vector containing all agencies being managed
 * @return if operation was successful
 */
//int saveAgencies(std::vector<Agency> &agencies) {
//
//    if (isAllUpToDate(agencies)) // already all saved
//        return 1;
//
//    for (Agency &agency : agencies)
//        saveAgency(agency);
//
//    return 1;
//}
