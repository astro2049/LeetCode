#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int direction = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                continue;
            } else if (nums[i] > nums[i - 1]) {
                if (direction == 0) {
                    direction = 1;
                } else if (direction == 1) {
                    continue;
                } else {
                    return false;
                }
            } else {
                if (direction == 0) {
                    direction = -1;
                } else if (direction == 1) {
                    return false;
                } else {
                    continue;
                }
            }
        }
        return true;
    }
};
