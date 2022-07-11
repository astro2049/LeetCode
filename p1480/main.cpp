#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> runningSums;
        int sum = 0;
        for (int num : nums) {
            sum += num;
            runningSums.push_back(sum);
        }
        return runningSums;
    }
};
