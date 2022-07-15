#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTri;
        pascalTri.push_back(vector<int>(1, 1));
        for (int i = 2; i <= numRows; i++) {
            vector<int> row(i, -1);
            row[0] = 1, row[i - 1] = 1;
            for (int j = 1; j < i - 1; j++) {
                row[j] = pascalTri[i - 2][j - 1] + pascalTri[i - 2][j];
            }
            pascalTri.push_back(row);
        }
        return pascalTri;
    }
};
