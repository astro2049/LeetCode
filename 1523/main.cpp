#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int countOdds(int low, int high) {
        int lowEndpoint = low % 2 == 1 ? low : low + 1;
        int highEndpoint = high % 2 == 1 ? high : high - 1;
        return (highEndpoint - lowEndpoint) / 2 + 1;
    }
};
