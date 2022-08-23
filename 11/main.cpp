#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int maxArea(vector<int> &heights) {
        int l = 0, r = heights.size() - 1;
        int maxCap = -1;
        while (l < r) {
            maxCap = max(maxCap, min(heights[l], heights[r]) * (r - l));
            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxCap;
    }
};
