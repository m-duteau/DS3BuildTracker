#include "CSVParser.h"

/*
 * method for string splitting in loadWeapons() method
 * reference: https://stackoverflow.com/a/46931770/19361783
 *
 * @param str String to be split
 * @param delimiter Char used to determine where the string is to be split
 */
std::vector<std::string> splitString(std::string str, char delimiter) {
    std::vector<std::string> results; // stores individual substrings of str param resulting from the split
    std::stringstream ss(str); // creates stream to parse the string in str param 
    std::string item; // holds the current substring to be stored in results vector

    while (getline(ss, item, delimiter)) {
        results.push_back(item);
    }

    return results;
}

/*
 * Load a .csv file containing weapon information into a container
 *
 * @param csvPath the path to the .csv file to load
 * @return a container holding all the weapons read
 */
std::vector<Weapon> loadWeapons(std::string csvPath) {
    std::cout << "--- Loading file " << csvPath << " ---\n" << std::endl;

    std::vector<Weapon> weaponList;
    std::vector<std::string> fileLines; // holds individual lines of the .csv being read
    std::ifstream weaponsFile; // instance to load the .csv
    weaponsFile.open(csvPath);

    if (weaponsFile.is_open()) {
        while (weaponsFile.good()) {
            std::string line; // holds the current line being read
            std::getline(weaponsFile, line);
            // add the line to fileLines if the line is not empty/blank
            if (line != "")
                fileLines.push_back(line);
        }
        weaponsFile.close();

        // checks that data was actually read from the file
        // i.e. if fileLines is empty, then nothing was read from the file
        if (fileLines.size() == 0) {
            std::cout << "No data was found in " << csvPath << "." << std::endl;
        }
    }

    // if fileLines isn't empty, data will be allocated to weapon objects
    if (fileLines.size() != 0) {
        // iterate through each element of fileLines past the first two header lines
        for (int i = 2; i < fileLines.size(); ++i) {
            Weapon weapon; // new weapon object
            std::string currLine = fileLines.at(i); // holds the current element of fileLines
            // a vector is created using the splitString() function
            // the vector brokenStrings will hold the substrings obtained from the string held in currLine
            std::vector<std::string> brokenStrings = splitString(currLine, ',');
            // if there are no elements in brokenStrings, then the file is not formatted correctly and the function terminates
            if (brokenStrings.size() == 0) {
                std::cout << "Incorrect file format." << std::endl;
                return weaponList;
            }

            // allocate brokenStrings data to weapon data
            weapon.weaponID = i - 1;
            weapon.weaponName = brokenStrings.at(0);
            if (brokenStrings.at(1) != "") {
                weapon.reqStr = brokenStrings.at(1);
            }
            if (brokenStrings.at(2) != "") {
                weapon.reqDex = brokenStrings.at(2);
            }
            if (brokenStrings.at(3) != "") {
                weapon.reqInt = brokenStrings.at(3);
            }
            if (brokenStrings.at(4) != "") {
                weapon.reqFth = brokenStrings.at(4);
            }
            if (brokenStrings.at(5) != "") {
                weapon.weight = brokenStrings.at(5);
            }
            if (brokenStrings.at(6) != "") {
                weapon.crit = brokenStrings.at(6);
            }
            if (brokenStrings.at(7) != "") {
                weapon.dmgPhys = brokenStrings.at(7);
            }
            if (brokenStrings.at(8) != "") {
                weapon.dmgMag = brokenStrings.at(8);
            }
            if (brokenStrings.at(9) != "") {
                weapon.dmgFire = brokenStrings.at(9);
            }
            if (brokenStrings.at(10) != "") {
                weapon.dmgLtn = brokenStrings.at(10);
            }
            if (brokenStrings.at(11) != "") {
                weapon.dmgDark = brokenStrings.at(11);
            }
            if (brokenStrings.at(12) != "") {
                weapon.auxBleed = brokenStrings.at(12);
            }
            if (brokenStrings.at(13) != "") {
                weapon.auxPoison = brokenStrings.at(13);
            }
            if (brokenStrings.at(14) != "") {
                weapon.auxFrost = brokenStrings.at(14);
            }
            if (brokenStrings.at(15) != "") {
                weapon.scaleStr = brokenStrings.at(15);
            }
            if (brokenStrings.at(16) != "") {
                weapon.scaleDex = brokenStrings.at(16);
            }
            if (brokenStrings.at(17) != "") {
                weapon.scaleInt = brokenStrings.at(17);
            }
            if (brokenStrings.at(18) != "") {
                weapon.scaleFth = brokenStrings.at(18);
            }
            if (brokenStrings.at(19) != "") {
                weapon.weaponType = brokenStrings.at(19);
            }
            if (brokenStrings.at(20) != "") {
                weapon.damageType = brokenStrings.at(20);
            }
            if (brokenStrings.at(21) != "") {
                weapon.weaponSkill = brokenStrings.at(21);
            }
            if (brokenStrings.at(22) != "") {
                weapon.spellBuff = brokenStrings.at(22);
            }
            if (brokenStrings.at(23) == "Y") {
                weapon.buffable = true;
            }
            if (brokenStrings.at(24) != "") {
                weapon.upgradeMat = brokenStrings.at(24);
            }
            if (brokenStrings.at(25) != "") {
                weapon.AR = brokenStrings.at(25);
            }
            if (brokenStrings.size() == 27) {
                weapon.notes = brokenStrings.at(26);
            }
            // empty the brokenStrings vector
            brokenStrings.clear();
            // weapon is then added to the tree using Insert() method
            weaponList.push_back(weapon);
        }
        std::cout << "Weapon data has been stored successfully.\n\n" << std::endl;
    }
    else {
        std::cout << "Unable to open " << csvPath << ".\n" << std::endl;
    }
    //empty the fileLines vector
    fileLines.clear();

    return weaponList;
}

