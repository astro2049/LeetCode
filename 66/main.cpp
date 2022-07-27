#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> reversedDigits;
        int digitCount = digits.size();
        for (int i = 0; i < digitCount; i++) {
            reversedDigits.push_back(digits[digitCount - 1 - i]);
        }
        reversedDigits.push_back(0);
        reversedDigits[0]++;
        for (int i = 0; i < digitCount; i++) {
            if (reversedDigits[i] == 10) {
                reversedDigits[i] -= 10;
                reversedDigits[i + 1]++;
            }
        }
        if (reversedDigits.back() == 0) {
            reversedDigits.pop_back();
        }
        digits.clear();
        int newDigitCount = reversedDigits.size();
        for (int i = 0; i < newDigitCount; i++) {
            digits.push_back(reversedDigits[newDigitCount - 1 - i]);
        }
        return digits;
    }
};
