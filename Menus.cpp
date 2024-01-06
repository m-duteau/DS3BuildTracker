#include "Menus.h"

/*
* Displays the menu that contains commands for displaying different weapons data
*/
void weaponMenu(std::vector<Weapon> weaponList) {
    std::string input; // stores user input
    Weapon weapon;
    int choice = 0;

    while (choice != 99) {
        std::cout << "********************************************" << std::endl;
        std::cout << "*                * Weapons *               *" << std::endl;
        std::cout << "*                                          *" << std::endl;
        std::cout << "*  1. Display All Weapons                  *" << std::endl;
        std::cout << "*  2. Display All Weapons and Attributes   *" << std::endl;
        std::cout << "*  3. Display Weapons by Type              *" << std::endl;
        std::cout << "*  4. Print Individual Weapon Information  *" << std::endl;
        std::cout << "*  99. Return to Main Menu                 *" << std::endl;
        std::cout << "********************************************" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cout << std::endl;

        if (choice == 1) {
            std::cout << "\n----------------------------------------------------" << std::endl;
            for (int i = 0; i < weaponList.size(); ++i) {
                std::cout << weaponList[i].weaponID << ": " << weaponList[i].weaponName << std::endl;
            }
            std::cout << "----------------------------------------------------\n" << std::endl;
        }

        else if (choice == 2) {
            std::cout << "\n----------------------------------------------------" << std::endl;
            for (int i = 0; i < weaponList.size(); ++i) {
                displayWeapon(weaponList.at(i));
            }
            std::cout << "----------------------------------------------------\n" << std::endl;
        }

        else if (choice == 3) {
            std::vector<std::string> weaponTypes = { "Axe", "Bow", "Claw", "Crossbow", "Curved Greatsword",
            "Curved Sword", "Dagger", "Fist", "Great Hammer", "Greataxe", "Greatbow", "Greatsword",
            "Halberd", "Hammer", "Katana", "Piercing Sword", "Reaper", "Sacred Chime", "Spear", 
            "Staff", "Straight Sword", "Talisman", "Ultra Greatsword", "Whip" };

            std::cout << "Weapon Types:" << std::endl;
            for (int i = 0; i < weaponTypes.size(); ++i) {
                std::cout << "  " << i + 1 << ". " << weaponTypes.at(i) << std::endl;
                if (i == 23) {
                    std::cout << "\n";
                }
            }

            std::cout << "Select Weapon Type: ";
            std::cin >> input;
            std::cout << std::endl;
            if (stoi(input) > 0 && stoi(input) < 25) {
                for (int i = 0; i < weaponList.size(); ++i) {
                    if (weaponList[i].weaponType == weaponTypes.at(stoi(input) - 1)) {
                        displayWeapon(weaponList.at(i));
                    }
                }
            }
            else {
                std::cout << "nope.\n" << std::endl;
            }
        }

        else if (choice == 4) {
            std::cout << "\nEnter the weapon ID to be displayed: ";
            std::cin >> input;
            std::cout << std::endl;
            for (int i = 0; i < weaponList.size(); ++i) {
                if (weaponList[i].weaponID == stoi(input)) {
                    displayWeapon(weaponList.at(i));
                    std::cout << "\n";
                }
                else if (stoi(input) > 189 || stoi(input) < 1) {
                    if (i == weaponList.size() - 1) {
                        std::cout << "Weapon ID not found.\n" << std::endl;
                    }
                }
            }
        }

        else if (choice != 99) {
            std::cout << "\nInvalid choice.\nPlease enter a number corresponding to the menu's available options.\n" << std::endl;
            std::cin.clear();
        }
    }
}

