#include <iostream>
#include <string>
#include "Source.h"

void renderWelcomeBanner() {
	std::cout << "\n\n";
	std::cout << "  +-------------------------------------------------------------------------------+\n";
	std::cout << "  |                                                                               |\n";
	std::cout << "  |             Welcome to DiceJack! Please take a seat at the table.             |\n";
	std::cout << "  |                                                                               |\n";
	std::cout << "  |                                                                               |\n";
	std::cout << "  |                             |    ________    |                                |\n";
	std::cout << "  |                             |___    ||    ___|                                |\n";
	std::cout << "  |                             |  |    /\\    |  |                                |\n";
	std::cout << "  |                                                                               |\n";
	std::cout << "  |                                                                               |\n";
	std::cout << "  |           You and your opponent start the game with 100 credits each.         |\n";
	std::cout << "  |                     If you run out of credits, you're out.                    |\n";
	std::cout << "  |                    The first one to reach 300 credits wins.                   |\n";
	std::cout << "  |                                                                               |\n";
	std::cout << "  |                                  Good luck!                                   |\n";
	std::cout << "  |                                                                               |\n";
	std::cout << "  +-------------------------------------------------------------------------------+\n";
	std::cout << "\n\n";
}

void renderVictoryBanner(std::string type) {
	if (type == "playerReachedThreshold") {
		std::cout << "  +-------------------------------------------------------------------------------+\n";
		std::cout << "  |                                                                               |\n";
		std::cout << "  |                      Congratulations, you won the game!                       |\n";
		std::cout << "  |                                                                               |\n";
		std::cout << "  |                     You ended the game with " << playerCredits << " credits.                      |\n";
		std::cout << "  |                                                                               |\n";
		std::cout << "  |                                 Well played!                                  |\n";
		std::cout << "  |                                                                               |\n";
		std::cout << "  +-------------------------------------------------------------------------------+\n";
	}

	if (type == "computerOutOfCredits") {
		std::cout << "  +-------------------------------------------------------------------------------+\n";
		std::cout << "  |                                                                               |\n";
		std::cout << "  |               You won because your opponent ran out of credits!               |\n";
		std::cout << "  |                                                                               |\n";
		std::cout << "  |                     You ended the game with " << playerCredits << " credits.                      |\n";
		std::cout << "  |                                                                               |\n";
		std::cout << "  |                                 Well played!                                  |\n";
		std::cout << "  |                                                                               |\n";
		std::cout << "  +-------------------------------------------------------------------------------+\n";
	}
}

void renderLossBanner(std::string type) {
	if (type == "computerReachedThreshold") {
		std::cout << "  +-------------------------------------------------------------------------------+\n";
		std::cout << "  |                                                                               |\n";
		std::cout << "  |                              You lost the game.                               |\n";
		std::cout << "  |                                                                               |\n";
		std::cout << "  |                     You ended the game with " << playerCredits << " credits.                      |\n";
		std::cout << "  |                                                                               |\n";
		std::cout << "  |                            Better luck next time!                             |\n";
		std::cout << "  |                                                                               |\n";
		std::cout << "  +-------------------------------------------------------------------------------+\n";
	}

	if (type == "playerOutOfCredits") {
		std::cout << "  +-------------------------------------------------------------------------------+\n";
		std::cout << "  |                                                                               |\n";
		std::cout << "  |                   You ran out of credits and lost the game.                   |\n";
		std::cout << "  |                                                                               |\n";
		std::cout << "  |                            Better luck next time!                             |\n";
		std::cout << "  |                                                                               |\n";
		std::cout << "  +-------------------------------------------------------------------------------+\n";
	}
}

void renderDivider() {
	std::cout << "\n  §-------------------------------------------------------------------------------§\n\n";
}

void renderRollingDice() {
	std::cout << "                                                               (( _____\n";
	std::cout << "                                                       _____     /\\    \\\n";
	std::cout << "                                                      /    /\\   /  \\____\\ ))\n";
	std::cout << "                                                  (( /____/  \\  \\  /    /\n";
	std::cout << "                                                     \\    \\  /   \\/____/\n";
	std::cout << "                                                      \\____\\/ ))\n";
	std::cout << "\n\n";
}

