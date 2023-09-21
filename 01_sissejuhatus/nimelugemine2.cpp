#include <iostream>

int main() {
    int count;
    std::string firstName;

    std::cin >> count;

    auto *names = new std::string[count];

    for (int i = 0; i < count; ++i) {
        std::cin >> firstName;

        names[i] = firstName;

        std::cout << "Tere, " << firstName << "!" << std::endl;
    }

    // Kuvage tagurpidi järjekorras välja
    for (int i = 0; i < count; ++i) {
        std::cout << "Tere, " << names[count - i - 1] << "!" << std::endl;
    }

    return 0;
}
