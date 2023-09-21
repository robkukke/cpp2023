#include <iostream>

int main() {
    int count;
    std::string firstName;

    std::cin >> count;

    for (int i = 0; i < count; ++i) {
        std::cin >> firstName;
        std::cout << "Tere, " << firstName << "!" << std::endl;
    }

    return 0;
}
