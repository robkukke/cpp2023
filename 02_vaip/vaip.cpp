#include <iostream>
#include <fstream>
#include <vector>

int main() {
    int carpetCount, eastWallFromWestWall, northWallFromSouthWall, coveredArea = 0;

    std::cin >> carpetCount >> eastWallFromWestWall >> northWallFromSouthWall;

    // 2D vektor nimega totalArea,
    // northWallFromSouthWall määrab ridade arvu,
    // vector<int>(eastWallFromWestWall, 0) määrab, et iga rida on täisarvudest vektor,
    // kus on eastWallFromWestWall arv veerge ning kõik algväärtused on 0
    std::vector<std::vector<int>> totalArea(northWallFromSouthWall, std::vector<int>(eastWallFromWestWall, 0));

    for (int i = 0; i < carpetCount; ++i) {
        int n, s, e, w;

        std::cin >> n >> s >> e >> w;

        for (int row = n; row < northWallFromSouthWall - s; ++row) {
            for (int col = w; col < eastWallFromWestWall - e; ++col) {
                if (totalArea[row][col] == 0) {
                    coveredArea++;
                    totalArea[row][col] = 1;
                }
            }
        }
    }

    std::ofstream outputFile("vaipval.txt");
    outputFile << coveredArea << "\n";
    outputFile.close();

    return 0;
}
