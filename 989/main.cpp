#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> addToArrayForm(vector<int> &num, int k) {
        vector<int> digits;
        for (int i = num.size() - 1; i >= 0; i--) {
            digits.push_back(num[i] + (k % 10));
            k /= 10;
            if (digits.back() >= 10) {
                digits.back() -= 10;
                k++;
            }
        }
        while (k > 0) {
            digits.push_back(k % 10);
            k /= 10;
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
