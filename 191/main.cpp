#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int weight = 0;
        while (n > 0) {
            if ((n & 1) == 1) {
                weight++;
            }
            n >>= 1;
        }
        return weight;
    }
};

int main() {
    uint32_t x = 15; // I really don't understand the example inputs
    std::cout << Solution().hammingWeight(x) << std::endl;
    return 0;
}
