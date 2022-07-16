#include <iostream>
#include "vector"
#include "queue"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<vector<int>> distances(maze.size(), vector<int>(maze[0].size(), -1));

        queue<vector<int>> cells;
        cells.push(entrance);
        distances[entrance[0]][entrance[1]] = 0;

        int yNextMoves[] = {-1, 0, 1, 0};
        int xNextMoves[] = {0, 1, 0, -1};

        while (!cells.empty()) {
            vector<int> cell = cells.front();
            int y = cell[0], x = cell[1];
            cells.pop();
            if (maze[y][x] == '+') {
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int newY = y + yNextMoves[i];
                int newX = x + xNextMoves[i];
                if (newY < 0 || newX > maze[0].size() - 1 || newY > maze.size() - 1 || newX < 0) {
                    if (!(y == entrance[0] && x == entrance[1])) {
                        return distances[y][x];
                    } else {
                        continue;
                    }
                }
                if (distances[newY][newX] == -1) {
                    cells.push({newY, newX});
                    distances[newY][newX] = distances[y][x] + 1;
                }
            }
        }
        return -1;
    }
};
