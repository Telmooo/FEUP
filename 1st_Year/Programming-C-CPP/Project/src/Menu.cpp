/**
 * @file Menu.cpp
 *
 * @author telmo
 * @since 29/03/2019
 * @version 1.0
 */

#include "../headers/Menu.hpp"

#include <stddef.h>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>
#include <sstream>
#include <algorithm>

#include "../headers/Client.hpp"
#include "../headers/TravelPack.hpp"
#include "../headers/Utils.hpp"

/**
 * Runs the main menu allowing user to create/modify agencies
 * All data must be saved using the options given
 * All unsaved data on exit is lost
 *
 * @brief main menu for multiple agency management
 */
void runMainMenu(void) {

    bool created = false;
    while (!created) {
        Agency agency;
        std::cout << "Enter the agency file: ";
        std::string path;
        std::getline(std::cin, path);

        std::vector<std::string> content;
        if (readFile(path, content)) {
            if (readAgency(content, agency)) {
                agency.setPath(path);
                created = true;
                runAgencyMenu(agency);
            } else {
                std::cout << "Invalid agency... aborting process\n";
            }
        } else {
            std::cout << "Invalid file\n";
        }
    }
//    bool created = false;
//
//	while (true) {
//		std::cout << TEXT_DELIMITER << "\nWelcome to agency management\n";
//		std::cout << "Options available:\n" << "[1] Create new agency\n" << "[2] Access agency\n"
//				<< "[3] Delete agency\n" << "[4] Save all changes\n" << "[0] Exit\n";
//
//		switch (askChoice("Enter your option: ")) {
//			case 0: // EXITING PROGRAM
//				if (created && !agency.upToDate()) {
//					switch (askYesNo("Data hasn't been saved yet. Do you want to save (y / n)?: ")) {
//						case 'y':
//						case 'Y':
//							saveAgency(agency);
//							return;
//						case 'n':
//						case 'N':
//							std::cout << "\nExiting... All unsaved data will be lost\n";
//							return;
//					}
//
//				} else {
//					std::cout << "Exiting...\n";
//					return;
//				}
//				break;
//			case 1: { // AGENCY CREATION
//			    if (!created) {
//                    std::cout << "Options available for agency creation:\n"
//                              << "[1] Agency from existing file\n" << "[2] Empty agency\n";
//
//                    switch (askChoice("Enter your option (0 to cancel): ")) {
//                        case 0:
//                            std::cout << "Cancelling...\n";
//                            break;
//                        case 1: { // AGENCY FROM FILE
//                            clearInputBuffer();
//                            Agency newAgency;
//                            std::cout << "Enter the agency file: ";
//                            std::string path;
//                            std::getline(std::cin, path);
//                            std::vector<std::string> content;
//                            if (readFile(path, content)) {
//                                if (readAgency(content, newAgency)) {
//                                        agency.setPath(path);
//                                        agency = newAgency;
//                                        created = true;
//                                        std::cout << "Agency added\n";
//                                } else {
//                                    std::cout << "Invalid agency... aborting process\n";
//                                }
//                            } else {
//                                std::cout << "Invalid file\n";
//                            }
//                        }
//                            break;
//                        case 2: { // AGENCY FROM ROOT (EMPTY AGENCY)
//                            Agency newAgency;
//                            bool control;
//                            do {
//                                control = false;
//                                runAgencyEditMenu(agency);
//                                switch (askYesNo(
//                                        "Are you sure you want to add this agency (y / n)? ")) {
//                                    case 'y':
//                                    case 'Y':
//                                        //agencies.push_back(agency);
//                                        std::cout
//                                                << "Updating agency from root (from files), all not-saved data may be lost\n";
//                                        switch (askYesNo(
//                                                "Do you want to update the agency from root (y / n)? ")) {
//                                            case 'y':
//                                            case 'Y': {
//                                                std::string path = agency.getPath();
//                                                std::vector<std::string> content;
//                                                Agency copy;
//                                                if (readFile(path, content)) {
//                                                    readAgency(content, copy);
//                                                    agency = copy;
//                                                    std::cout << "Agency updated from root\n";
//                                                } else
//                                                    std::cout
//                                                            << "Invalid file... aborting process no data was lost\n";
//                                            }
//                                                break;
//                                            case 'n':
//                                            case 'N':
//                                                break;
//                                        }
//                                        std::cout << "Agency added with success\n";
//                                        break;
//                                    case 'n':
//                                    case 'N':
//                                        break;
//                                }
//                            } while (control);
//                        }
//                            break;
//                    }
//                } else {
//			        std::cout << "Agency is already created...\n\n";
//			    }
//			}
//				break;
//			case 2: // AGENCY ACCESS
//				if (!created) {
//					std::cout << "There is no agencies yet\n";
//					break;
//				}
//                runAgencyMenu(agency);
//				break;
//			case 3: { // AGENCY DELETION
//				if (!created) {
//					std::cout << "There is no agencies yet\n";
//					break;
//				}
//
//				switch (askYesNo("Are you sure you want to delete the agency (y / n)?: ")) {
//                    case 'y':
//                    case 'Y': {
//                        Agency empty;
//                        agency = empty;
//                        created = false;
//                    }
//                        break;
//                    case 'n':
//                    case 'N':
//                        std::cout << "Aborting process\n";
//                        break;
//                }
//			}
//				break;
//			case 4: // DATA SAVING
//				if (created && !agency.upToDate()) {
//					switch (askYesNo("Are you sure you want to save all changes (y / n)? ")) {
//						case 'y':
//						case 'Y':
//							saveAgency(agency);
//							break;
//						case 'n':
//						case 'N':
//							break;
//					}
//				} else {
//					std::cout << "There's no changes to be updated... cancelling process\n";
//				}
//				break;
//			default:
//				std::cout << "ERROR: Invalid entry\n\n";
//				break;
//		}
//		std::cout << "\n";
//	}
}

/**
 * Runs the agency management menu, giving options to add/edit clients/travel packs
 * Data may be saved in the main menu or in the specific agency menu
 * All unsaved data is lost
 *
 * @brief specific agency management menu
 */
