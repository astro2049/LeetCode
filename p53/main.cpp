#include <iostream>
#include "vector"

using namespace std;

int main()
{
    std::cout<<"Hello, World!"<<std::endl;
    return 0;
}

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int subArraySum = nums[0], maxSubArraySum = nums[0];
        int i = 0, j = 1;
        while (i < nums.size() && j < nums.size()) {
            if (subArraySum < 0) {
                i = j;
                subArraySum = nums[j];
            } else {
                subArraySum += nums[j];
            }

            maxSubArraySum = max(maxSubArraySum, subArraySum);

            j++;
        }

        return maxSubArraySum;
    }
};
