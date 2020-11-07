#include <random>

std::random_device randomDevice;
std::mt19937 randomGenerator = std::mt19937(randomDevice());

int rollDie() {
    std::uniform_int_distribution<int> randomNumber(1, 6);

    return randomNumber(randomGenerator);
}