void runAgencyMenu(Agency &agency) {

	while (true) {
		std::cout << TEXT_DELIMITER << "\nWelcome to Agency: " << agency.getName() << "\n";
		std::cout << "Management options available:\n" << "[1] See agency information\n"
				<< "[2] Edit agency information\n" << "[3] Manage Clients\n"
				<< "[4] Manage Travel Packs\n" << "[5] Save changes\n"
				<< "[6] Show agency statistics\n"<< "[7] Update from root\n"
				<< "[0] Exit\n";

		switch (askChoice("Enter your option: ")) {
			case 0: // EXIT
				if (!agency.upToDate()) {
					switch (askYesNo("Data hasn't been saved yet. Do you want to save (y / n)?: ")) {
						case 'y':
						case 'Y':
							saveAgency(agency);
							return;
						case 'n':
						case 'N':
							std::cout << "\nExiting... All unsaved data might be lost\n";
							return;
					}

				} else {
					std::cout << "Exiting...\n";
					return;
				}
				return;
			case 1: { // AGENCY INFO VISUALISATION
				std::cout << TEXT_DELIMITER << "\nAgency " << agency.getName() << " Information:\n"
						<< agency << "\n";
				switch (askYesNo("Want to see the agency's clients (y / n)? ")) {
					case 'y':
					case 'Y':
						for (size_t i = 0; i < agency.getClients().size(); i++)
							std::cout << "\nClient " << i + 1 << "\n" << agency.getClient(i)
									<< "\n";
						break;
					case 'n':
					case 'N':
						break;
				}
				std::cout << "\n";

				switch (askYesNo("Want to see the agency's travel packs (y / n)? ")) {
					case 'y':
					case 'Y':
						for (size_t i = 0; i < agency.getPacks().size(); i++)
							std::cout << "\nTravel Pack " << i + 1 << "\n" << agency.getPack(i)
									<< "\n";
						break;
					case 'n':
					case 'N':
						break;
				}
			}
				break;
			case 2: // AGENCY EDITION
				runAgencyEditMenu(agency);
				break;
			case 3: // CLIENT MANAGEMENT
				runAgencyClientMenu(agency);
				break;
			case 4: // TRAVEL PACK MANAGEMENT
				runAgencyPackMenu(agency);
				break;
			case 5: { // DATA SAVING
			    if (!agency.upToDate()) {
                    switch (askYesNo(
                            "Are you sure you want to save all changes to this agency(y / n)? ")) {
                        case 'y':
                        case 'Y':
                            saveAgency(agency);
                            agency.setUpdated(true);
                            break;
                        case 'n':
                        case 'N':
                            break;
                    }
                    break;
                }
			    std::cout << "There was no changes... canceling saving process\n";
			}
				break;
			case 6: // AGENCY STATS
				showStatistics(agency);
				break;
			case 7: { // UPDATING FROM ROOT (FILES)
				std::cout
						<< "Updating agency from root (from files), all not-saved data may be lost\n";
				switch (askYesNo("Are you sure you want to update this agency from root (y / n)? ")) {
					case 'y':
					case 'Y': {
						std::string path = agency.getPath();
						std::vector < std::string > content;
						Agency copy;
						if (readFile(path, content)) {
							if (readAgency(content, copy)) {
                                agency = copy;
                                agency.setUpdated(true);
                                std::cout << "Agency updated from root\n";
                            } else {
							    std::cout << "Invalid agency... aborting process no data was lost\n";
							}
						} else {
							std::cout << "Invalid file... aborting process no data was lost\n";
						}
					}
						break;
					case 'n':
					case 'N':
						break;
				}
			}
				break;
			default:
				std::cout << "Invalid number\n";
				break;
		}
	}
}

/**
 * Runs menu to edit agency information
 * Options available in menu is editing name, NIF, address, etc...
 *
 * @brief edit agency information
 * @param agency
 */
