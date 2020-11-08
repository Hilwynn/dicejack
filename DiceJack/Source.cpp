#include <iostream>
#include "Gameplay.h"

int playerCredits = 100;

int main()
{
    bool gameOver = false;

    std::cout << "Welcome to DiceJack! Please take a seat at the table.\n";
    std::cout << "You start with 100 credits. You win the game if you get to 300 credits.\n\n";

    while (!gameOver) {
        char input;

        std::cout << "What would you like to do next?\n";
        std::cout << "  [1] Play a round.\n";
        std::cout << "  [2] Leave the table.\n\n";
        std::cin >> input;
        std::cout << "\n\n";

        while (input != '1' && input != '2') {
            std::cout << "Please enter 1 or 2: ";
            std::cin >> input;
            std::cout << "\n\n";
        }

        if (input == '1') {
            std::cout << "Yay, let's play!\n\n";
        }
        else if (input == '2') {
            std::cout << "Okay, maybe next time!\n\n";
            gameOver = true;
            break;
        }

        playRound();

        if (playerCredits >= 300) {
            std::cout << "Huzzah! You reached " << playerCredits << " credits, which means you win!\n";
            std::cout << "Well done! Your credits will now be reset to 100.\n\n";
            playerCredits = 100;
        }
        else {
            std::cout << "You have " << playerCredits << " credits.\n\n";
        }
    }
    std::cout << "You ended the game with " << playerCredits << " credits. Thanks for playing!\n";
}