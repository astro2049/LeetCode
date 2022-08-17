#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int a = 0;
        for (int num: nums) {
            a ^= num;
        }
        return a;
    }
};
