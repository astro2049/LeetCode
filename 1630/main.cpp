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
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r) {
        vector<bool> answers;
        int n = nums.size(), m = l.size();
        for (int i = 0; i < m; i++) {
            int lIndex = l[i], rIndex = r[i];
            vector<int> s;
            for (int j = lIndex; j <= rIndex; j++) {
                s.push_back(nums[j]);
            }
            if (s.size() < 2) {
                answers.push_back(false);
                continue;
            } else {
                sort(s.begin(), s.end());
                int diff = s[1] - s[0];
                bool isArithmetic = true;
                for (int k = 2; k < s.size(); k++) {
                    if (s[k] - s[k - 1] != diff) {
                        isArithmetic = false;
                        break;
                    }
                }
                answers.push_back(isArithmetic);
            }
        }
        return answers;
    }
};
