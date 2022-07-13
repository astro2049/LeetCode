#include <iostream>
#include "vector"

using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int closedIslandsCount = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    bool isClosed = true;
                    dfs(grid, i, j, visited, isClosed);
                    if (isClosed) {
                        closedIslandsCount++;
                    }
                }
            }
        }
        return closedIslandsCount;
    }

    void dfs(vector<vector<int>>& grid, int y, int x, vector<vector<bool>>& visited, bool& isClosed) {
        if (grid[y][x] == 1) {
            return;
        }
        if (visited[y][x]) {
            return;
        }
        visited[y][x] = true;
        if (y - 1 >= 0) {
            dfs(grid, y - 1, x, visited, isClosed);
        } else {
            isClosed = false;
        }
        if (x + 1 <= grid[0].size() - 1) {
            dfs(grid, y, x + 1, visited, isClosed);
        } else {
            isClosed = false;
        }
        if (y + 1 <= grid.size() - 1) {
            dfs(grid, y + 1, x, visited, isClosed);
        } else {
            isClosed = false;
        }
        if (x - 1 >= 0) {
            dfs(grid, y, x - 1, visited, isClosed);
        } else {
            isClosed = false;
        }
    }
};

int main() {
    Solution solution = Solution();
    vector<vector<int>> grid = {
            {0,0,1,0,0},
            {0,1,0,1,0},
            {0,1,1,1,0}};
    solution.closedIsland(grid);

    return 0;
}
