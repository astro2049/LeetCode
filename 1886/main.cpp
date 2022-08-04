#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target) {
        int n = mat.size();
        bool r0 = true, r90 = true, r180 = true, r270 = true;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                int num = mat[row][col];
                r0 = r0 && (num == target[row][col]);
                r90 = r90 && (num == target[col][n - 1 - row]);
                r180 = r180 && (num == target[n - 1 - row][n - 1 - col]);
                r270 = r270 && (num == target[n - 1 - col][row]);
            }
        }
        return r0 || r90 || r180 || r270;
    }
};
