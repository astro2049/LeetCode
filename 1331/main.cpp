#include <iostream>
#include "vector"
#include "algorithm"
#include "unordered_map"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        int rank = 0;
        unordered_map<int, int> rankMap;
        for (int num : sortedArr) {
            if (rankMap.find(num) != rankMap.end()) {
                continue;
            } else {
                rank++;
                rankMap.insert(pair<int, int>(num, rank));
            }
        }
        for (int &num : arr) {
            num = rankMap.find(num)->second;
        }
        return arr;
    }
};
