#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int zeroIndex = leftistZeroIndex(nums);
        if (zeroIndex == -1) {
            zeroIndex = nums.size();
        }
        int i = zeroIndex - 1, j = zeroIndex;
        vector<int> newArr;
        while (i >= 0 && j < nums.size()) {
            int squareOfNegativeNum = nums[i] * nums[i];
            int squareOfPositiveNum = nums[j] * nums[j];
            if (squareOfNegativeNum < squareOfPositiveNum) {
                newArr.push_back(squareOfNegativeNum);
                i--;
            } else {
                newArr.push_back(squareOfPositiveNum);
                j++;
            }
        }
        if (i >= 0) {
            while (i >= 0) {
                newArr.push_back(nums[i] * nums[i]);
                i--;
            }
        }
        if (j < nums.size()) {
            while (j < nums.size()) {
                newArr.push_back(nums[j] * nums[j]);
                j++;
            }
        }
        return newArr;
    }

    int leftistZeroIndex(vector<int>& nums) {
        int zeroIndex = -1;
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            int mid = (j - i) / 2 + i;
            if (nums[mid] < 0) {
                i = mid + 1;
            } else {
                zeroIndex = mid;
                j = mid - 1;
            }
        }
        return zeroIndex;
    }
};
