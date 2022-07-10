#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int res;
        int i = 0, j = n;
        while (i <= j) {
            int mid = (i - j) / 2 + j;
            int guessResult = guess(mid);
            if (guessResult == -1) {
                j = mid - 1;
            } else if (guessResult == 0) {
                res = mid;
                break;
            } else {
                i = mid + 1;
            }
        }
        return res;
    }
};
