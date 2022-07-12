#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int i = 1, j = x;
        while (i <= j) {
            int mid = (j - i) / 2 + i;
            if (mid <= x / mid && (mid + 1) > x / (mid + 1)) {
                return mid;
            } else if (mid < x / mid) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return -1;
    }
};
