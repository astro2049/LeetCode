#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1, j = n;
        while (i <= j) {
            int mid = (j - i) / 2 + i;
            if (!isBadVersion(mid)) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return i;
    }
};
