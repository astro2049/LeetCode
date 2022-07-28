#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = searchForRow(matrix, target);
        if (row == -1) {
            return false;
        }
        return searchRow(matrix[row], target);
    }

    int searchForRow(vector<vector<int>> matrix, int target) {
        int i = 0, j = matrix.size() - 1;
        int index = -1;
        while (i <= j) {
            int mid = (j - i) / 2 + i;
            if (matrix[mid][0] <= target) {
                index = mid;
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return index;
    }

    bool searchRow(vector<int> row, int target) {
        int i = 0, j = row.size() - 1;
        while (i <= j) {
            int mid = (j - i) / 2 + i;
            if (row[mid] == target) {
                return true;
            } else if (row[mid] < target) {
                i = mid + 1;
            } else{
                j = mid - 1;
            };
        }
        return false;
    }
};
