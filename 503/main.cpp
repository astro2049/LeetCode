#include <iostream>
#include "vector"
#include "stack"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int len = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());
        nums.pop_back();
        vector<int> nextGr8terElement(len, -1);
        stack<int> indexes;
        for (int i = 0; i < nums.size(); i++) {
            while (!indexes.empty()) {
                int k = indexes.top();
                if (nums[k] < nums[i]) {
                    nextGr8terElement[k] = nums[i];
                    indexes.pop();
                } else {
                    break;
                }
            }
            if (i < len) {
                indexes.push(i);
            }
        }
        return nextGr8terElement;
    }
};
