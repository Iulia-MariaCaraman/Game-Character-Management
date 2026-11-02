# CaracterJoc - C++ Game Character Management

A C++ Object-Oriented Programming (OOP) project demonstrating dynamic memory management and core class mechanics through a video game character model.

## Features

- **Class `CaracterJoc`**:
  - **Dynamic Array Allocation**: Stores character attack abilities (`putereAtac`) dynamically on the heap.
  - **Data Validation**: Constructor and modifiers validate attack values to ensure they fall within the range `[0, 100]`.
  - **Dynamic Expansion**: The `adaugaPutereAtac` method dynamically resizes the abilities array to append new valid skills.
  - **Skill Filtering**: The `anuleazaAbilitatiSubPrag` method resets any attack ability strictly below a given threshold to `0`.
  - **Enemy Ability Theft**: The `atacaSiPreluare` method finds the highest attack stat from an enemy's dynamically allocated array, absorbs it into the character's abilities, and removes it from the enemy.
  - **Resource Management**: Includes a custom destructor to prevent memory leaks by releasing dynamically allocated memory (`delete[]`)
