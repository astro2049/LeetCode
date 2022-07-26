#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        int index = -1;
        while (i <= j) {
            int mid = (j - i) / 2 + i;
            if (nums[mid] >= nums[0]) {
                i = mid + 1;
            } else {
                index = mid;
                j = mid - 1;
            }
        }
        if (index == -1) {
            return nums[0];
        }
        return nums[index];
    }
};
