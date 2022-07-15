#include <iostream>
#include "vector"
#include "set"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rowsToSet0;
        set<int> colsToSet0;
        for (int y = 0; y < matrix.size(); y++) {
            for (int x = 0; x < matrix[0].size(); x++) {
                if (matrix[y][x] == 0) {
                    rowsToSet0.insert(y);
                    colsToSet0.insert(x);
                }
            }
        }
        for (int row : rowsToSet0) {
            for (int i = 0; i < matrix[0].size(); i++) {
                matrix[row][i] = 0;
            }
        }
        for (int col : colsToSet0) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][col] = 0;
            }
        }
    }
};
