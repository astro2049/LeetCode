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
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        sort(nums.begin(), nums.end(), [](int a, int b){return a > b;});
        vector<int> subSeq;
        int half = sum / 2 + 1;
        int currentSum = 0;
        for (int num : nums) {
            currentSum += num;
            subSeq.push_back(num);
            if (currentSum >= half) {
                break;
            }
        }
        return subSeq;
    }
};
