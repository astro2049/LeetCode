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
    vector<int> frequencySort(vector<int> &nums) {
        vector<pair<int, int>> freqs(201, {0, 0});
        for (int i = 0; i < 201; i++) {
            freqs[i].first = i;
        }
        for (int num: nums) {
            freqs[num + 100].second++;
        }
        sort(freqs.begin(), freqs.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.second < b.second) {
                return true;
            } else if (a.second == b.second) {
                return a.first > b.first;
            } else {
                return false;
            }
        });
        nums.clear();
        for (auto freq: freqs) {
            if (freq.second == 0) {
                continue;
            } else {
                for (int i = 0; i < freq.second; i++) {
                    nums.push_back(freq.first - 100);
                }
            }
        }
        return nums;
    }
};
