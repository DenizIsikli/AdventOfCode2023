#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

std::vector<std::string> expandUniverse(const std::vector<std::string> &lines, int expansionFactor) {
    int rows = lines.size();
    int cols = lines[0].size();

    std::vector<bool> emptyRow(rows, true), emptyCol(cols, true);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (lines[i][j] == '#') {
                emptyRow[i] = false;
                emptyCol[j] = false;
            }
        }
    }
    
    std::vector<std::string> expanded;
    for (int i = 0; i < rows; ++i) {
        for (int k = 0; k < expansionFactor; ++k) {
            std::string expandedRow;
            for (int j = 0; j < cols; ++j) {
                expandedRow += lines[i][j];
                if (emptyCol[j]) expandedRow += '.';
            }
            expanded.push_back(expandedRow);
        }
        
    }

    for (int k = 0; k < expansionFactor; ++k) { // Expand columns
        std::string emptyColString(cols, '.');
        for (int i = 0; i < rows; ++i) {
            expanded.push_back(emptyColString);
        }
    }

    return expanded;
}

int manhattanDistance(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    return std::abs(a.first - b.first) + std::abs(a.second - b.second);
}

int main() {
    std::ifstream file("Input.txt");
    std::string line;
    
    std::vector<std::string> lines;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    int expansionFactor = 1000000;

    std::vector<std::string> newLines = expandUniverse(lines, expansionFactor);

    std::unordered_map<int, std::pair<int, int>> galaxyCoords;
    int galaxyNumber = 1;
    for (int i = 0; i < newLines.size(); ++i) {
        for (int j = 0; j < newLines[i].size(); ++j) {
            if (newLines[i][j] == '#') {
                galaxyCoords[galaxyNumber++] = std::make_pair(i, j);
            }
        }
    }

    int totalPathLength = 0;
    for (int i = 1; i < galaxyNumber; ++i) {
        for (int j = i + 1; j < galaxyNumber; ++j) {
            totalPathLength += manhattanDistance(galaxyCoords[i], galaxyCoords[j]);
        }
    }

    std::cout << totalPathLength << std::endl;
}
    