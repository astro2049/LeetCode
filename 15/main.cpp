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
    vector<vector<int>> triplets;

    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int x = nums[i];
            int j = i + 1, k = nums.size() - 1;
            int target = -x;
            while (j < k) {
                int y = nums[j], z = nums[k];
                int sum = y + z;
                if (sum > target) {
                    k--;
                    while (j < k && nums[k + 1] == nums[k]) {
                        k--;
                    }
                } else if (sum < target) {
                    j++;
                    while (j < k && nums[j - 1] == nums[j]) {
                        j++;
                    }
                } else {
                    triplets.push_back(vector<int>{x, y, z});
                    k--;
                    while (j < k && nums[k + 1] == nums[k]) {
                        k--;
                    }
                    j++;
                    while (j < k && nums[j - 1] == nums[j]) {
                        j++;
                    }
                }
            }
            while (i < nums.size() - 2 && nums[i + 1] == nums[i]) {
                i++;
            }
        }
        return triplets;
    }
};
