#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int currentIslandArea = 0;
        int maxIslandArea = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 1) {
                    dfs(grid, row, col, visited, currentIslandArea);
                    if (currentIslandArea > maxIslandArea) {
                        maxIslandArea = currentIslandArea;
                    }
                    currentIslandArea = 0;
                }
            }
        }
        return maxIslandArea;
    }

    void dfs(vector<vector<int>>& grid, int y, int x, vector<vector<bool>>& visited, int &currentIslandArea) {
        if (grid[y][x] == 0) {
            return;
        }
        if (visited[y][x]) {
            return;
        }
        currentIslandArea++;
        visited[y][x] = true;
        if (y - 1 >= 0) {
            dfs(grid, y - 1, x, visited, currentIslandArea);
        }
        if (x + 1 <= grid[0].size() - 1) {
            dfs(grid, y, x + 1, visited, currentIslandArea);
        }
        if (y + 1 <= grid.size() - 1) {
            dfs(grid, y + 1, x, visited, currentIslandArea);
        }
        if (x - 1 >= 0) {
            dfs(grid, y, x - 1, visited, currentIslandArea);
        }
    }
};
