#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        vector<int> numsAtBack;
        for (int i = 0; i < nums.size() - k; i++) {
            numsAtBack.push_back(nums[i]);
        }
        vector<int> numsAtFront;
        for (int i = nums.size() - k; i < nums.size(); i++) {
            numsAtFront.push_back(nums[i]);
        }
        nums.clear();
        nums.insert(nums.end(), numsAtFront.begin(), numsAtFront.end());
        nums.insert(nums.end(), numsAtBack.begin(), numsAtBack.end());
    }
};
