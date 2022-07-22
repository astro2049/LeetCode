#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = 0; i < (int)nums.size() - 2; i++) {
            for (int j = i + 1; j < (int)nums.size() - 1; j++) {
                int target = nums[i] + nums[j];
                int m = 0, n = nums.size() - 1;
                int index = -1;
                while (m <= n) {
                    int mid = (n - m) / 2 + m;
                    if (nums[mid] < target) {
                        m = mid + 1;
                        index = mid;
                    } else {
                        n = mid - 1;
                    }
                }
                if (index == -1 || index <= j) {
                    continue;
                }
                count += (index - j);
            }
        }
        return count;
    }
};

int main() {
    vector<int> nums = {1};
    cout << Solution().triangleNumber(nums) << endl;
    return 0;
}