void renderFirstDie(int value) {
	switch (value) {
	case 1:
		std::cout << "                                     _______ \n";
		std::cout << "                                    |       |\n";
		std::cout << "                                    |       |\n";
		std::cout << "                                    |   o   |\n";
		std::cout << "                                    |       |\n";
		std::cout << "                                    |_______|\n\n";
		break;							          
	case 2:								          
		std::cout << "                                     _______ \n";
		std::cout << "                                    |       |\n";
		std::cout << "                                    | o     |\n";
		std::cout << "                                    |       |\n";
		std::cout << "                                    |     o |\n";
		std::cout << "                                    |_______|\n\n";
		break;							          
	case 3:								          
		std::cout << "                                     _______ \n";
		std::cout << "                                    |       |\n";
		std::cout << "                                    | o     |\n";
		std::cout << "                                    |   o   |\n";
		std::cout << "                                    |     o |\n";
		std::cout << "                                    |_______|\n\n";
		break;							          
	case 4:								          
		std::cout << "                                     _______ \n";
		std::cout << "                                    |       |\n";
		std::cout << "                                    | o   o |\n";
		std::cout << "                                    |       |\n";
		std::cout << "                                    | o   o |\n";
		std::cout << "                                    |_______|\n\n";
		break;							          
	case 5:								          
		std::cout << "                                     _______ \n";
		std::cout << "                                    |       |\n";
		std::cout << "                                    | o   o |\n";
		std::cout << "                                    |   o   |\n";
		std::cout << "                                    | o   o |\n";
		std::cout << "                                    |_______|\n\n";
		break;							          
	case 6:								          
		std::cout << "                                     _______ \n";
		std::cout << "                                    |       |\n";
		std::cout << "                                    | o   o |\n";
		std::cout << "                                    | o   o |\n";
		std::cout << "                                    | o   o |\n";
		std::cout << "                                    |_______|\n\n";
		break;
	default:
		std::cout << "Error: Value must be between 1 and 6.\n";
	}
}

void renderSecondDie(int value) {
	switch (value) {
	case 1:
		std::cout << "                                                _______ \n";
		std::cout << "                                               |       |\n";
		std::cout << "                                               |       |\n";
		std::cout << "                                               |   o   |\n";
		std::cout << "                                               |       |\n";
		std::cout << "                                               |_______|\n\n";
		break;									           
	case 2:
		std::cout << "                                                _______ \n";
		std::cout << "                                               |       |\n";
		std::cout << "                                               | o     |\n";
		std::cout << "                                               |       |\n";
		std::cout << "                                               |     o |\n";
		std::cout << "                                               |_______|\n\n";
		break;									           
	case 3:										           
		std::cout << "                                                _______ \n";
		std::cout << "                                               |       |\n";
		std::cout << "                                               | o     |\n";
		std::cout << "                                               |   o   |\n";
		std::cout << "                                               |     o |\n";
		std::cout << "                                               |_______|\n\n";
		break;									           
	case 4:										           
		std::cout << "                                                _______ \n";
		std::cout << "                                               |       |\n";
		std::cout << "                                               | o   o |\n";
		std::cout << "                                               |       |\n";
		std::cout << "                                               | o   o |\n";
		std::cout << "                                               |_______|\n\n";
		break;									           
	case 5:										           
		std::cout << "                                                _______ \n";
		std::cout << "                                               |       |\n";
		std::cout << "                                               | o   o |\n";
		std::cout << "                                               |   o   |\n";
		std::cout << "                                               | o   o |\n";
		std::cout << "                                               |_______|\n\n";
		break;									           
	case 6:										           
		std::cout << "                                                _______ \n";
		std::cout << "                                               |       |\n";
		std::cout << "                                               | o   o |\n";
		std::cout << "                                               | o   o |\n";
		std::cout << "                                               | o   o |\n";
		std::cout << "                                               |_______|\n\n";
		break;
	default:
		std::cout << "Error: Value must be between 1 and 6.\n";
	}
}