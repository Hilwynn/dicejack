#include <iostream>
#include "Graphics.h"
#include "Source.h"

void promptPlayerToPlay() {
    char input;

    std::cout << "    What would you like to do?\n";
    std::cout << "      [P]lay a round.\n";
    std::cout << "      [L]eave the table.\n\n";
    std::cout << "    Your choice: ";
    std::cin >> input;

    while (input != 'p' && input != 'P' && input != 'l' && input != 'L') {
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        renderDivider();

        std::cout << "    Please enter P or L.\n\n";
        std::cout << "    Your choice: ";
        std::cin >> input;
    }

    renderDivider();

    std::cin.clear();
    std::cin.ignore(10000, '\n');

    if (input == 'p' || input == 'P') {
        std::cout << "    Let's roll!\n\n";
    }
    else if (input == 'l' || input == 'L') {
        if (firstRound) {
            std::cout << "    Maybe next time!\n\n";
        }
        else {
            std::cout << "    You ended the game with " << playerCredits << " credits. Thanks for playing!\n\n";
        }

        gameOver = true;
    }
}

void checkPlayerCredits() {
    if (playerCredits >= 300) {
        renderVictoryBanner();

        renderDivider();

        promptPlayerToPlay();
    }
    else if (playerCredits <= 0) {
        std::cout << "   You're out of credits!\n";

        renderDivider();

        promptPlayerToPlay();
    }
    else {
        renderDivider();

        std::cout << "    You currently have " << playerCredits << " credits.\n\n";
    }
}