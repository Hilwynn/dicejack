#include <iostream>
#include "Source.h"
#include "Helpers.h"
#include "Graphics.h"

int playerBet = 0;

void promptUserForBet() {
    std::cout << "    Please enter your bet: ";
    std::cin >> playerBet;
    renderDivider();
}

void handlePlayerBetInput() {
    promptUserForBet();

    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "    You must enter a number.\n\n";
        promptUserForBet();
    }

    while (playerBet <= 0 || playerBet > playerCredits) {

        if (playerBet <= 0) {
            std::cout << "    You must bet at least 1 credit.\n\n";
            promptUserForBet();
        }
        else if (playerBet > playerCredits) {
            std::cout << "    You can't bet more credits than you have.\n";
            std::cout << "    You currently have " << playerCredits << " credits.\n\n";
            promptUserForBet();
        }
    }
}

void playRound() {
    handlePlayerBetInput();

    int playerTotal = 0;
    bool playing = true;

    while (playing) {
        std::cout << "    Rolling some dice...\n\n";

        int firstRoll = rollDie();
        int secondRoll = rollDie();
        int rollTotal = firstRoll + secondRoll;
        playerTotal += rollTotal;

        std::cout << "    You rolled " << rollTotal << ".\n\n";

        renderFirstDie(firstRoll);
        renderSecondDie(secondRoll);
        std::cout << "\n\n";

        if (playerTotal == 21) {
            std::cout << "DICEJACK! Your total is 21. You win the round!\n\n";
            playerCredits += playerBet * 2;
            return;
        }

        if (playerTotal > 21) {
            std::cout << "Oh no! You ended up on " << playerTotal << " and went bust!\n\n";
            playerCredits -= playerBet;
            return;
        }

        std::cout << "Your current total is " << playerTotal << ".\n\n";

        char rollAgain;

        std::cout << "Would you like to roll again? [Y]es or [N]o? ";
        std::cin >> rollAgain;
        renderDivider();

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
        std::cout << "You win " << (playerBet * 2) << " credits!\n\n";
        playerCredits += playerBet * 2;
        return;
    }
    else if (computerTotal > playerTotal || computerTotal == playerTotal) {
        std::cout << "The computer rolled " << computerTotal << ".\n";
        std::cout << "You lost " << playerBet << " credits. Better luck next time!\n\n";
        playerCredits -= playerBet;
        return;
    }
    else {
        std::cout << "The computer rolled " << computerTotal << ".\n";
        std::cout << "You win " << (playerBet * 2) << " credits!\n\n";
        playerCredits += playerBet * 2;
    }
}