#ifndef CSVPARSER_H_
#define CSVPARSER_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

// structure to hold weapon information
struct Weapon {
    int weaponID = -1; // unique identifier
    std::string weaponName = "";
    std::string reqStr = "";
    std::string reqDex = "";
    std::string reqInt = "";
    std::string reqFth = "";
    std::string weight = "";
    std::string crit = "";
    std::string dmgPhys = "";
    std::string dmgMag = "";
    std::string dmgFire = "";
    std::string dmgLtn = "";
    std::string dmgDark = "";
    std::string auxBleed = "";
    std::string auxPoison = "";
    std::string auxFrost = "";
    std::string scaleStr = "";
    std::string scaleDex = "";
    std::string scaleInt = "";
    std::string scaleFth = "";
    std::string weaponType = "";
    std::string damageType = "";
    std::string weaponSkill = "";
    std::string spellBuff = "";
    bool buffable = false;
    std::string upgradeMat = "";
    std::string AR = "";
    std::string notes = "";
};

struct Armor {
    int armorID = -1;
    std::string armorName = "";
    std::string weight = "";
    std::string physDef = "";
    std::string defStrike = "";
    std::string defSlash = "";
    std::string defThrust = "";
    std::string defMag = "";
    std::string defFire = "";
    std::string defLtn = "";
    std::string defDark = "";
    std::string defBleed = "";
    std::string defPoison = "";
    std::string defFrost = "";
    std::string defCurse = "";
    std::string poise = "";
    std::string armorType = "";
    std::string armorSet = "";
};

struct Sorcery {
    int sorceryID = -1;
    std::string sorceryName = "";
    std::string fpCost = "";
    std::string slotsReq = "";
    std::string intReq = "";
    std::string sorceryDesc = "";
    std::string acquisition = "";
    std::string notes = "";
};

// shields,rings,miracles,pyromancies

std::vector<std::string> splitString(std::string str, char delimiter);
std::vector<Weapon> loadWeapons(std::string csvPath);
std::vector<Armor> loadArmor(std::string csvPath);
std::vector<Sorcery> loadSorceries(std::string csvPath);

#endif