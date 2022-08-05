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
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = s.length() - 2;
        while (i >= 0) {
            if (s[i] < s[i + 1]) {
                break;
            } else {
                i--;
            }
        }
        if (i == -1) {
            return -1;
        }
        int j = s.length() - 1;
        while (j > i) {
            if (s[j] > s[i]) {
                break;
            }
            j--;
        }
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        long long answer = stol(s);
        return answer > INT32_MAX ? -1 : (int) answer;
    }
};
