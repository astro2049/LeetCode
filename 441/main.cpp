#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1, j = n;
        while (i <= j) {
            int mid = (j - i) / 2 + i;
            if ((mid - 1) / 2 < n / mid && mid / 2 >= n / (mid + 1)) {
                if (mid / 2 == n / (mid + 1)) {
                    return mid;
                } else {
                    return mid - 1;
                }
            } else if ((mid - 1) / 2 < n / mid) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return -1;
    }
};
