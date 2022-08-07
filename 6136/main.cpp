#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int arithmeticTriplets(vector<int> &nums, int diff) {
        int count = 0;
        int len = nums.size();
        for (int i = 0; i < len - 2; i++) {
            for (int j = i + 1; j < len - 1; j++) {
                for (int k = j + 1; k < len; k++) {
                    if (nums[k] - nums[j] == diff && nums[j] - nums[i] == diff) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
