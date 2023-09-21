#include <iostream>
#include <fstream>
#include <vector>

int main() {
    int numOfNotesInEachVoice, numOfVoices;

    std::cin >> numOfNotesInEachVoice >> numOfVoices;

    std::vector<int> voices(numOfVoices);
    std::vector<int> previousVoices(numOfVoices);

    std::ofstream outputFile("hargval.txt");

    for (int row = 0; row < numOfNotesInEachVoice; ++row) {
        previousVoices = voices;

        for (int voice = 0; voice < numOfVoices; ++voice) {
            std::cin >> voices[voice];
        }

        if (row > 0) {
            for (int i = 0; i < numOfVoices - 1; ++i) {
                for (int j = i + 1; j < numOfVoices; ++j) {
                    bool isParallelQuintet = (voices[i] - voices[j]) % 12 == 7;
                    bool isPreviousParallelQuintet = (previousVoices[i] - previousVoices[j]) % 12 == 7;

                    if (isParallelQuintet && isPreviousParallelQuintet && voices[i] != previousVoices[i] &&
                        voices[j] != previousVoices[j]) {
                        outputFile << row << " " << i + 1 << " " << j + 1 << "\n";
                    }
                }
            }
        }
    }

    outputFile.close();

    std::ifstream checkFile("hargval.txt");

    if (checkFile.peek() == std::ifstream::traits_type::eof()) {
        std::ofstream emptyFile("hargval.txt");

        emptyFile << "POLE" << "\n";
        emptyFile.close();
    }

    checkFile.close();

    return 0;
}
