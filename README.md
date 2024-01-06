# DS3BuildTracker

DS3 Build Tracker is a C++ program that aims to create a space for users to save builds for the game Dark Souls 3. This may be beneficial for those who wish to respec temporarily without forgetting a prior build's attributes and equipment.

DS3 Build Tracker reads .csv files in order to save data for weapons, armor, sorceries, miracles, pyromancies, and rings. Through various menus, the user has the ability to read the names and attributes of any of these aforementioned build elements. The user can then save these elements to a new Build object using unique ID's corresponding to the different options available for each element.

Certain .csv files were created by other users; they are credited within the heading of the Source.cpp, and any .csv files made by me use data gathered from https://darksouls3.wiki.fextralife.com/Dark+Souls+3+Wiki . Editing of .csv files is not recommended as it can cause unintended behavior by the program.

# Motivation
Before anything else, this is mainly a personal project to gain and show experience with the C++ programming language. However, I've also found it difficult to impossible to find an already established Dark Souls 3 reference application or software that includes an option to save builds; either this feature is non-existent or locked behind a paywall. I intend for this to be a free to use, open source option for those wishing to save their builds.

# Current State
Intake data for weapons, armor, and sorceries
Access different menus to view weapons, armor, and sorceries
Each menu has the option to list all names of elements (weapons, armor, sorceries), all names and attributes of elements, or find a specific element within the current element type
Weapon and Armor menus also provide an option for viewing elements by weapon type or armor set

# Roadmap/To-Do
Implement miracles
Implement pyromancies
Implement rings
Implement shields
Implement build saving
