#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        for (int i = 0; i < arr1.size(); i++) {
            bool isFar = true;
            for (int j = 0; j < arr2.size(); j++) {
                if (arr1[i] - arr2[j] >= -d && arr1[i] - arr2[j] <= d) {
                    isFar = false;
                }
            }
            if (isFar) {
                count++;
            }
        }

        return count;
    }
};

class Solution2 {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        sort(arr2.begin(), arr2.end());
        for (int m = 0; m < arr1.size(); m++) {
            int target = arr1[m];
            bool isFar = true;
            int i = 0, j = arr2.size() - 1;
            while (i <= j) {
                int mid = (j - i) / 2 + i;
                if (arr2[mid] < target) {
                    i = mid + 1;
                } else if (arr2[mid] == target) {
                    isFar = false;
                    break;
                } else {
                    j = mid - 1;
                }
            }

            if (i == 0) {
                int higherVal = arr2[i];
                if (higherVal - target <= d) {
                    isFar = false;
                }
            } else if (i == arr2.size()) {
                int lowerVal = arr2[i - 1];
                if (target - lowerVal <= d) {
                    isFar = false;
                }
            } else {
                int higherVal = arr2[i];
                int lowerVal = arr2[i - 1];
                if (higherVal - target <= d || target - lowerVal <= d) {
                    isFar = false;
                }
            }

            if (isFar) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution2 solution2 = Solution2();
    vector<int> arr1 = {2, 1, 100, 3};
    vector<int> arr2 = {-5, -2, 10, -3, 7};
    int distance = solution2.findTheDistanceValue(arr1, arr2, 6);
    cout << distance << endl;

    return 0;
}
