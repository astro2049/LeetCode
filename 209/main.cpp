#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = nums[0];
        int i = 0, j = 0;
        int minLength = INT32_MAX;
        while (true) {
            if (sum >= target) {
                minLength = min(minLength, j - i + 1);
                sum -= nums[i];
                i++;
                if (i >= nums.size()) {
                    break;
                }
            } else {
                j++;
                if (j >= nums.size()) {
                    break;
                }
                sum += nums[j];
            }
        }
        if (minLength == INT32_MAX) {
            return 0;
        }
        return minLength;
    }
};
