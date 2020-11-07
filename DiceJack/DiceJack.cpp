#include <iostream>

int main()
{
    bool gameOver = false;

    std::cout << "Welcome to Dicejack! Please take a seat at the table.\n";
    std::cout << "You start with 100 credits. You win the game if you get to 300 credits.\n\n";

    while (!gameOver) {
        int input;

        std::cout << "What would you like to do next?\n";
        std::cout << "  [1] Play a round.\n";
        std::cout << "  [2] Leave the table.\n\n";
        std::cin >> input;
        std::cout << "\n\n";

        while (input != 1 && input != 2) {
            std::cout << "Please enter 1 or 2: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cin >> input;
            std::cout << "\n";
        }

        if (input == 1) {
            std::cout << "Yay, let's play!\n\n";
        }
        else if (input == 2) {
            std::cout << "Okay, maybe next time!\n\n";
            gameOver = true;
        }
    }

    std::cout << "You ended the game with X credits. Thanks for playing!\n";
}