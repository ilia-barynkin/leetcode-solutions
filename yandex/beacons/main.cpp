#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Tower {
    int x;
    int y;
};

double distance(int x, int y) {
    return std::sqrt(x * x + y * y);
}

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    int p, q;
    inputFile >> p >> q;

    std::vector<Tower> towers(16);
    for (int i = 0; i < 16; ++i) {
        inputFile >> towers[i].x >> towers[i].y;
    }

    std::vector<double> distances1(8);
    std::vector<double> distances2(8);

    // Calculate distances from each tower to the center
    for (int i = 0; i < 8; ++i) {
        distances1[i] = distance(towers[i].x, towers[i].y);
        distances2[i] = distance(towers[i + 8].x, towers[i + 8].y);
    }

    double minDistance1 = *std::min_element(distances1.begin(), distances1.end());
    double minDistance2 = *std::min_element(distances2.begin(), distances2.end());

    int winner = 0;
    int prestige = 0;

    if (minDistance1 < minDistance2) {
        winner = 1;
        prestige = std::count_if(distances1.begin(), distances1.end(), [&](double d) {
            return d < minDistance2;
        });
    } else if (minDistance2 < minDistance1) {
        winner = 2;
        prestige = std::count_if(distances2.begin(), distances2.end(), [&](double d) {
            return d < minDistance1;
        });
    }

    outputFile << winner << '\n';
    outputFile << prestige << '\n';

    inputFile.close();
    outputFile.close();

    return 0;
}