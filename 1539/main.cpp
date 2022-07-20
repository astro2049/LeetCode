#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0, j = arr.size() - 1;
        int theNextOneIndex = -1;
        while (i <= j) {
            int mid = (j - i) / 2  + i;
            if (arr[mid] - (mid + 1) < k) {
                i = mid + 1;
            } else if (arr[mid] - (mid + 1) >= k && (mid == 0 || arr[mid - 1] - mid < k)) {
                theNextOneIndex = mid;
                break;
            } else {
                j = mid - 1;
            }
        }
        if (theNextOneIndex == -1) {
            return arr.size() + k;
        } else if (theNextOneIndex == 0) {
            return k;
        } else {
            return arr[theNextOneIndex - 1] + k - (arr[theNextOneIndex - 1] - theNextOneIndex);
        }
    }
};
