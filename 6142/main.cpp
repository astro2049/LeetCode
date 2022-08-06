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
    long long countBadPairs(vector<int> &nums) {
        auto len = (long long) nums.size();
        if (len == 1) {
            return 0;
        }
        long long pairsCount = (len) * (len - 1) / 2;
        vector<int> standard;
        for (int i = 1; i <= len; i++) {
            standard.push_back(i);
        }
        for (int i = 0; i < len; i++) {
            nums[i] -= standard[i];
        }
        sort(nums.begin(), nums.end());
        long long goodElementsCount = 1;
        for (int i = 1; i < len; i++) {
            if (nums[i] == nums[i - 1]) {
                goodElementsCount++;
            } else {
                pairsCount -= goodElementsCount * (goodElementsCount - 1) / 2;
                goodElementsCount = 1;
            }
        }
        pairsCount -= goodElementsCount * (goodElementsCount - 1) / 2;
        return pairsCount;
    }
};
