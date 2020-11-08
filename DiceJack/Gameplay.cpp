#include <iostream>
#include "Source.h"
#include "Helpers.h"
#include "Graphics.h"

void playRound() {
    int bet = 0;

    std::cout << "Please enter your bet: ";
    std::cin >> bet;
    std::cout << "\n\n";

    while (std::cin.fail()) {
        std::cout << "Please enter your bet (numbers only): ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cin >> bet;
        std::cout << "\n\n";
    }

    while (bet <= 0 || bet > playerCredits) {

        if (bet <= 0) {
            std::cout << "You must bet at least 1 credit.\n";
            std::cout << "Please enter your bet: ";
            std::cin >> bet;
            std::cout << "\n\n";
        }
        else if (bet > playerCredits) {
            std::cout << "You must bet at least 1 credit.\n";
            std::cout << "Please enter your bet: ";
            std::cin >> bet;
            std::cout << "\n\n";
        }
    }

    int playerTotal = 0;
    bool playing = true;

    std::cout << "Rolling some dice...\n\n";

    while (playing) {
        int firstRoll = rollDie();
        int secondRoll = rollDie();
        int rollTotal = firstRoll + secondRoll;
        playerTotal += rollTotal;

        renderFirstDie(firstRoll);
        renderSecondDie(secondRoll);
        std::cout << "\n\n";

        if (playerTotal == 21) {
            std::cout << "DIEJACK! Your total is 21. You win the round!\n\n";
            playerCredits += bet * 2;
            return;
        }

        if (playerTotal > 21) {
            std::cout << "Oh no! You ended up on " << playerTotal << " and went bust!\n\n";
            playerCredits -= bet;
            return;
        }

        std::cout << "Your current total is " << playerTotal << ".\n\n";

        char rollAgain;

        std::cout << "Would you like to roll again? [Y]es or [N]o? ";
        std::cin >> rollAgain;
        std::cout << "\n";

        while (rollAgain != 'y' && rollAgain != 'Y' && rollAgain != 'n' && rollAgain != 'N') {
            std::cout << "Would you like to roll again? [Y]es or [N]o? ";
            std::cin >> rollAgain;
            std::cout << "\n";
        }

        if (rollAgain == 'n' || rollAgain == 'N') {
            playing = false;
        }
    }

    int computerTotal;
    computerTotal = rollDie() + rollDie() + rollDie() + rollDie();

    if (computerTotal > 21) {
        std::cout << "The computer rolled " << computerTotal << ".\n";
        std::cout << "You win " << (bet * 2) << " credits!\n\n";
        playerCredits += bet * 2;
        return;
    }
    else if (computerTotal > playerTotal || computerTotal == playerTotal) {
        std::cout << "The computer rolled " << computerTotal << ".\n";
        std::cout << "You lost " << bet << " credits. Better luck next time!\n\n";
        playerCredits -= bet;
        return;
    }
    else {
        std::cout << "The computer rolled " << computerTotal << ".\n";
        std::cout << "You win " << (bet * 2) << " credits!\n\n";
        playerCredits += bet * 2;
    }
}