//same as above but for armor
std::vector<Armor> loadArmor(std::string csvPath) {
    std::cout << "--- Loading file " << csvPath << " ---\n" << std::endl;

    std::vector<Armor> armorList;
    std::vector<std::string> fileLines;
    std::ifstream armorFile;
    armorFile.open(csvPath);

    if (armorFile.is_open()) {
        while (armorFile.good()) {
            std::string line;
            std::getline(armorFile, line);
            if (line != "")
                fileLines.push_back(line);
        }
        armorFile.close();

        if (fileLines.size() == 0) {
            std::cout << "No data was found in " << csvPath << "." << std::endl;
        }
    }

    if (fileLines.size() != 0) {
        for (int i = 4; i < fileLines.size(); ++i) {
            Armor armor;
            std::string currLine = fileLines.at(i);
            std::vector<std::string> brokenStrings = splitString(currLine, ',');
            if (brokenStrings.size() == 0) {
                std::cout << "Incorrect file format." << std::endl;
                return armorList;
            }

            armor.armorID = i - 3;
            armor.armorName = brokenStrings.at(0);
            armor.weight = brokenStrings.at(1);
            armor.physDef = brokenStrings.at(2);
            armor.defStrike = brokenStrings.at(3);
            armor.defSlash = brokenStrings.at(4);
            armor.defThrust = brokenStrings.at(5);
            armor.defMag = brokenStrings.at(6);
            armor.defFire = brokenStrings.at(7);
            armor.defLtn = brokenStrings.at(8);
            armor.defDark = brokenStrings.at(9);
            armor.defBleed = brokenStrings.at(10);
            armor.defPoison = brokenStrings.at(11);
            armor.defFrost = brokenStrings.at(12);
            armor.defCurse = brokenStrings.at(13);
            armor.poise = brokenStrings.at(14);
            armor.armorType = brokenStrings.at(15);
            armor.armorSet = brokenStrings.at(16);

            brokenStrings.clear();
            armorList.push_back(armor);
        }
        std::cout << "Armor data has been stored successfully.\n\n" << std::endl;
    }
    else {
        std::cout << "Unable to open " << csvPath << ".\n" << std::endl;
    }
    fileLines.clear();

    return armorList;
}

//same as above but for sorceries
std::vector<Sorcery> loadSorceries(std::string csvPath) {
    std::cout << "--- Loading file " << csvPath << " ---\n" << std::endl;

    std::vector<Sorcery> sorceryList;
    std::vector<std::string> fileLines;
    std::ifstream sorceryFile;
    sorceryFile.open(csvPath);

    if (sorceryFile.is_open()) {
        while (sorceryFile.good()) {
            std::string line;
            std::getline(sorceryFile, line);
            if (line != "")
                fileLines.push_back(line);
        }
        sorceryFile.close();

        if (fileLines.size() == 0) {
            std::cout << "No data was found in " << csvPath << "." << std::endl;
        }
    }

    if (fileLines.size() != 0) {
        for (int i = 1; i < fileLines.size(); ++i) {
            Sorcery sorcery;
            std::string currLine = fileLines.at(i);
            std::vector<std::string> brokenStrings = splitString(currLine, ',');
            if (brokenStrings.size() == 0) {
                std::cout << "Incorrect file format." << std::endl;
                return sorceryList;
            }

            // allocate brokenStrings data to weapon data
            sorcery.sorceryID = i;
            sorcery.sorceryName = brokenStrings.at(0);
            sorcery.fpCost = brokenStrings.at(1);
            sorcery.slotsReq = brokenStrings.at(2);
            sorcery.intReq = brokenStrings.at(3);
            sorcery.sorceryDesc = brokenStrings.at(4);
            sorcery.acquisition = brokenStrings.at(5);
            if (brokenStrings.size() == 7) {
                sorcery.notes = brokenStrings.at(6);
            }

            brokenStrings.clear();
            sorceryList.push_back(sorcery);
        }
        std::cout << "Sorcery data has been stored successfully.\n\n" << std::endl;
    }
    else {
        std::cout << "Unable to open " << csvPath << ".\n" << std::endl;
    }
    fileLines.clear();

    return sorceryList;
}