#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1, j = num;
        while (i <= j) {
            int mid = (j - i) / 2 + i;
            if (num / mid > mid || (num / mid == mid && num % mid > 0)) {
                i = mid + 1;
            } else if (num / mid == mid && num % mid == 0) {
                return true;
            } else {
                j = mid - 1;
            }
        }
        return false;
    }
};
