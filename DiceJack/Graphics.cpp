#include <iostream>

void renderDivider() {
	std::cout << "\n  +------------------------------------------------------------+  \n\n";
}

void renderFirstDie(int value) {
	switch (value) {
	case 1:
		std::cout << "  +-------+\n";
		std::cout << "  |       |\n";
		std::cout << "  |   *   |\n";
		std::cout << "  |       |\n";
		std::cout << "  +-------+\n";
		break;
	case 2:
		std::cout << "  +-------+\n";
		std::cout << "  | *     |\n";
		std::cout << "  |       |\n";
		std::cout << "  |     * |\n";
		std::cout << "  +-------+\n";
		break;
	case 3:
		std::cout << "  +-------+\n";
		std::cout << "  | *     |\n";
		std::cout << "  |   *   |\n";
		std::cout << "  |     * |\n";
		std::cout << "  +-------+\n";
		break;
	case 4:
		std::cout << "  +-------+\n";
		std::cout << "  | *   * |\n";
		std::cout << "  |       |\n";
		std::cout << "  | *   * |\n";
		std::cout << "  +-------+\n";
		break;
	case 5:
		std::cout << "  +-------+\n";
		std::cout << "  | *   * |\n";
		std::cout << "  |   *   |\n";
		std::cout << "  | *   * |\n";
		std::cout << "  +-------+\n";
		break;
	case 6:
		std::cout << "  +-------+\n";
		std::cout << "  | *   * |\n";
		std::cout << "  | *   * |\n";
		std::cout << "  | *   * |\n";
		std::cout << "  +-------+\n";
		break;
	default:
		std::cout << "Error: Value must be between 1 and 6.\n";
	}
}

void renderSecondDie(int value) {
	switch (value) {
	case 1:
		std::cout << "             +-------+\n";
		std::cout << "             |       |\n";
		std::cout << "             |   *   |\n";
		std::cout << "             |       |\n";
		std::cout << "             +-------+\n";
		break;
	case 2:
		std::cout << "             +-------+\n";
		std::cout << "             | *     |\n";
		std::cout << "             |       |\n";
		std::cout << "             |     * |\n";
		std::cout << "             +-------+\n";
		break;
	case 3:
		std::cout << "             +-------+\n";
		std::cout << "             | *     |\n";
		std::cout << "             |   *   |\n";
		std::cout << "             |     * |\n";
		std::cout << "             +-------+\n";
		break;
	case 4:
		std::cout << "             +-------+\n";
		std::cout << "             | *   * |\n";
		std::cout << "             |       |\n";
		std::cout << "             | *   * |\n";
		std::cout << "             +-------+\n";
		break;
	case 5:
		std::cout << "             +-------+\n";
		std::cout << "             | *   * |\n";
		std::cout << "             |   *   |\n";
		std::cout << "             | *   * |\n";
		std::cout << "             +-------+\n";
		break;
	case 6:
		std::cout << "             +-------+\n";
		std::cout << "             | *   * |\n";
		std::cout << "             | *   * |\n";
		std::cout << "             | *   * |\n";
		std::cout << "             +-------+\n";
		break;
	default:
		std::cout << "Error: Value must be between 1 and 6.\n";
	}
}