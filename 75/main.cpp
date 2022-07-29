#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int map[3] = {0};
        for (int num: nums) {
            map[num]++;
        }
        int currentNum = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (map[currentNum] == 0) {
                currentNum++;
            }
            map[currentNum]--;
            nums[i] = currentNum;
        }
    }
};
