#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> n1, n2;
        int n1Len = num1.length(), n2Len = num2.length();
        for (int i = 0; i < n1Len; i++) {
            n1.push_back(num1[n1Len - 1 - i] - '0');
        }
        for (int i = 0; i < n2Len; i++) {
            n2.push_back(num2[n2Len - 1 - i] - '0');
        }
        vector<int> reversedDigits(n1Len + n2Len, 0);
        for (int i = 0; i < n2Len; i++) {
            for (int j = 0; j < n1Len; j++) {
                reversedDigits[i + j] += n2[i] * n1[j];
            }
        }
        for (int i = 0; i < reversedDigits.size(); i++) {
            if (reversedDigits[i] >= 10) {
                reversedDigits[i + 1] += reversedDigits[i] / 10;
                reversedDigits[i] %= 10;
            }
        }
        string product;
        int diff = '0' - 0;
        for (int i = reversedDigits.size() - 1; i >= 0; i--) {
            if (reversedDigits[i] != 0) {
                while (i >= 0) {
                    product.push_back(reversedDigits[i] + diff);
                    i--;
                }
            }
        }
        if (product.empty()) {
            return "0";
        }
        return product;
    }
};
