#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2) {
        int map[1001] = { 0 };
        for (auto &vec: items1) {
            map[vec[0]] += vec[1];
        }
        for (auto &vec: items2) {
            map[vec[0]] += vec[1];
        }
        vector<vector<int>> answer;
        for (int i = 0; i < 1001; i++) {
            if (map[i] != 0) {
                vector<int> pair;
                pair.push_back(i);
                pair.push_back(map[i]);
                answer.push_back(pair);
            }
        }
        return answer;
    }
};
