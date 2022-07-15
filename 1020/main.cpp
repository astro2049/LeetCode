#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int numOfEnclaves = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                int currentSectorLandCellCount = 0;
                bool isSurrounded = true;
                dfs(grid, row, col, visited, currentSectorLandCellCount, isSurrounded);
                if (isSurrounded) {
                    numOfEnclaves += currentSectorLandCellCount;
                }
            }
        }
        return numOfEnclaves;
    }

    void dfs(vector<vector<int>>& grid, int y, int x, vector<vector<bool>> &visited,
             int &currentSectorLandCellCount, bool &isSurrounded) {
        if (grid[y][x] == 0) {
            return;
        }
        if (visited[y][x]) {
            return;
        }
        visited[y][x] = true;
        currentSectorLandCellCount++;
        if (y - 1 >= 0) {
            dfs(grid, y - 1, x, visited, currentSectorLandCellCount, isSurrounded);
        } else {
            isSurrounded = false;
        }
        if (x + 1 <= grid[0].size() - 1) {
            dfs(grid, y, x + 1, visited, currentSectorLandCellCount, isSurrounded);
        } else {
            isSurrounded = false;
        }
        if (y + 1 <= grid.size() - 1) {
            dfs(grid, y + 1, x, visited, currentSectorLandCellCount, isSurrounded);
        } else {
            isSurrounded = false;
        }
        if (x - 1 >= 0) {
            dfs(grid, y, x - 1, visited, currentSectorLandCellCount, isSurrounded);
        } else {
            isSurrounded = false;
        }
    }
};
