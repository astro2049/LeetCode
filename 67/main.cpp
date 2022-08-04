#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string addBinary(string a, string b) {
        vector<int> reversedSum;
        int i = a.length() - 1, j = b.length() - 1;
        for (; i >= 0 && j >= 0; i--, j--) {
            reversedSum.push_back(a[i] - '0' + b[j] - '0');
        }
        if (i >= 0) {
            while (i >= 0) {
                reversedSum.push_back(a[i] - '0');
                i--;
            }
        }
        if (j >= 0) {
            while (j >= 0) {
                reversedSum.push_back(b[j] - '0');
                j--;
            }
        }
        reversedSum.push_back(0);
        for (int k = 0; k < reversedSum.size(); k++) {
            if (reversedSum[k] >= 2) {
                reversedSum[k] -= 2;
                reversedSum[k + 1]++;
            }
        }
        if (reversedSum.back() == 0) {
            reversedSum.pop_back();
        }
        string s;
        for (int k = reversedSum.size() - 1; k >= 0; k--) {
            s.push_back(reversedSum[k] + '0');
        }
        return s;
    }
};