/*
* Displays the menu that contains commands for displaying different armor data
*/
void armorMenu(std::vector<Armor> armorList) {
    std::string input;
    Armor armor;
    int choice = 0;

    while (choice != 99) {
        std::cout << "********************************************" << std::endl;
        std::cout << "*                 * Armor *                *" << std::endl;
        std::cout << "*                                          *" << std::endl;
        std::cout << "*  1. Display All Armor                    *" << std::endl;
        std::cout << "*  2. Display All Armor and Attributes     *" << std::endl;
        std::cout << "*  3. Display Armor Sets                   *" << std::endl;
        std::cout << "*  4. Print Individual Armor Information   *" << std::endl;
        std::cout << "*  99. Return to Main Menu                 *" << std::endl;
        std::cout << "********************************************" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cout << std::endl;

        if (choice == 1) {
            std::cout << "\n----------------------------------------------------" << std::endl;
            for (int i = 0; i < armorList.size(); ++i) {
                std::cout << armorList[i].armorID << ": " << armorList[i].armorName << std::endl;
            }
            std::cout << "----------------------------------------------------\n" << std::endl;
        }

        else if (choice == 2) {
            std::cout << "\n----------------------------------------------------" << std::endl;
            for (int i = 0; i < armorList.size(); ++i) {
                displayArmor(armorList.at(i));
                if (i < 324) {
                    std::cout << "\n--------------------\n" << std::endl;
                }
                else {
                    std::cout << "\n" << std::endl;
                }
            }
            std::cout << "----------------------------------------------------\n" << std::endl;
        }

        else if (choice == 3) {
            std::vector<std::string> armorSets = { "Alva Set", "Antiquated Set", "Archdeacon Set", "Aristocrat's Set",
            "Armor of Favor Set", "Armor of the Sun Set", "Armor of Thorns Set", "Assassin Set", "Black Set",
            "Black Hand Set", "Black Iron Set", "Black Knight Set", "Black Leather Set", "Brass Set", "Brigand Set", 
            "Catarina Set", "Cathedral Knight Set", "Chain Set", "Clandestine Set", "Cleric Set", "Conjurator Set", 
            "Cornyx's Set", "Court Sorcerer Set", "Dancer's Set", "Dark Set", "Deacon Set", "Deserter Set", 
            "Dragonscale Set", "Dragonslayer Set", "Drakeblood Set", "Drang Set", "Eastern Set", "Elite Knight Set", 
            "Evangelist Set", "Executioner Set", "Exile Set", "Fallen Knight Set", "Faraam Set", "Fire Keeper Set", 
            "Fire Witch Set", "Firelink Set", "Follower Set", "Grave Warden Set", "Gundyr's Set", "Hard Leather Set", 
            "Havel's Set", "Herald Set", "Jailer Set", "Karla's Set", "Knight Set", "Leather Set", "Leonhard's Set", 
            "Loincloth Set", "Lorian's Set", "Lothric Knight Set", "Maiden Set", "Master's Set", "Millwood Set",
            "Mirrah Set", "Mirrah Chain Set", "Morne's Set", "Nameless Knight Set", "Northern Set", "Old Sorcerer Set", 
            "Ordained Set", "Outrider Knight Set", "Painting Guarding Set", "Pale Shade Set", "Pontiff Knight Set", 
            "Prayer Set", "Pyromancer Set", "Ragged Mask Set", "Sage's Big Hat Set", "Scholar's Robe Set", "Sellsword Set", 
            "Shadow Set", "Silver Knight Set", "Slave Set", "Smough's Set", "Sorcerer Set", "Sunless Set", "Sunset Set", 
            "Symbol of Avarice Set", "Thrall Set", "Undead Legion Set", "Vilhelm's Set", "Winged Knight Set", "Worker Set", 
            "Xanthous Set", "Wolf Knight Set", "Wolnir's Set" };

            std::cout << "Armor Sets:" << std::endl;
            for (int i = 0; i < armorSets.size(); ++i) {
                std::cout << "  " << i + 1 << ". " << armorSets.at(i) << std::endl;
                if (i == 90) {
                    std::cout << "\n";
                }
            }

            std::cout << "Select Armor Set: ";
            std::cin >> input;
            std::cout << std::endl;
            if (stoi(input) > 0 && stoi(input) < 92) {
                for (int i = 0; i < armorList.size(); ++i) {
                    if (armorList[i].armorSet == armorSets.at(stoi(input) - 1)) {
                        displayArmor(armorList.at(i));
                    }
                }
            }
            else {
                std::cout << "nope.\n" << std::endl;
            }
        }

        else if (choice == 4) {
            std::cout << "\nEnter the armor ID to be displayed: ";
            std::cin >> input;
            std::cout << std::endl;
            for (int i = 0; i < armorList.size(); ++i) {
                if (armorList[i].armorID == stoi(input)) {
                    displayArmor(armorList.at(i));
                    std::cout << "\n";
                }
                else if (stoi(input) > 325 || stoi(input) < 1) {
                    if (i == armorList.size() - 1) {
                        std::cout << "Armor ID not found.\n" << std::endl;
                    }
                }
            }
        }

        else if (choice != 99) {
            std::cout << "\nInvalid choice.\nPlease enter a number corresponding to the menu's available options.\n" << std::endl;
            std::cin.clear();
        }
    }
}

/*
* Displays the menu that contains commands for displaying different sorcery data
*/
void sorceryMenu(std::vector<Sorcery> sorceryList) {
    std::string input;
    Sorcery sorcery;
    int choice = 0;

    while (choice != 99) {
        std::cout << "********************************************" << std::endl;
        std::cout << "*               * Sorceries *              *" << std::endl;
        std::cout << "*                                          *" << std::endl;
        std::cout << "*  1. Display All Sorceries                *" << std::endl;
        std::cout << "*  2. Display All Sorceries and Attributes *" << std::endl;
        std::cout << "*  3. Print Individual Sorcery Information *" << std::endl;
        std::cout << "*  99. Return to Main Menu                 *" << std::endl;
        std::cout << "********************************************" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cout << "\n";

        if (choice == 1) {
            std::cout << "\n----------------------------------------------------" << std::endl;
            for (int i = 0; i < sorceryList.size(); ++i) {
                std::cout << sorceryList[i].sorceryID << ": " << sorceryList[i].sorceryName << std::endl;
            }
            std::cout << "----------------------------------------------------\n" << std::endl;
        }

        else if (choice == 2) {
            std::cout << "\n----------------------------------------------------" << std::endl;
            for (int i = 0; i < sorceryList.size(); ++i) {
                displaySorcery(sorceryList.at(i));
            }
            std::cout << "\n----------------------------------------------------\n" << std::endl;
        }

        else if (choice == 3) {
            std::cout << "\nEnter the Sorcery ID to be displayed: ";
            std::cin >> input;
            std::cout << "\n";
            for (int i = 0; i < sorceryList.size(); ++i) {
                if (sorceryList[i].sorceryID == stoi(input)) {
                    displaySorcery(sorceryList.at(i));
                    std::cout << "\n";
                }
                else if (stoi(input) > 38 || stoi(input) < 1) {
                    if (i == sorceryList.size() - 1) {
                        std::cout << "Sorcery ID not found.\n" << std::endl;
                    }
                }
            }
            std::cout << "\n";
        }

        else if (choice != 99) {
            std::cout << "\nInvalid choice.\nPlease enter a number corresponding to the menu's available options.\n" << std::endl;
            std::cin.clear();
        }
    }
}