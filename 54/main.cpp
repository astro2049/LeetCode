#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> values;

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int y = 0, x = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int step = 0;
        int yDirection = 0, xDirection = 1;
        for (; step < m * n; y += yDirection, x += xDirection) {
            step++;
            values.push_back(matrix[y][x]);
            visited[y][x] = true;
            if (yDirection == 0 && xDirection == 1) {
                if (x + 1 < n && !visited[y][x + 1]) {
                } else {
                    yDirection = 1, xDirection = 0;
                }
            } else if (yDirection == 1 && xDirection == 0) {
                if (y + 1 < m && !visited[y + 1][x]) {
                } else {
                    yDirection = 0, xDirection = -1;
                }
            } else if (yDirection == 0 && xDirection == -1) {
                if (x - 1 >= 0 && !visited[y][x - 1]) {
                } else {
                    yDirection = -1, xDirection = 0;
                }
            } else {
                if (y - 1 >= 0 && !visited[y - 1][x]) {
                } else {
                    yDirection = 0, xDirection = 1;
                }
            }
        }

        return values;
    }
};
