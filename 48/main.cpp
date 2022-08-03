#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int lBound = 0, rBound = n - 1;
        int row = 0;
        while (lBound < rBound) {
            for (int col = lBound; col < rBound; col++) {
                int first = matrix[row][col];
                matrix[row][col] = matrix[n - 1 - col][row];
                matrix[n - 1 - col][row] = matrix[n - 1 - row][n - 1 - col];
                matrix[n - 1 - row][n - 1 - col] = matrix[col][n - 1 - row];
                matrix[col][n - 1 - row] = first;
            }
            row++, lBound++, rBound--;
        }

        return;
    }
};
