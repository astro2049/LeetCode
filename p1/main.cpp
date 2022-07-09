#include <iostream>
#include "vector"
#include "unordered_map"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> numIndexMap;
        for (int i = 0; i < nums.size(); ++i) {
            int partner = target - nums[i];
            if (numIndexMap.find(partner) != numIndexMap.end()) {
                res.push_back(i);
                res.push_back(numIndexMap[partner]);
                break;
            }
            numIndexMap.insert(pair<int, int>(nums[i], i));
        }
        return res;
    }
};
