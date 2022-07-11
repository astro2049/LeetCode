#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rowCount = grid.size();
        int colCount = grid[0].size();
        vector<vector<bool>> visited(rowCount, vector<bool> (colCount, false));
        int sectorCount = 0;
        for (int x = 0; x < colCount; x++) {
            for (int y = 0; y < rowCount; y++) {
                if (grid[y][x] == '1' && !visited[y][x]) {
                    sectorCount++;
                    dfs(grid, y, x, visited);
                }
            }
        }

        return sectorCount;
    }

    void dfs(vector<vector<char>>& grid, int y, int x, vector<vector<bool>>& visited) {
        if (grid[y][x] == '0') {
            return;
        }
        if (visited[y][x]) {
            return;
        }
        visited[y][x] = true;
        if (y - 1 >= 0) {
            dfs(grid, y - 1, x, visited);
        }
        if (x + 1 <= grid[0].size() - 1) {
            dfs(grid, y, x + 1, visited);
        }
        if (y + 1 <= grid.size() - 1) {
            dfs(grid, y + 1, x, visited);
        }
        if (x - 1 >= 0) {
            dfs(grid, y, x - 1, visited);
        }
    }
};
