#ifndef MENUS_H_
#define MENUS_H_

#include "CSVParser.h"
#include "Displays.h"

void weaponMenu(std::vector<Weapon> weaponList, std::vector<Shield> shieldList);
void armorMenu(std::vector<Armor> armorList);
void magicMenu(std::vector<Sorcery> sorceryList, std::vector<Miracle> miracleList, std::vector<Pyromancy> pyromancyList);

#endif