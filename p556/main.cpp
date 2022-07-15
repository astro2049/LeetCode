#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (m * n != r * c) {
            return mat;
        }
        vector<vector<int>> newMat(r, vector<int>(c, -1));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int originalY = (i * c + j) / n;
                int originalX = (i * c + j) % n;
                newMat[i][j] = mat[originalY][originalX];
            }
        }
        return newMat;
    }
};
