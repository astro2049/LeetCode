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
    int largestPerimeter(vector<int>& nums) {
        int maxPerimeter = 0;
        sort(nums.begin(), nums.end(), [](int a, int b){
            return a > b;
        });
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i + 1] + nums[i + 2] > nums[i]) {
                maxPerimeter = nums[i] + nums[i + 1] + nums[i + 2];
                break;
            }
        }
        return maxPerimeter;
    }
};
