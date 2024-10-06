//============================================================================
// Name        : DS3BuildTracker
// Author      : Syd Nivraam
// Version     : 0.2
// Description : Hello World in C++, Ansi-style; reads data from .csv
//               files in order for user to create and save DS3 builds.
// Credits     : Weapons spreadsheet by u/D_VoN on reddit https://www.reddit.com/r/darksouls3/comments/4fo66t/dark_souls_iii_weapons_spreadsheet/
//             : Armor spreadsheet by naiyt on GoogleDocs https://docs.google.com/spreadsheets/d/1OVGVtjCgkoFPEvtCKHx7dh9tXVplMbft4iUSY_Inm_I/edit#gid=0
//             : Sorceries spreadsheet self made using data from https://darksouls3.wiki.fextralife.com/Sorceries
//             : Miracles spreadsheet self made using data from https://darksouls3.wiki.fextralife.com/Miracles
//             : Pyromancies spreadsheet self made using data from https://darksouls3.wiki.fextralife.com/Pyromancies
//============================================================================

#include "CSVParser.h"
#include "Menus.h"
#include "Displays.h"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

const string CSV_PATH_WEAPON = "Dark_Souls_3_Weapons_Normal.csv";
const string CSV_PATH_SHIELD = "Dark_Souls_3_Shields.csv";
const string CSV_PATH_ARMOR = "Dark_Souls_3_Armor_Data.csv";
const string CSV_PATH_SORCERY = "Dark_Souls_3_Sorceries.csv";
const string CSV_PATH_MIRACLE = "Dark_Souls_3_Miracles.csv";
const string CSV_PATH_PYROMANCY = "Dark_Souls_3_Pyromancies.csv";

struct Build
{
    int buildID = -1;
    Weapon weaponR1;
    Weapon weaponR2;
    Weapon weaponR3;
    Weapon weaponL1;
    Weapon weaponL2;
    Weapon weaponL3;
    Armor armorHead;
    Armor armorChest;
    Armor armorLeg;
    Armor armorFeet;
};

int main()
{
    vector<Weapon> weaponList = loadWeapons(CSV_PATH_WEAPON);
    vector<Shield> shieldList = loadShields(CSV_PATH_SHIELD);
    vector<Armor> armorList = loadArmor(CSV_PATH_ARMOR);
    vector<Sorcery> sorceryList = loadSorceries(CSV_PATH_SORCERY);
    vector<Miracle> miracleList = loadMiracles(CSV_PATH_MIRACLE);
    vector<Pyromancy> pyromancyList = loadPyromancies(CSV_PATH_PYROMANCY);

    int choice = 0;

    cout << "Welcome to Dark Souls 3 Build Tracker\n" << endl;
    while (choice != 99)
    {
        cout << "********************************************" << endl;
        cout << "*                  ******                  *" << endl;
        cout << "*              ~* Main Menu *~             *" << endl;
        cout << "*                  ******                  *" << endl;
        cout << "*                                          *" << endl;
        cout << "*  1. Weapons & Shields                    *" << endl;
        cout << "*  2. Armor                                *" << endl;
        cout << "*  3. Magic                                *" << endl;
        cout << "*  9. New Build                            *" << endl;
        cout << "*  10. Load Build                          *" << endl;
        cout << "*  99. Exit                                *" << endl;
        cout << "*                                          *" << endl;
        cout << "********************************************" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;

        if (choice == 1)
        {
            weaponMenu(weaponList, shieldList);
        }

        if (choice == 2)
        {
            armorMenu(armorList);
        }

        
        if (choice == 3)
        {
            magicMenu(sorceryList, miracleList, pyromancyList);
        }

        /*fix me
         if (choice) == 9)
         {
         new build
         }
         */

        /*fix me
         if (choice) == 10)
         {
         load build
         }
         */

        else if (choice != 99)
        {
            cout << "\nInvalid choice.\nPlease enter a number corresponding to the menu's available options.\n" << endl;
            cin.clear();
        }
    }

    cout << "\nGood bye." << endl;
    return 0;
}
