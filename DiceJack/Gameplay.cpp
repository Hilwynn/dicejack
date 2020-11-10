#include <iostream>
#include <chrono>
#include <thread>
#include "Graphics.h"
#include "Helpers.h"
#include "Source.h"

using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;

int playerBet = 0;
int playerTotal = 0;
int computerBet = 0;

void promptPlayerForBet() {
    std::cout << "    Place your bet: ";
    std::cin >> playerBet;
}

void handlePlayerBettingPhase() {
    promptPlayerForBet();

    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        
        std::cout << "    You must enter a number.\n\n";

        promptPlayerForBet();
    }

    while (playerBet <= 0 || playerBet > playerCredits) {
        if (playerBet <= 0) {
            std::cout << "    You must bet at least 1 credit.\n\n";

            promptPlayerForBet();
        }
        else if (playerBet > playerCredits) {
            std::cout << "    You can't bet more credits than you have.\n\n";
            std::cout << "    You currently have " << playerCredits << " credits.\n\n";

            promptPlayerForBet();
        }
    }

    renderDivider();
}

void handlePlayerTurn() {
    renderRollingDice();

    std::cout << "    Rolling some dice...\n\n";

    int firstRoll = rollDie();
    int secondRoll = rollDie();
    int rollTotal = firstRoll + secondRoll;

    sleep_until(system_clock::now() + 2s);

    renderFirstDie(firstRoll);
    renderSecondDie(secondRoll);

    std::cout << "    You rolled " << rollTotal << ".\n";

    playerTotal += rollTotal;
}

bool promptPlayerToRollAgain() {
    char rollAgain = 'x';

    while (rollAgain != 'y' && rollAgain != 'Y' && rollAgain != 'n' && rollAgain != 'N') {
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        std::cout << "    Would you like to roll again? [Y]es or [N]o? ";
        std::cin >> rollAgain;
    }

    if (rollAgain == 'n' || rollAgain == 'N') {
        return false;
    }

    return true;
}

void handleComputerBettingPhase() {
    int creditDifference = playerCredits - computerCredits;
    int computerCreditsPointThree = computerCredits * 0.3;
    int computerCreditsPointFour = computerCredits * 0.4;
    int computerCreditsPointEight = computerCredits * 0.8;

    if (firstRound) {
        computerBet = randomizeComputerBet(20, 50);
    }
    else if (computerCredits < 20) {
        int smallBet = randomizeComputerBet(computerCreditsPointEight, computerCredits);
        
        if (smallBet < 2) {
            computerBet = 1;
        }
        else {
            computerBet = smallBet;
        }
    }
    else if (playerCredits >= computerCredits) {
        if (playerCredits > 200) {
            int idealBet = (300 - computerCredits) / 2;

            if (computerCredits >= idealBet) {
                computerBet = idealBet;
            }
            else if ((computerCredits * 2) >= 300) {
                computerBet = computerCredits;
            }
            else {
                computerBet = randomizeComputerBet(computerCredits - 10, computerCredits);
            }
        }
        else {
            computerBet = randomizeComputerBet(computerCreditsPointThree, computerCreditsPointFour);
        }
        
    }
    else if (playerCredits < computerCredits) {
        if (computerCredits > 200) {
            computerBet = (300 - computerCredits) / 2;
        }
        else {
            computerBet = randomizeComputerBet(computerCreditsPointThree, computerCreditsPointFour);
        }
    }

    std::cout << "    Your bet: " << playerBet << "\n\n";
    std::cout << "    Your opponent's bet: " << computerBet << "\n";

    sleep_until(system_clock::now() + 3s);

    renderDivider();
}

int handleComputerTurn() {
    bool playing = true;
    int total = 0;

    while (playing) {
        renderRollingDice();

        std::cout << "    Your opponent is rolling some dice...\n\n";

        sleep_until(system_clock::now() + 2s);

        int firstRoll = rollDie();
        int secondRoll = rollDie();
        int rollTotal = firstRoll + secondRoll;

        total += rollTotal;

        renderFirstDie(firstRoll);
        renderSecondDie(secondRoll);

        std::cout << "    Your opponent rolled " << rollTotal << ".\n";

        renderDivider();

            if (total > 21) {
                playing = false;
            } else if (total < 22 && total >= playerTotal) {
                playing = false;
            }
            else {
                std::cout << "    Your opponent's current total is " << total << ".\n\n";
                std::cout << "    They're going to roll again.\n";

                sleep_until(system_clock::now() + 3s);

                renderDivider();
            }
    }

    return total;
}

void playRound() {
    bool playing = true;
    playerTotal = 0;
    
    handlePlayerBettingPhase();

    handleComputerBettingPhase();

    while (playing) {
        handlePlayerTurn();

        renderDivider();

        if (playerTotal > 21) {
            std::cout << "    Oh no! You hit " << playerTotal << " and went bust!\n\n";
            std::cout << "    You lost " << playerBet << " credits.\n";

            playerCredits -= playerBet;
            computerCredits += computerBet;
            
            return;
        }

        std::cout << "    Your current total is " << playerTotal << ".\n\n";

        playing = promptPlayerToRollAgain();

        renderDivider();
    }

    std::cout << "    You stopped at " << playerTotal << ".\n\n";
    std::cout << "    Opponent's turn to play!\n";

    sleep_until(system_clock::now() + 3s);

    renderDivider();

    int computerTotal = handleComputerTurn();

    if (computerTotal > 21) {
        std::cout << "    Your opponent hit " << computerTotal << " and went bust!\n\n";
        std::cout << "    You win " << (playerBet * 2) << " credits.\n";

        playerCredits += (playerBet * 2);
        computerCredits -= computerBet;
        
        return;
    }
    else if (computerTotal < 22 && computerTotal >= playerTotal) {
        std::cout << "    Your opponent won with " << computerTotal  << ".\n\n";
        std::cout << "    You lost " << playerBet << " credits.\n";
        
        playerCredits -= playerBet;
        computerCredits += (computerBet * 2);
        
        return;
    }
    else {
        std::cout << "    Congratulations! You win " << (playerBet * 2) << " credits.\n";

        playerCredits += (playerBet * 2);
        computerCredits -= computerBet;
    }
}