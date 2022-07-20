#include <iostream>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        // I looked at the solution
        bool map[244] = {false};
        while (n != 1) {
            n = getNewN(n);
            if (n > 243) {
                continue;
            }
            if (map[n]) {
                return false;
            }
            map[n] = true;
        }
        return true;
    }

    int getNewN(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            sum += digit * digit;
        }
        return sum;
    }
};

int main() {
    std::cout << Solution().isHappy(19) << std::endl;
    return 0;
}
