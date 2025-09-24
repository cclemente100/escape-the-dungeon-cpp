// dungeon_adventure.cpp
// Escape the Dungeon - Text Adventure Game
// Author: cclemente100
// Description: Console-based adventure game with input validation, nested if-else, and switch statements.
//
#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Helper function for input validation (integer)
int getValidatedInt(int min, int max) {
    int choice;
    while (true) {
        cout << "Enter your choice (" << min << "-" << max << "): ";
        if (cin >> choice && choice >= min && choice <= max) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        } else {
            cout << "Invalid input. Please enter a number between " << min << " and " << max << ".\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main() {
    // Introduction
    cout << "==============================\n";
    cout << "   Welcome to Escape the Dungeon!\n";
    cout << "==============================\n";
    cout << "You find yourself trapped in a dark, damp dungeon.\n";
    cout << "Your mission: Find a way out before it's too late.\n\n";

    // First decision: Choose a direction
    cout << "You see two paths ahead:\n";
    cout << "1. Left - A faint light flickers.\n";
    cout << "2. Right - You hear distant growling.\n";
    int direction = getValidatedInt(1, 2);

    if (direction == 1) {
        // Left path
        cout << "\nYou walk towards the light and find a locked door.\n";
        cout << "There's a rusty key on the ground and a mysterious lever on the wall.\n";
        cout << "What will you do?\n";
        cout << "1. Pick up the key and try the door.\n";
        cout << "2. Pull the lever.\n";
        int leftChoice = getValidatedInt(1, 2);

        if (leftChoice == 1) {
            cout << "\nThe key fits! You unlock the door and escape.\n";
            cout << "Congratulations, you have escaped the dungeon!\n";
        } else {
            cout << "\nYou pull the lever. A trapdoor opens beneath you!\n";
            cout << "You fall into a pit and lose the game.\n";
        }
    } else {
        // Right path
        cout << "\nYou walk towards the growling and encounter a monster!\n";
        cout << "You must decide how to face it:\n";
        cout << "1. Fight the monster.\n";
        cout << "2. Run away.\n";
        cout << "3. Try to sneak past.\n";
        int monsterChoice = getValidatedInt(1, 3);

        switch (monsterChoice) {
            case 1:
                cout << "\nYou bravely fight the monster.\n";
                cout << "After a fierce battle, you defeat it and find a hidden exit.\n";
                cout << "You escape the dungeon!\n";
                break;
            case 2:
                cout << "\nYou try to run, but the monster is faster.\n";
                cout << "You are caught and lose the game.\n";
                break;
            case 3:
                cout << "\nYou attempt to sneak past the monster.\n";
                cout << "You succeed and find a secret passage leading outside.\n";
                cout << "You escape the dungeon!\n";
                break;
            default:
                // Should never reach here due to input validation
                cout << "Unexpected error.\n";
        }
    }

    cout << "\nThank you for playing Escape the Dungeon!\n";
    return 0;
}