void runAgencyEditMenu(Agency &agency) {
	bool control;
	Agency copy = agency;
	while (true) {
		std::cout << TEXT_DELIMITER << "\nAgency Info:\n";
		std::cout << "\t1. Name: " << copy.getName() << "\n" << "\t2. Agency file path: "
				<< copy.getPath() << "\n" << "\t3. NIF: " << copy.getNif() << "\n"
				<< "\t4. Address:\n" << copy.getAddress().formatTo_str("\t\t") << "\n"
				<< "\t5. Website: " << copy.getWebsite() << "\n"
				<< "\t6. Agency travel pack's file path: " << copy.getPacksFile() << "\n"
				<< "\t7. Agency client's file path: " << copy.getClientsFile() << "\n";

		do {
			control = false;
			switch (askChoice("Choose the line you want to edit (0 to finish): ")) {
				case 0: { // EDITION FINISHING
					if (agency.upToDate()) {
						switch (askYesNo("Are you sure you want save the changes? (y / n)? ")) {
							case 'y':
							case 'Y':
								agency = copy;
								agency.setUpdated(false);
								std::cout << "Edits saved...\n";
								return;
							case 'n':
							case 'N':
								switch (askYesNo("\nDo you want to cancel the process (y / n)? ")) {
									case 'y':
									case 'Y':
										return;
									case 'n':
									case 'N':
										break;
								}
						}
					} else {
						std::cout << "Finishing process\n";
					}
				}
					break;
				case 1: {
					clearInputBuffer();
					std::string name;
					std::cout << "Enter the agency's name: ";
					while (!std::getline(std::cin, name)) {
						clearInputBuffer();
						std::cout << "Invalid entry\nEnter the agency's name: ";
					}
					Agency temp = copy;
					temp.setName(trimNorm(name, " "));
					std::cout << "Agency before edit:\n" << copy << "\n\n" << "Agency after edit:\n"
							<< temp << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							copy = temp;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				case 2: {
					clearInputBuffer();
					std::string path;
					std::cout << "Enter the agency's file path: ";
					while (!std::getline(std::cin, path)) {
						clearInputBuffer();
						std::cout << "Invalid entry\nEnter the agency's file path: ";
					}
					Agency temp = copy;
					temp.setPath(path);
					std::cout << "Agency before edit:\n" << copy << "\n\n" << "Agency after edit:\n"
							<< temp << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							copy = temp;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				case 3: {
					clearInputBuffer();
					ULLong nif = 0;
					std::cout << "Enter the agency's NIF: ";
					while (!(std::cin >> nif)) {
						std::cin.clear();
						clearInputBuffer();
						std::cout << "Invalid entry\nEnter the agency's NIF: ";
					}
					Agency temp = copy;
					temp.setNif(nif);
					std::cout << "\nAgency before edit:\n" << copy << "\n"
							<< "\nAgency after edit:\n" << temp << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							copy = temp;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				case 4:
					clearInputBuffer();
					addressMenu(copy);
					break;
				case 5: {
					clearInputBuffer();
					std::string website;
					std::cout << "Enter the agency's website: ";
					while (!std::getline(std::cin, website)) {
						clearInputBuffer();
						std::cout << "Invalid entry\nEnter the agency's website: ";
					}
					Agency temp = copy;
					temp.setWebsite(trimNorm(website, " "));
					std::cout << "Agency before edit:\n" << copy << "\n\n" << "Agency after edit:\n"
							<< temp << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							copy = temp;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				case 6: {
					clearInputBuffer();
					std::string path;
					std::cout << "Enter the agency's travel pack file path: ";
					while (!std::getline(std::cin, path)) {
						clearInputBuffer();
						std::cout << "Invalid entry\nEnter the agency's travel pack file path: ";
					}
					Agency temp = copy;
					temp.setPacksFile(trimNorm(path, " "));
					std::cout << "Agency before edit:\n" << copy << "\n\n" << "Agency after edit:\n"
							<< temp << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							copy = temp;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				case 7: {
					clearInputBuffer();
					std::string path;
					std::cout << "Enter the agency's clients file path: ";
					while (!std::getline(std::cin, path)) {
						clearInputBuffer();
						std::cout << "Invalid entry\nEnter the agency's clients file path: ";
					}
					Agency temp = copy;
					temp.setClientsFile(trimNorm(path, " "));
					std::cout << "Agency before edit:\n" << copy << "\n\n" << "Agency after edit:\n"
							<< temp << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							copy = temp;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				default:
					std::cout << "Invalid entry\n";
					control = true;
					break;
			}

		} while (control);
	}
}

/**
 * Runs the agency menu allowing user to create/modify agency's travel packs
 * Data may be saved in the main menu or in the specific agency menu
 * On creating/modifying travel pack's information, be sure to save the edits
 * All unsaved data is lost
 *
 * @brief agency's client management menu
 */
void runAgencyPackMenu(Agency &agency) {
	while (true) {
		std::cout << TEXT_DELIMITER << "\nPack Management of agency: " << agency.getName() << "\n";
		std::cout << "Management options available:\n" << "[1] Show packs\n"
				<< "[2] Create new pack\n" << "[3] Modify pack\n" << "[4] Delete pack\n"
				<< "[0] Exit\n";

		switch (askChoice("Enter the option: ")) {
			case 0:
				return;
			case 1: { // PACK VISUALISATION
				std::cout << TEXT_DELIMITER << "\nOptions available for packs visualisation:\n"
						<< "[1] All travel packs\n" << "[2] Choose travel pack\n"
						<< "[3] See available packs\n" << "[4] See sold packs\n" << "[0] Exit\n";
				int choice = askChoice("Enter your option: ");
				while (choice < 0 || choice > 4) {
					std::cout << "Invalid entry\n";
					choice = askChoice("Enter your option: ");
				}

				switch (choice) {
					case 0:
						break;
					case 1: // ALL TRAVEL PACKS
						if (agency.getPacks().empty())
							std::cout << "Agency has no travel packs yet\n";
						else {
							std::cout << "Showing all travel packs...\n\n";
							for (const TravelPack &pack : agency.getPacks())
								std::cout << pack << "\n";
							std::cout << "\n";
						}
						break;
					case 2: { // SPECIFIC TRAVEL PACK
						std::cout << "Choose a pack to see information\n";
						showPacksOptions(agency);
						if (!agency.getPacks().empty()) {
							int choice = askChoice(
									"Enter the pack number of order (0 to cancel): ");
							while (choice < 0 || (size_t) choice > agency.getPacks().size()) {
								std::cout << "Invalid entry\n";
								choice = askChoice(
										"Enter the pack number of order (0 to cancel): ");
							}

							if (choice != 0)
								std::cout << "\nShowing information for pack selected:\n"
										<< agency.getPack(choice - 1) << "\n\n";
						}
					}
						break;
					case 3: { // AVAILABLE TRAVEL PACKS
						std::cout << TEXT_DELIMITER
								<< "\nOptions available for available packs visualisation:\n"
								<< "[1] All available packs\n"
								<< "[2] All available between two dates\n"
								<< "[3] All available for a specific destiny\n"
								<< "[4] All available for a specific destiny between two dates\n"
								<< "[0] Exit\n";
						int choice = askChoice("Enter your option: ");
						while (choice < 0 || choice > 4) {
							std::cout << "Invalid entry\n";
							choice = askChoice("Enter your option: ");
						}
						switch (choice) {
							case 0:
								break;
							case 1:
								if (agency.getPacks().empty())
									std::cout << "Agency has no travel packs yet\n";
								else {
									std::cout << "Showing all available travel packs...\n\n";
									for (const TravelPack &pack : agency.getPacks())
										if (pack.getIdentifier() > 0)
											std::cout << pack << "\n";
									std::cout << "\n";
								}
								break;
							case 2: {
								Date start, end, temp;
								std::string aux;
								std::cout << "Enter the start date (year/month/day): ";
								while (!inputDate(aux))
									std::cout << "Invalid entry\nEnter the start date (year/month/day): ";

								clearInputBuffer();

								std::stringstream ss(aux);
								ss >> start;

								ss.clear();
								aux.clear();
								std::cout << "Enter the end date (year/month/day): ";
								while (true) {
									while (!inputDate(aux))
										std::cout << "Invalid entry\nEnter the end date (year/month/day): ";

									ss << aux;
									ss >> end;
									if (end >= start)
										break;
									else {
										std::cout << "Invalid entry\nEnter the end date (year/month/day): ";
										ss.clear();
										aux.clear();
									}
								}

								std::cout << "Showing all available packs between " << start
										<< " and " << end << ":\n";
								for (const TravelPack &pack : agency.getPacks()) {
									if (pack.getIdentifier() > 0) {
										temp = pack.getBegin();
										if (temp < start || temp > end)
											continue;
										temp = pack.getEnd();
										if (temp < start || temp > end)
											continue;

										std::cout << pack << "\n";
									}
								}
								std::cout << "\n";
							}
								break;
							case 3: {
								std::string destiny;
                                clearInputBuffer();
								std::cout << "Enter the destiny: ";
								std::getline(std::cin, destiny);
								destiny = trimNorm(destiny, " ");

								std::cout << "Showing all available packs to " << destiny << ":\n";
								for (const TravelPack &pack : agency.getPacks())
									if (pack.getIdentifier() > 0 && vectorContains(pack.getPlaces(), destiny))
										std::cout << pack << "\n";
								std::cout << "\n";
							}
								break;
							case 4: {
								std::string aux, destiny;
								Date start, end, temp;
								clearInputBuffer();
								std::cout << "Enter the destiny: ";
								std::getline(std::cin, destiny);
								destiny = trimNorm(destiny, " ");

								std::cout << "Enter the start date (year/month/day): ";
								while (!inputDate(aux))
									std::cout << "Invalid entry\nEnter the start date (year/month/day): ";

								std::stringstream ss(aux);
								ss >> start;

								ss.clear();
								aux.clear();
								std::cout << "Enter the end date (year/month/day): ";
								while (true) {
									while (!inputDate(aux))
										std::cout << "Invalid entry\nEnter the end date (year/month/day): ";

									ss << aux;
									ss >> end;
									if (end >= start)
										break;
									else {
										std::cout << "Invalid entry\nEnter the end date (year/month/day): ";
										ss.clear();
										aux.clear();
									}
								}

								std::cout << "Showing all available packs to " << destiny
										<< " between " << start << " and " << end << ":\n";
								for (const TravelPack &pack : agency.getPacks()) {
                                    if (pack.getIdentifier() > 0 && vectorContains(pack.getPlaces(), destiny)) {
										temp = pack.getBegin();
										if (temp < start || temp > end)
											continue;
										temp = pack.getEnd();
										if (temp < start || temp > end)
											continue;

										std::cout << pack << "\n";
									}
								}
								std::cout << "\n";
							}
								break;
						}
					}
						break;
					case 4: { // PACKS SOLD VISUALISATION
						std::cout << TEXT_DELIMITER
								<< "\nOptions available for sold packs visualisation:\n"
								<< "[1] All packs sold\n" << "[2] All packs sold to a client\n"
								<< "[0] Exit\n";
						int choice = askChoice("Enter your option: ");
						while (choice < 0 || choice > 2) {
							std::cout << "Invalid entry\n";
							choice = askChoice("Enter your option: ");
						}

						switch (choice) {
							case 0:
								break;
							case 1:
								std::cout << "Showing all packs sold\n\n";
								for (const TravelPack &pack : agency.getPacks())
									if (pack.getSold() > 0)
										std::cout << pack << "\n";
								std::cout << "\n";
								break;
							case 2: {
								std::cout << "Choose a client to edit\n";
								showClientOptions(agency);
								int choice = askChoice(
										"Enter the client number of order (0 to cancel): ");
								while (choice < 0 || (size_t) choice > agency.getClients().size()) {
									std::cout << "Invalid entry\n";
									choice = askChoice(
											"Enter the client number of order (0 to cancel): ");
								}
								std::cout << "\n";

								if (choice != 0)
									for (const TravelPack &pack : agency.getClient(choice - 1).getPacks())
										std::cout << pack << "\n";
								std::cout << "\n";
							}
								break;
						}
					}
						break;
				}
			}
				break;
			case 2: // PACK CREATION
			{
				packMenu(agency);
				break;
			}
				break;
			case 3: // PACK EDITION
			{
				std::cout << "Choose a pack to edit\n";
				showPacksOptions(agency);
				int choice = askChoice("Enter the travel pack number of order (0 to cancel): ");
				while (choice < 0 || (size_t) choice > agency.getPacks().size()) {
					std::cout << "Invalid entry\n";
					choice = askChoice("Enter the travel pack number of order (0 to cancel): ");
				}

				if (choice != 0)
					packMenu(agency, choice - 1);
			}
				break;
			case 4: { // PACK DELETION
				bool control;
				do {
					control = false;
					std::cout << TEXT_DELIMITER << "Deleting travel packs, choose an option:\n"
							<< "[1] All packs\n" << "[2] Choose travel pack\n" << "[0] Exit\n";
					switch (askChoice("Enter your option: ")) {
						case 0:
							break;
						case 1:
							switch (askYesNo(
									"Are you sure you want to delete all travel packs (y / n) ?: ")) {
								case 'y':
								case 'Y':
									agency.deletePacks();
                                    agency.setUpdated(false);
									break;
								case 'n':
								case 'N':
									break;
							}
						case 2: {
							std::cout << "Choose a travel pack to delete\n";
							showPacksOptions(agency);
							int choice = askChoice(
									"Enter the travel pack number of order (0 to cancel): ");
							while (choice < 0 || (size_t) choice > agency.getPacks().size()) {
								std::cout << "Invalid entry\n";
								choice = askChoice(
										"Enter the travel pack number of order (0 to cancel): ");
							}

							if (choice != 0)
								switch (askYesNo(
										"Are you sure you want to delete the travel pack (y / n) ?: ")) {
									case 'y':
									case 'Y':
										agency.deletePack(choice - 1);
                                        agency.setUpdated(false);
										break;
									case 'n':
									case 'N':
										break;
								}
						}
							break;
						default:
							control = true;
							std::cout << "Invalid entry\n";
							break;
					}

				} while (control);
			}
				break;
			default:
				std::cout << "Invalid number\n";
				break;
		}
	}
}

/**
 * Runs the agency menu allowing user to create/modify agency's clients
 * Data may be saved in the main menu or in the specific agency menu
 * On creating/modifying client's information, be sure to save the edits
 * All unsaved data is lost
 *
 * @brief agency's client management menu
 */
void runAgencyClientMenu(Agency &agency) {

	while (true) {
		std::cout << TEXT_DELIMITER << "\nClient Management of agency: " << agency.getName()
				<< "\n";
		std::cout << "Management options available:\n" << "[1] Show clients\n"
				<< "[2] Add new client\n" << "[3] Modify client\n" << "[4] Delete client\n"
				<< "[0] Exit\n";

		switch (askChoice("Enter the option: ")) {
			case 0:
				return;
			case 1: {
				std::cout << "Options available for client visualisation:\n" << "[1] All clients\n"
						<< "[2] Choose client\n" << "[0] Exit\n";
				int choice = askChoice("Enter your option: ");
				while (choice < 0 || choice > 2) {
                    std::cout << "Invalid entry\n";
                    choice = askChoice("Enter your option: ");
                }
				clearInputBuffer();

				switch (choice) {
					case 0:
						break;
					case 1:
						std::cout << "Showing all clients...\n\n";
						for (const Client &client : agency.getClients())
							std::cout << client << "\n\n";
						std::cout << "\n";
						break;
					case 2: {
						std::cout << "Choose a client to see information\n";
						showClientOptions(agency);
						int choice = askChoice("Enter the client number of order (0 to cancel): ");
						while (choice < 0 || (size_t) choice > agency.getClients().size()) {
							std::cout << "Invalid entry\n";
							choice = askChoice("Enter the client number of order (0 to cancel): ");
						}

						if (choice != 0)
							std::cout << "\nShowing information for client "
									<< agency.getClient(choice - 1).getName() << ":\n"
									<< agency.getClient(choice - 1) << "\n\n";
					}
				}
			}
				break;
			case 2: // CLIENT CREATION
				clientMenu(agency);
				break;
			case 3: { // EDIT CLIENT
				std::cout << "Choose a client to edit\n";
				showClientOptions(agency);
				int choice = askChoice("Enter the client number of order (0 to cancel): ");
				while (choice < 0 || (size_t) choice > agency.getClients().size()) {
					std::cout << "Invalid entry\n";
					choice = askChoice("Enter the client number of order (0 to cancel): ");
				}

				if (choice != 0)
					clientMenu(agency, choice - 1);
			}
				break;
			case 4: { // CLIENT DELETION
				bool control;
				do {
					control = false;
					std::cout << "Deleting clients, choose an option:\n" << "[1] All clients\n"
							<< "[2] Choose client\n" << "[0] Exit\n";
					switch (askChoice("Enter your option: ")) {
						case 0:
							break;
						case 1:
							switch (askYesNo(
									"Are you sure you want to delete all clients (y / n) ?: ")) {
								case 'y':
								case 'Y':
									agency.deleteClients();
                                    agency.setUpdated(false);
									break;
								case 'n':
								case 'N':
									break;
							}
						case 2: {
							std::cout << "Choose a client to delete\n";
							showClientOptions(agency);
							int choice = askChoice(
									"Enter the client number of order (0 to cancel): ");
							while (choice < 0 || (size_t) choice > agency.getClients().size()) {
								std::cout << "Invalid entry\n";
								choice = askChoice(
										"Enter the client number of order (0 to cancel): ");
							}

							if (choice != 0)
								switch (askYesNo(
										"Are you sure you want to delete the client (y / n) ?: ")) {
									case 'y':
									case 'Y':
										agency.deleteClient(choice - 1);
                                        agency.setUpdated(false);
										break;
									case 'n':
									case 'N':
										break;
								}
						}
							break;
						default:
							control = true;
							std::cout << "Invalid entry\n";
							break;
					}

				} while (control);
			}
				break;
			default:
				std::cout << "Invalid entry\n";
				break;
		}
	}
}

/**
 * Validate dates
 * Date must follow the format {year}/{month}/{day}
 * Year -> any integer
 * Month -> Integer between 1 and 12 (inclusive)
 * Day -> Integer between 1 and the number of days in that month of that year
 *
 * @param str container to deposit the date
 * @return whether the input was successful or not
 */
int inputDate(std::string &str) {

	int year = 0;
	UInt month = 0, day = 0;
	char sep1, sep2;

	std::cin >> year >> sep1 >> month >> sep2 >> day;

	if (std::cin.fail()) {
		std::cin.clear();
		clearInputBuffer();
		return 0;
	}

	if (sep1 != '/' || sep2 != '/')
		return 0;

	if (month < 1 || month > 12)
		return 0;

	if (day < 1 || day > days(month, year))
		return 0;

	str = std::to_string(year) + " " + std::to_string(month) + " " + std::to_string(day);
	return 1;
}

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
int inputZipCode(std::string &str) {

	UInt x, y;
	char op;

	std::cin >> x >> op >> y;

	if (std::cin.fail()) {
		std::cin.clear();
		clearInputBuffer();
		return 0;
	}

	if (op != '-')
		return 0;

	str = std::to_string(x) + " " + std::to_string(y);

	return 1;
}

/**
 * Evaluates if the year specified is a leap year
 *
 * @brief evaluates year as leap year or common year
 * @param year value of year (can be negative or positive (must be whole number))
 * @return if year is a leap year (1-> is leap; 0-> is common)
 */
bool leapYear(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

/**
 * Get the number of days of specified month of the specified year, number of days varies depending
 * if the year is leap or common (this variance only applies to one month)
 *
 * @brief get number of days in a month
 * @param month a number between 1-12 representing the month
 * @param year value of year (can be negative or positive (must be whole number))
 * @return number of days
 */
UInt days(UInt month, int year) {
	if ((month < 8 && month % 2 == 1) || (month >= 8 && month % 2 == 0))
		return 31;
	else if (month == 2)
		return leapYear(year) ? 29 : 28;

	return 30;
}

/**
 * Allows user to add/edit a client in the agency
 * For adding a new client position must be specified as -1 (or any negative number)
 * By default the value is already set to add a new client
 *
 * @brief allows user to add/edit a client in the agency
 * @param agency Agency object
 * @param at index to access client in the agency
 */
void clientMenu(Agency &agency, int at) {

	Client client;
	std::cout << TEXT_DELIMITER << "\n";
	if (at >= 0) {
		client = agency.getClient(at);
	} else {
		std::cout << "Adding a new client:\nLoaded default configurations\n\n";
	}
	bool control;
	while (true) {
		std::cout << TEXT_DELIMITER << "\nClient Info:\n";
		std::cout << "\t1. Name: " << client.getName() << "\n" << "\t2. NIF: "
				<< std::to_string(client.getNif()) << "\n" << "\t3. Address:\n"
				<< client.getAddress().formatTo_str("\t\t") << "\n" << "\t4. Family aggregate: "
				<< std::to_string(client.getFamilyAggr()) << "\n" << "\t5. Purchased packs:"
				<< (client.getPacksPurchased().empty() ? " NULL" : "") << "\n";
		for (const TravelPack &pack : client.getPacks())
			pack.showBasic("\t\t");

		do {
			control = false;
			switch (askChoice("Choose the line you want to edit (0 to finish): ")) {
				case 0: {
					switch (askYesNo("Are you sure you want to finish the client? (y / n)? ")) {
						case 'y':
						case 'Y': {

						    UInt moneySpent = 0;
						    for (const TravelPack &pack : client.getPacks()) {
						        moneySpent += pack.getPrice() * client.getFamilyAggr();
						    }
							client.setPurchasesValue(moneySpent);


							std::vector<int> temp;
							for (const TravelPack &pack : client.getPacks())
								temp.push_back(std::abs(pack.getIdentifier()));
							client.setPacksPurchased(temp);
							if (at < 0) {
								if (agency.containsClient(client)) {
									std::cout << "Sorry! This client already exists in the agency\n"
											<< "Please verify the information\n";
									break;
								}
								agency.pushClient(client);
                                agency.setUpdated(false);
								std::cout << "Client added to agency\n";
							} else {
								agency.setClient(client, at);
                                agency.setUpdated(false);
								std::cout << "Edits saved, client was updated successfully\n";
							}
						}
							return;
						case 'n':
						case 'N':
							switch (askYesNo("\nDo you want to cancel the process (y / n)? ")) {
								case 'y':
								case 'Y':
									return;
								case 'n':
								case 'N':
									break;
							}
					}
				}
					break;
				case 1: {
					clearInputBuffer();
					std::string name;
					std::cout << "Enter the client's name: ";
					while (!std::getline(std::cin, name)) {
						clearInputBuffer();
						std::cout << "Invalid entry\nEnter the client's name: ";
					}
					Client copy = client;
					copy.setName(trimNorm(name, " "));
					std::cout << "Client before edit:\n" << client << "\n" << "Client after edit:\n"
							<< copy << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							client = copy;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				case 2: {
					clearInputBuffer();
					ULLong nif = 0;
					std::cout << "Enter the client's NIF: ";
					while (!(std::cin >> nif)) {
						std::cin.clear();
						clearInputBuffer();
						std::cout << "Invalid entry\nEnter the client's NIF: ";
					}
					Client copy = client;
					copy.setNif(nif);
					std::cout << "Client before edit:\n" << client << "\n" << "Client after edit:\n"
							<< copy << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							client = copy;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				case 3:
					clearInputBuffer();
					addressMenu(client);
					break;
				case 4: {
					clearInputBuffer();
					UInt familyAggr = 0;
					std::cout << "Enter the client's number of people in family aggregate: ";
					while (!(std::cin >> familyAggr)) {
						clearInputBuffer();
						std::cout
								<< "Invalid entry\nEnter the client's number of people in family aggregate: ";
					}
					Client copy = client;
					copy.setFamilyAggr(familyAggr);
					std::cout << "Client before edit:\n" << client << "\n" << "Client after edit:\n"
							<< copy << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							client = copy;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				case 5: {
					std::cout << "Options available:\n" << "[1] Buy pack\n" << "[2] Remove pack\n";

					switch (askChoice("Enter your option (0 to cancel): ")) {
						case 0:
							std::cout << "Cancelling...";
						case 1: {
							std::cout << "Showing packs available:\n";
							std::vector < size_t > accessers = showPacksAvailableOptions(agency); // indexes of packs
							int choice = askChoice(
									"Enter the travel pack number of order (0 to cancel): ");
							while (choice < 0 || (size_t) choice > accessers.size()) {
								std::cout << "Invalid entry\n";
								choice = askChoice(
										"Enter the travel pack number of order (0 to cancel): ");
							}

							if (choice != 0) {
								TravelPack pack = agency.getPack(accessers.at(choice - 1));

								if (pack.getMaxPeople() - pack.getSold()
										>= client.getFamilyAggr()) {
									std::cout << "Buying pack for " << client.getFamilyAggr()
											<< " for: " << pack.getPrice() * client.getFamilyAggr()
											<< " euros\n";
									switch (askYesNo(
											"Do you want to proceed with the purchase (y / n)? ")) {
										case 'y':
										case 'Y':
											pack.setSold(pack.getSold() + client.getFamilyAggr());
											agency.setPack(pack, accessers.at(choice - 1));
											client.pushPack(pack);
											std::cout << "Pack bought\n";
											break;
										case 'n':
										case 'N':
											std::cout << "Canceling transaction...\n";
											break;
									}
								} else {
									std::cout
											<< "There's no sufficient tickets left for all the members of your family... We're sorry\n";
								}
							}
						}
						break;
						case 2: {
						    if (!client.getPacks().empty()) {
						        std::cout << "Removing client pack\n";

						        for (size_t i = 0; i < client.getPacks().size(); i++) {
                                    std::cout << "Pack " << i + 1 << ".\n";
                                    client.getPack(i).showBasic("\t");
                                    std::cout << "\n";
                                }

                                int choice = askChoice("Enter the pack number of order (0 to cancel): ");
                                while (choice < 0 || (size_t) choice > client.getPacks().size()) {
                                    std::cout << "Invalid entry\n";
                                    clearInputBuffer();
                                    choice = askChoice("Enter the pack number of order (0 to cancel): ");
                                }
                                clearInputBuffer();
                                if (choice != 0) {
                                    Client copy = client;
                                    copy.deletePack(choice - 1);

                                    std::cout << "Client before edit:\n" << client << "\n" << "Client after edit:\n"
                                              << copy << "\n";

                                    switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
                                        case 'y':
                                        case 'Y':
                                            client = copy;
                                            std::cout << "Saved edits\n";
                                            break;
                                        case 'n':
                                        case 'N':
                                            std::cout << "Cancelling edits...\n";
                                            break;
                                    }
                                }
						    }
						}
					}
				}
					break;
				default:
					std::cout << "Invalid entry\n";
					control = true;
					break;
			}

		} while (control);
	}
}

/**
 * Allows user to add/edit a travel pack in the agency
 * For adding a new travel pack position must be specified as -1 (or any negative number)
 * By default the value is already set to add a new travel pack
 *
 * @brief allows user to add/edit a travel pack in the agency
 * @param agency Agency object
 * @param at index to access travel pack in the agency
 */
void packMenu(Agency &agency, int at) {

	TravelPack pack;
	std::cout << TEXT_DELIMITER << "\n";
	if (at >= 0) {
		pack = agency.getPack(at);
	} else {
		std::cout << "Adding a new travel pack:\nLoaded default configurations\n\n";
	}
	bool control;
	while (true) {
		std::cout << TEXT_DELIMITER << "\nTravel Pack Info:\n";
		std::cout << "\t1. Unique Identifier: " << std::to_string(pack.getIdentifier()) << "\n"
				<< "\t2. Destiny: " << pack.getDestiny() << "\n" << "\t3. Places: "
				<< (!pack.getPlaces().empty() ? vectorToStr(pack.getPlaces(), ", ") : "Not specified")
				<< "\n" << "\t4. Begin date: " << pack.getBegin() << "\n" << "\t5. End date: "
				<< pack.getEnd() << "\n" << "\t6. Price: " << pack.getPrice() << " euros\n"
				<< "\t7. Max number of people: " << pack.getMaxPeople() << "\n"
				<< "\t8. Sold tickets: " << pack.getSold() << "\n";

		do {
			control = false;
			switch (askChoice("Choose the line you want to edit (0 to finish): ")) {
				case 0: {
					switch (askYesNo("Are you sure you want to finish the travel pack? (y / n)? ")) {
						case 'y':
						case 'Y': {
							if (at < 0) {
								if (agency.containsPack(pack)) {
									std::cout
											<< "Sorry! This travel pack already exists in the agency\n"
											<< "Please verify the information\n";
									break;
								}
								agency.pushPack(pack);
                                agency.setUpdated(false);
								std::cout << "Travel pack added to agency\n";
							} else {
								agency.setPack(pack, at);
                                agency.setUpdated(false);
								std::cout << "Edits saved, travel pack was updated successfully\n";
							}
						}
							return;
						case 'n':
						case 'N':
							switch (askYesNo("\nDo you want to cancel the process (y / n)? ")) {
								case 'y':
								case 'Y':
									return;
								case 'n':
								case 'N':
									break;
							}
					}
				}
					break;
				case 1: {
					clearInputBuffer();
					int identifier = 0;
					std::cout
							<< "Enter the travel pack's identifier (negative if pack not available): ";
					while (!(std::cin >> identifier) || identifier == 0) {
						clearInputBuffer();
						std::cout
								<< "Invalid entry\nEnter the travel pack's identifier (negative if pack not available): ";
					}
					TravelPack copy = pack;
					copy.setIdentifier(identifier);
					std::cout << "Travel Pack before edit:\n" << pack << "\n"
							<< "Travel Pack after edit:\n" << copy << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							pack = copy;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				case 2: {
					clearInputBuffer();
					std::string destiny;
					std::cout << "Enter the travel pack's destiny: ";
					while (!std::getline(std::cin, destiny)) {
						std::cin.clear();
						clearInputBuffer();
						std::cout << "Invalid entry\nEnter the travel pack's destiny: ";
					}
					TravelPack copy = pack;
					copy.setDestiny(trimNorm(destiny, " "));
					std::cout << "Travel Pack before edit:\n" << pack << "\n"
							<< "Travel Pack after edit:\n" << copy << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							pack = copy;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				case 3: {
					clearInputBuffer();
					std::string str;
					std::cout
							<< "Enter the travel pack's specific places (separate each place with a comma ','): ";
					while (!std::getline(std::cin, str)) {
						clearInputBuffer();
						std::cout
								<< "Invalid entry\nEnter the travel pack's specific places (separate each place with a comma ','): ";
					}

					std::vector < std::string > places;
					split(places, str, ",");
					for (std::string &s : places)
						str = trimNorm(s, " ");

					TravelPack copy = pack;
					copy.setPlaces(places);
					std::cout << "Travel Pack before edit:\n" << pack << "\n"
							<< "Travel Pack after edit:\n" << copy << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							pack = copy;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				case 4: {
					clearInputBuffer();
					Date begin;
					std::string str;
					std::stringstream ss;

					while (true) {

						std::cout << "Enter the begin date ({year}/{month}/{day}): ";
						str.clear();
						ss.clear();

						while (!inputDate(str)) {
							std::cout
									<< "Invalid entry\nEnter the begin date ({year}/{month}/{day}): ";
							str.clear();
						}

						ss << str;
						ss >> begin;
						if (pack.getEnd().getDay() == 0 || pack.getEnd().getMonth() == 0
								|| begin <= pack.getEnd()) {
							break;
						} else {
							std::cout << "Invalid entry\nBegin date before end date "
									<< pack.getEnd() << "\n";
							begin.clear();
						}
					}
					TravelPack copy = pack;
					copy.setBegin(begin);
					std::cout << "Travel Pack before edit:\n" << pack << "\n"
							<< "Travel Pack after edit:\n" << copy << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							pack = copy;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				case 5: {
					clearInputBuffer();
					Date end;
					std::string str;
					std::stringstream ss;

					while (true) {

						std::cout << "Enter the end date ({year}/{month}/{day}): ";
						str.clear();
						ss.clear();

						while (!inputDate(str)) {
							std::cout
									<< "Invalid entry\nEnter the end date ({year}/{month}/{day}): ";
							str.clear();
						}

						ss << str;
						ss >> end;
						if (pack.getBegin().getDay() == 0 && pack.getBegin().getMonth() == 0
								&& end >= pack.getBegin()) {
							break;
						} else {
							std::cout << "Invalid entry\nEnd date before begin date "
									<< pack.getBegin() << "\n";
							end.clear();
						}
					}
					TravelPack copy = pack;
					copy.setEnd(end);
					std::cout << "Travel Pack before edit:\n" << pack << "\n"
							<< "Travel Pack after edit:\n" << copy << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							pack = copy;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				case 6: {
					clearInputBuffer();
					UInt price = 0;
					std::cout << "Enter the travel pack's price: ";
					while (!(std::cin >> price)) {
						clearInputBuffer();
						std::cout << "Invalid entry\nEnter the travel pack's price: ";
					}
					TravelPack copy = pack;
					copy.setPrice(price);
					std::cout << "Travel Pack before edit:\n" << pack << "\n"
							<< "Travel Pack after edit:\n" << copy << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							pack = copy;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				case 7: {
					clearInputBuffer();
					UInt maxPeople = 0;
					std::cout << "Enter the travel pack's max number of people: ";
					while (!(std::cin >> maxPeople) || maxPeople < pack.getSold()) {
						clearInputBuffer();
						std::cout
								<< "Invalid entry\nEnter the travel pack's max number of people: ";
					}
					TravelPack copy = pack;
					copy.setMaxPeople(maxPeople);
					std::cout << "Travel Pack before edit:\n" << pack << "\n"
							<< "Travel Pack after edit:\n" << copy << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							pack = copy;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				case 8: {
					clearInputBuffer();
					UInt sold = 0;
					std::cout << "Enter the travel pack's number of tickets sold: ";
					while (!(std::cin >> sold) || sold > pack.getMaxPeople()) {
						clearInputBuffer();
						std::cout << "Invalid entry\nEnter the travel pack's price: ";
					}
					TravelPack copy = pack;
					copy.setSold(sold);
					std::cout << "Travel Pack before edit:\n" << pack << "\n"
							<< "Travel Pack after edit:\n" << copy << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							pack = copy;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				default:
					std::cout << "Invalid entry\n";
					control = true;
					break;
			}

		} while (control);
	}
}

/**
 * Allows user to add/edit address of a client
 *
 * @brief menu to edit address of a client
 * @overload void addressMenu(Client &client)
 * @param client Client object to be modified
 */
void addressMenu(Client &client) {
	bool control;
	Address address = client.getAddress();
	while (true) {
		std::cout << TEXT_DELIMITER << "\nClient " << client.getName() << " Address Info:\n";
		std::cout << "\t1. City: " << address.getCity() << "\n" << "\t2. Road: "
				<< address.getRoad() << "\n" << "\t3. Door Number: "
				<< std::to_string(address.getDoorNumber()) << "\n" << "\t4. Floor: "
				<< address.getFloor() << "\n" << "\t5. Zip-Code: " << address.zipCodeTo_str()
				<< "\n";

		do {
			control = false;
			switch (askChoice("Choose the line you want to edit (0 to finish): ")) {
				case 0: {
					switch (askYesNo("Are you sure you want to finish the address? (y / n)? ")) {
						case 'y':
						case 'Y':
							client.setAddress(address);
							std::cout << "Edits saved, client was updated successfully\n";

							return;
						case 'n':
						case 'N':
							switch (askYesNo("\nDo you want to cancel the process (y / n)? ")) {
								case 'y':
								case 'Y':
									return;
								case 'n':
								case 'N':
									break;
							}
					}
				}
					break;
				case 1: {
					clearInputBuffer();
					std::string city;
					std::cout << "Enter the city: ";
					while (!std::getline(std::cin, city)) {
						clearInputBuffer();
						std::cout << "Invalid entry\nEnter the city: ";
					}
					Address copy = address;
					copy.setCity(trimNorm(city, " "));
					std::cout << "Address before edit:\n" << address << "\n"
							<< "Address after edit:\n" << copy << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							address = copy;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				case 2: {
					clearInputBuffer();
					std::string road;
					std::cout << "Enter the road: ";
					while (!std::getline(std::cin, road)) {
						std::cin.clear();
						clearInputBuffer();
						std::cout << "Invalid entry\nEnter the road: ";
					}
					Address copy = address;
					copy.setRoad(trimNorm(road, " "));
					std::cout << "Address before edit:\n" << address << "\n"
							<< "Address after edit:\n" << copy << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							address = copy;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				case 3: {
					clearInputBuffer();
					UInt doorNumber = 0;
					std::cout << "Enter the door number: ";
					while (!(std::cin >> doorNumber)) {
						clearInputBuffer();
						std::cout << "Invalid entry\nEnter the door number: ";
					}
					Address copy = address;
					copy.setDoorNumber(doorNumber);
					std::cout << "Address before edit:\n" << address << "\n"
							<< "Address after edit:\n" << copy << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							address = copy;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				case 4: {
					clearInputBuffer();
					std::string floor;
					std::cout << "Enter the floor (Enter '-' if there is no floor information): ";
					while (!std::getline(std::cin, floor)) {
						clearInputBuffer();
						std::cout
								<< "Invalid entry\nEnter the floor (Enter '-' if there is no floor information): ";
					}
					Address copy = address;
					copy.setFloor(trimNorm(floor, " "));
					std::cout << "Address before edit:\n" << client << "\n"
							<< "Address after edit:\n" << copy << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							address = copy;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				case 5: {
					clearInputBuffer();
					std::string str;
					std::cout << "Enter the zip-code ({code}-{code}): ";
					while (!inputZipCode(str))
						std::cout << "Invalid entry\nEnter the zip-code ({code}-{code}): ";

					std::stringstream ss(str);
					UInt x, y;
					ss >> x >> y;
					Address copy = address;
					copy.setZipCode(x, y);
					std::cout << "Address before edit:\n" << client << "\n"
							<< "Address after edit:\n" << copy << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							address = copy;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				default:
					std::cout << "Invalid entry\n";
					control = true;
					break;
			}

		} while (control);
	}
}

/**
 * Allows user to add/edit address of an agency
 *
 * @brief menu to edit address of a agency
 * @overload void addressMenu(Agency &agency)
 * @param agency Agency object to be modified
 */
void addressMenu(Agency &agency) {
	bool control;
	Address address = agency.getAddress();
	while (true) {
		std::cout << TEXT_DELIMITER << "\nAgency Address Info:\n";
		std::cout << "\t1. City: " << address.getCity() << "\n" << "\t2. Road: "
				<< address.getRoad() << "\n" << "\t3. Door Number: "
				<< std::to_string(address.getDoorNumber()) << "\n" << "\t4. Floor: "
				<< address.getFloor() << "\n" << "\t5. Zip-Code: " << address.zipCodeTo_str()
				<< "\n";

		do {
			control = false;
			switch (askChoice("Choose the line you want to edit (0 to finish): ")) {
				case 0: {
					switch (askYesNo("Are you sure you want to finish the address? (y / n)? ")) {
						case 'y':
						case 'Y':
							agency.setAddress(address);
							std::cout << "Edits saved, agency was updated successfully\n";

							return;
						case 'n':
						case 'N':
							switch (askYesNo("\nDo you want to cancel the process (y / n)? ")) {
								case 'y':
								case 'Y':
									return;
								case 'n':
								case 'N':
									break;
							}
					}
				}
					break;
				case 1: {
					clearInputBuffer();
					std::string city;
					std::cout << "Enter the city: ";
					while (!std::getline(std::cin, city)) {
						clearInputBuffer();
						std::cout << "Invalid entry\nEnter the city: ";
					}
					Address copy = address;
					copy.setCity(trimNorm(city, " "));
					std::cout << "Address before edit:\n" << address << "\n"
							<< "Address after edit:\n" << copy << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							address = copy;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				case 2: {
					clearInputBuffer();
					std::string road;
					std::cout << "Enter the road: ";
					while (!std::getline(std::cin, road)) {
						std::cin.clear();
						clearInputBuffer();
						std::cout << "Invalid entry\nEnter the road: ";
					}
					Address copy = address;
					copy.setRoad(trimNorm(road, " "));
					std::cout << "Address before edit:\n" << address << "\n"
							<< "Address after edit:\n" << copy << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							address = copy;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				case 3: {
					clearInputBuffer();
					UInt doorNumber = 0;
					std::cout << "Enter the door number: ";
					while (!(std::cin >> doorNumber)) {
						clearInputBuffer();
						std::cout << "Invalid entry\nEnter the door number: ";
					}
					Address copy = address;
					copy.setDoorNumber(doorNumber);
					std::cout << "Address before edit:\n" << address << "\n"
							<< "Address after edit:\n" << copy << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							address = copy;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				case 4: {
					clearInputBuffer();
					std::string floor;
					std::cout << "Enter the floor (Enter '-' if there is no floor information): ";
					while (!std::getline(std::cin, floor)) {
						clearInputBuffer();
						std::cout
								<< "Invalid entry\nEnter the floor (Enter '-' if there is no floor information): ";
					}
					Address copy = address;
					copy.setFloor(trimNorm(floor, " "));
					std::cout << "Address before edit:\n" << address << "\n"
							<< "Address after edit:\n" << copy << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							address = copy;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				case 5: {
					clearInputBuffer();
					std::string str;
					std::cout << "Enter the zip-code ({code}-{code}): ";
					while (!inputZipCode(str))
						std::cout << "Invalid entry\nEnter the zip-code ({code}-{code}): ";

					std::stringstream ss(str);
					UInt x, y;
					ss >> x >> y;
					Address copy = address;
					copy.setZipCode(x, y);
					std::cout << "Address before edit:\n" << address << "\n"
							<< "Address after edit:\n" << copy << "\n";

					switch (askYesNo("Are you sure you want to save the edits (y / n)? ")) {
						case 'y':
						case 'Y':
							address = copy;
							std::cout << "Saved edits\n";
							break;
						case 'n':
						case 'N':
							std::cout << "Cancelling edits...\n";
							break;
					}
				}
					break;
				default:
					std::cout << "Invalid entry\n";
					control = true;
					break;
			}

		} while (control);
	}
}

/**
 * Shows all clients available, only showing the essential
 * "Client {number of order}: {client's name}"
 *
 * @brief show all client options in agency
 * @param agency Agency object
 * @see Agency
 */
void showClientOptions(const Agency &agency) {

	if (agency.getClients().empty()) {
		std::cout << "This agency has no clients yet\n";
		return;
	}

	for (size_t i = 0; i < agency.getClients().size(); i++)
		std::cout << "Client " << i + 1 << ": " << agency.getClient(i).getName() << "(NIF: " << agency.getClient(i).getNif() << ")" <<  "\n";
}

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
void showPacksOptions(const Agency &agency) {

	if (agency.getPacks().empty()) {
		std::cout << "This agency has no travel packs yet\n";
		return;
	}

	for (size_t i = 0; i < agency.getPacks().size(); i++) {
		std::cout << "\nTravel Pack " << i + 1 << ":\n";
		agency.getPack(i).showBasic("\t");
	}
}

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
std::vector<size_t> showPacksAvailableOptions(const Agency &agency) {
	// TODO: Think of another way to have the return type or handle the indexes
	if (agency.getPacks().empty()) {
		std::cout << "This agency has no travel packs yet\n";
		return {};
	}
	std::vector < size_t > indexes;
	for (size_t i = 0; i < agency.getPacks().size(); i++) {
		if (agency.getPack(i).getIdentifier() > 0) {
			std::cout << "\nTravel Pack " << indexes.size() + 1 << ":\n";
			indexes.push_back(i);
			agency.getPack(i).showBasic("\t");
		}
	}
	return indexes;
}

/**
 * If anything is still on the input buffer it gets ignored
 *
 * @brief clears std::cin input buffer
 * @see std::cin
 */
void clearInputBuffer(void) {
    char c;
	if (std::cin.peek() != std::string::traits_type::eof()) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.clear();
    }
}

/**
 * Asks user to input an answer to a question passed as a message
 * The only answers accepted are 'y' or 'n' (not case-sensitive)
 * If answer doesn't match, it keeps asking till user forfeits
 *
 * @brief asks user to input 'y' or 'n' (not case-sensitive)
 * @param message Message to display to user before asking
 * @return client's choice
 */
char askYesNo(const std::string &message) {
	std::cout << message;
	char c;
	std::cin >> c;

	while (std::cin.fail() || (c != 'y' && c != 'Y' && c != 'n' && c != 'N')) {
		std::cout << "Invalid input\n" << message;
		std::cin.clear();
		clearInputBuffer();
		std::cin >> c;
	}
	clearInputBuffer();
	return c;
}

/**
 * Asks user to input an answer to a question passed as a message
 * The answer can be any number in the range of signed integer
 * If any error occurs during input, choice is automatically put as -1
 *
 * @brief asks user to input his choice
 * @param message Message to display to user before asking
 * @return client's choice (-1 if error on reading)
 */
int askChoice(const std::string &message) {
	int choice = 0;

	std::cout << message;
	std::cin >> choice;

	if (std::cin.fail()) {
		std::cin.clear();
		choice = -1;
    }
	clearInputBuffer();

	return choice;
}

/**
 * Tests if an agency given already exists in the container of agencies (vector)
 * Returning true if it already exists, otherwise false
 *
 * @brief tests if vector already contains the agency given
 * @param agencies Vector of agencies containing all the agencies open
 * @param agency Agency to test if already exists if vector
 * @return if agency already exists
 */
//bool containsAgency(const std::vector<Agency> &agencies, const Agency &agency) {
//	for (const Agency &other : agencies)
//		if (agency == other)
//			return true;
//
//	return false;
//}

/**
 *
 * @param agency
 */
void showStatistics(Agency &agency) {
	agency.updateVisitedPlaces();
	std::map<std::string, UInt> map = agency.getVisitedPlaces();
	std::vector < std::string > places;
	places.reserve(map.size());

	double percentageSold = 0;
	UInt sold = 0, total = 0;

	for (const TravelPack &pack : agency.getPacks()) {
        sold += pack.getSold();
        total += pack.getMaxPeople();
	}

	percentageSold = (double) sold / total * 100;

    std::cout << "Percentage of packs sold: " << percentageSold << "%\n";

	for (const auto &element : map)
		places.push_back(element.first);

	// not working TODO: figure out why, maybe because of the assign of map and the function getVisitedPlaces
	//std::transform(map.begin(), map.end(), places.begin(), RetrieveKey());

	std::sort(places.begin(), places.end(), [map](std::string s1, std::string s2) {
		return map.at(s1) > map.at(s2) || (map.at(s1) == map.at(s2) && s1 <= s2);
	});
    UInt n = -1;
    clearInputBuffer();
	std::cout << "Showing the N most visited places, enter a value for N: ";
	std::cin >> n;
    if(std::cin.fail()) {
        std::cin.clear();
        n = -1;
    }
    clearInputBuffer();

    if (n <= places.size()) {
        places.erase(places.begin() + n, places.end());
    }

	for (size_t i = 0; i < places.size(); i++)
		std::cout << i + 1 << ". " << places.at(i) << "\n";

	// SHOW CLIENTS

	switch(askYesNo(("Show possible packs for clients (y / n)? "))) {
	    case 'y':
	    case 'Y':
        {
            bool visited = false;
            bool control = true;
            for (const Client &client : agency.getClients()) {
                for (const std::string &str : places) {
                    for (const TravelPack &pack : client.getPacks()) {
                        if (vectorContains(pack.getPlaces(), str)) {
                            visited = true;
                            break;
                        }
                    }

                    if (!visited) {
                        for (const TravelPack &pack : agency.getPacks()) {
                            if (pack.getIdentifier() > 0 && vectorContains(pack.getPlaces(), str)) {
                                std::cout << "Client " << client.getName() << "(NIF: " << client.getNif() << ") recommended pack is:\n";
                                pack.showBasic("\t");
                                control = false;
                                break;
                            }
                        }
                        if (!control)
                            break;
                    }
                }
                if (control)
                    std::cout << "Client " << client.getName() << "(NIF: " << client.getNif() << "): No recommended pack was found\n";
            }
            std::cout << "\n";
        }
	        break;
	    case 'n':
	    case 'N':
	        break;
	}

}
