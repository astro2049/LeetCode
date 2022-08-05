#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int i = nums.size() - 2;
        while (i >= 0) {
            if (nums[i] < nums[i + 1]) {
                break;
            } else {
                i--;
            }
        }
        if (i == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            int j = nums.size() - 1;
            while (j > i) {
                if (nums[j] > nums[i]) {
                    break;
                } else {
                    j--;
                }
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};
