#include <random>
#include <ctime>

std::mt19937 randomGenerator = std::mt19937(std::time(nullptr));

int rollDie() {
    std::uniform_int_distribution<int> randomNumber(1, 6);

    return randomNumber(randomGenerator);
}

int randomizeComputerBet(double min, double max) {
    std::uniform_int_distribution<int> randomNumber(min, max);

    return randomNumber(randomGenerator);
}