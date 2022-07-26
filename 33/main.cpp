#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (target < nums[0] && target > nums[nums.size() - 1]) {
            return -1;
        }
        int i = 0, j = nums.size() - 1;
        if (target >= nums[0]) {
            while (i <= j) {
                int mid = (j - i) / 2 + i;
                if (nums[mid] < target) {
                    if (nums[mid] >= nums[0]) {
                        i = mid + 1;
                    } else {
                        j = mid - 1;
                    }
                } else if (nums[mid] == target) {
                    return mid;
                } else {
                    j = mid - 1;
                }
            }
        } else {
            while (i <= j) {
                int mid = (j - i) / 2 + i;
                if (nums[mid] < target) {
                    i = mid + 1;
                } else if (nums[mid] == target) {
                    return mid;
                } else {
                    if (nums[mid] >= nums[0]) {
                        i = mid + 1;
                    } else {
                        j = mid - 1;
                    }
                }
            }
        }
        return -1;
    }
};
