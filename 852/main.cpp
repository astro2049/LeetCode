#include <iostream>
#include "vector"

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 0, j = arr.size() - 1;
        while (i <= j) {
            int mid = (j - i) / 2 + i;
            if (arr[mid] < arr[mid + 1]) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return i;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> mountainArray = {3, 5, 3, 2, 0};
    int res = solution.peakIndexInMountainArray(mountainArray);
    cout << res << endl;

    return 0;
}
