#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int signIndicator = 1;
        for (int num : nums) {
            if (num > 0) {
                signIndicator *= 1;
            } else if (num < 0) {
                signIndicator *= -1;
            } else {
                signIndicator = 0;
                break;
            }
        }
        return signIndicator;
    }
};
