#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};

class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res;
        int i = 0, j = 0;
        while (i < m && j < n) {
            int num1 = nums1[i];
            int num2 = nums2[j];
            if (num1 < num2) {
                res.push_back(num1);
                i++;
            } else {
                res.push_back(num2);
                j++;
            }
        }
        if (i < m) {
            for (int k = i; k < m; k++) {
                res.push_back(nums1[k]);
            }
        }
        if (j < n) {
            for (int k = j; k < n; k++) {
                res.push_back(nums2[k]);
            }
        }
        nums1.swap(res);
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0 ,0};
    vector<int> nums2 = {2, 5, 6};

    Solution2 s2 = Solution2();
    s2.merge(nums1, 3, nums2, 3);

    return 0;
}
