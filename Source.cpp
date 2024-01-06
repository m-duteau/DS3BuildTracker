//============================================================================
// Name        : DS3BuildTracker
// Author      : Syd Nivraam
// Version     : 0.1
// Description : Hello World in C++, Ansi-style; reads data from .csv
//               files in order for user to create and save DS3 builds.
// Credits     : Weapons spreadsheet by u/D_VoN on reddit https://www.reddit.com/r/darksouls3/comments/4fo66t/dark_souls_iii_weapons_spreadsheet/
//             : Armor spreadsheet by naiyt on GoogleDocs https://docs.google.com/spreadsheets/d/1OVGVtjCgkoFPEvtCKHx7dh9tXVplMbft4iUSY_Inm_I/edit#gid=0
//             : Sorceries spreadsheet self made using data from https://darksouls3.wiki.fextralife.com/Sorceries
//============================================================================

#include "CSVParser.h"
#include "Menus.h"
#include "Displays.h"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

struct Build {
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

int main() {
    string csvPathWeapon = "Dark_Souls_3_Weapons_Normal.csv";
    string csvPathArmor = "Dark_Souls_3_Armor_Data.csv";
    string csvPathSorceries = "Dark_Souls_3_Sorceries.csv";
    vector<Weapon> weaponList = loadWeapons(csvPathWeapon);
    vector<Armor> armorList = loadArmor(csvPathArmor);
    vector<Sorcery> sorceryList = loadSorceries(csvPathSorceries);

    int choice = 0;

    cout << "Welcome to Dark Souls 3 Build Tracker\n" << endl;
    while (choice != 99) {
        cout << "********************************************" << endl;
        cout << "*                  ******                  *" << endl;
        cout << "*              ~* Main Menu *~             *" << endl;
        cout << "*                  ******                  *" << endl;
        cout << "*                                          *" << endl;
        cout << "*  1. Weapons                              *" << endl;
        cout << "*  2. Armor                                *" << endl;
        cout << "*  3. Sorceries                            *" << endl;
        cout << "*  9. New Build                            *" << endl;
        cout << "*  10. Load Build                          *" << endl;
        cout << "*  99. Exit                                *" << endl;
        cout << "*                                          *" << endl;
        cout << "********************************************" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;

        if (choice == 1) {
            weaponMenu(weaponList);
        }

        if (choice == 2) {
            armorMenu(armorList);
        }

        
        if (choice == 3) {
            sorceryMenu(sorceryList);
        }

        /*fix me
         if (choice) == 9) {
         new build
         }
         */

        /*fix me
         if (choice) == 10) {
         load build
         }
         */

        else if (choice != 99) {
            cout << "\nInvalid choice.\nPlease enter a number corresponding to the menu's available options.\n" << endl;
            cin.clear();
        }
    }

    cout << "\nGood bye." << endl;
    return 0;
}
