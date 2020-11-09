#include <iostream>
#include "Graphics.h"
#include "Lobby.h"
#include "Gameplay.h"

bool gameOver = false;
bool firstRound = true;
int playerCredits = 100;

int main()
{
    renderWelcomeBanner();

    while (!gameOver) {
        promptPlayerToPlay();
        if (gameOver) {
            return 0;
        }

        playRound();

        firstRound = false;

        checkPlayerCredits();
    }
}