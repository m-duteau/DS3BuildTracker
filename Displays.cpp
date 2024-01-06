#include "Displays.h"

/*
 * Display the weapon information to the console (std::out)
 */
void displayWeapon(Weapon weapon) {
    std::cout << weapon.weaponID << ": " << weapon.weaponName << std::endl;

    if (weapon.buffable == true) {
        std::cout << "- Buffable -" << std::endl;
    }
    else {
        std::cout << "- Not Buffable -" << std::endl;
    }

    std::cout << "Weapon type: " << weapon.weaponType << std::endl;
    std::cout << "Damage type: " << weapon.damageType << std::endl;
    std::cout << "Weapon skill: " << weapon.weaponSkill << std::endl;

    if (weapon.spellBuff != "") {
        std::cout << "Spell buff amount: " << weapon.spellBuff << std::endl;
    }
    std::cout << "Upgrade material: " << weapon.upgradeMat << std::endl;

    //if weapon.[thing] != "" then [thing] gets printed
    if (weapon.reqStr != "") {
        std::cout << "Required strength: " << weapon.reqStr << std::endl;
    }
    if (weapon.reqDex != "") {
        std::cout << "Required dexterity: " << weapon.reqDex << std::endl;
    }
    if (weapon.reqInt != "") {
        std::cout << "Required intelligence: " << weapon.reqInt << std::endl;
    }
    if (weapon.reqFth != "") {
        std::cout << "Required faith: " << weapon.reqFth << std::endl;
    }
    if (weapon.weight != "") {
        std::cout << "Weight: " << weapon.weight << std::endl;
    }
    if (weapon.crit != "") {
        std::cout << "Crit damage multiplier: " << weapon.crit << std::endl;
    }
    if (weapon.AR != "") {
        std::cout << "AR: " << weapon.AR << std::endl;
    }
    if (weapon.dmgPhys != "") {
        std::cout << "Physical damage: " << weapon.dmgPhys << std::endl;
    }
    if (weapon.dmgMag != "") {
        std::cout << "Magic damage: " << weapon.dmgMag << std::endl;
    }
    if (weapon.dmgFire != "") {
        std::cout << "Fire damage: " << weapon.dmgFire << std::endl;
    }
    if (weapon.dmgLtn != "") {
        std::cout << "Lightning damage: " << weapon.dmgLtn << std::endl;
    }
    if (weapon.dmgDark != "") {
        std::cout << "Dark damage: " << weapon.dmgDark << std::endl;
    }
    if (weapon.auxBleed != "") {
        std::cout << "Bleed build-up: " << weapon.auxBleed << std::endl;
    }
    if (weapon.auxPoison != "") {
        std::cout << "Poison build-up: " << weapon.auxPoison << std::endl;
    }
    if (weapon.auxFrost != "") {
        std::cout << "Frost build-up: " << weapon.auxFrost << std::endl;
    }
    if (weapon.scaleStr != "") {
        std::cout << "Strength scaling: " << weapon.scaleStr << std::endl;
    }
    if (weapon.scaleDex != "") {
        std::cout << "Dexterity scaling: " << weapon.scaleDex << std::endl;
    }
    if (weapon.scaleInt != "") {
        std::cout << "Intelligence scaling: " << weapon.scaleInt << std::endl;
    }
    if (weapon.scaleFth != "") {
        std::cout << "Faith scaling: " << weapon.scaleFth << std::endl;
    }
    if (weapon.notes != "") {
        std::cout << "Extra details: " << weapon.notes << std::endl;
    }
    std::cout << "\n";

    return;
}

/*
 * Display the armor information to the console (std::out)
 */
void displayArmor(Armor armor) {
    std::cout << armor.armorID << ": " << armor.armorName << std::endl;
    std::cout << "Armor set: " << armor.armorSet << std::endl;
    std::cout << "Armor type: " << armor.armorType << std::endl;
    std::cout << "Weight: " << armor.weight << std::endl;
    std::cout << "Poise: " << armor.poise << std::endl;
    std::cout << "\nPhysical damage protection: " << armor.physDef << std::endl;
    std::cout << "Vs. strike protection: " << armor.defStrike << std::endl;
    std::cout << "Vs. slash protection: " << armor.defSlash << std::endl;
    std::cout << "Vs. thrust protection: " << armor.defThrust << std::endl;
    std::cout << "Magic protection: " << armor.defMag << std::endl;
    std::cout << "Fire protection: " << armor.defFire << std::endl;
    std::cout << "Lightning protection: " << armor.defLtn << std::endl;
    std::cout << "Dark protection: " << armor.defDark << std::endl;
    std::cout << "Bleed protection: " << armor.defBleed << std::endl;
    std::cout << "Poison protection: " << armor.defPoison << std::endl;
    std::cout << "Frost protection: " << armor.defFrost << std::endl;
    std::cout << "Curse protection: " << armor.defCurse << std::endl;
    std::cout << "-------------------\n" << std::endl;

    return;
}

/*
 * Display the sorcery information to the console (std::out)
 */
void displaySorcery(Sorcery sorcery) {
    std::cout << sorcery.sorceryID << ": " << sorcery.sorceryName << std::endl;
    std::cout << "FP cost: " << sorcery.fpCost << std::endl;
    std::cout << "Slots required: " << sorcery.slotsReq << std::endl;
    std::cout << "Intelligence required: " << sorcery.intReq << std::endl;
    std::cout << "\nDescription:\n" << sorcery.sorceryDesc << std::endl;
    std::cout << "\nAcquisition:" << std::endl;

    std::vector<std::string> acquisitionStrings = splitString(sorcery.acquisition, ' ');

    if (acquisitionStrings.size() == 0) {
        std::cout << "Something bad happened." << std::endl;
    }
    else {
        for (int i = 0; i < acquisitionStrings.size(); ++i) {
            if (acquisitionStrings.at(i).find("^") != std::string::npos) {
                std::vector<std::string> acquisitionSubstr = splitString(acquisitionStrings.at(i), '^');
                std::cout << acquisitionSubstr.at(0) << "\n" << acquisitionSubstr.at(1) << " ";
            }
            else {
                std::cout << acquisitionStrings.at(i) << " ";
            }
        }
        std::cout << "\n";
    }

    if (sorcery.notes != "") {
        std::cout << "\nNotes: " << sorcery.notes << std::endl;
    }
    
    if (sorcery.sorceryID != 38) {
        std::cout << "\n-------------------\n" << std::endl;
    }
    
    acquisitionStrings.clear();

    return;
}