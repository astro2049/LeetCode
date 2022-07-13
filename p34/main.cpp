#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(findFirstPosition(nums, target));
        res.push_back(findLastPosition(nums, target));
        return res;
    }

    int findFirstPosition(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        int firstPosition = -1;
        while (i <= j) {
            int mid = (j - i) / 2 + i;
            if (nums[mid] < target) {
                i = mid + 1;
            } else if (nums[mid] == target) {
                firstPosition = mid;
                j = mid - 1;
            } else {
                j = mid - 1;
            }
        }
        return firstPosition;
    }

    int findLastPosition(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        int lastPosition = -1;
        while (i <= j) {
            int mid = (j - i) / 2 + i;
            if (nums[mid] < target) {
                i = mid + 1;
            } else if (nums[mid] == target) {
                lastPosition = mid;
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return lastPosition;
    }
};
