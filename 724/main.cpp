#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefixSums;
        prefixSums.push_back(0);
        int prefixSum = 0;
        for (int num : nums) {
            prefixSum += num;
            prefixSums.push_back(prefixSum);
        }
        // prefix sum of nums[i] correspond to prefixSums[i + 1]
        for (int i = 0; i < nums.size(); i++) {
            int leftSum = prefixSums[i];
            int rightSum = prefixSums[nums.size()] - nums[i] - leftSum;
            if (leftSum == rightSum) {
                return i;
            }
        }
        return -1;
    }
};
