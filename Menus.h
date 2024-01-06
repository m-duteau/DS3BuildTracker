#ifndef MENUS_H_
#define MENUS_H_

#include "CSVParser.h"
#include "Displays.h"

void weaponMenu(std::vector<Weapon> weaponList);
void armorMenu(std::vector<Armor> armorList);
void sorceryMenu(std::vector<Sorcery> sorceryList);

#endif