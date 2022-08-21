#include <iostream>
#include "vector"
#include "map"
#include "algorithm"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons) {
        map<int, int> differences;
        for (auto flower: flowers) {
            differences[flower[0]]++;
            differences[flower[1] + 1]--;
        }

        vector<pair<int, int>> visitDays;
        for (int i = 0; i < persons.size(); i++) {
            visitDays.push_back(pair<int, int>(persons[i], i));
        }
        sort(visitDays.begin(), visitDays.end(), [](auto a, auto b) { return a.first < b.first; });

        vector<int> answer(persons.size());
        auto difference = differences.begin();
        int count = 0;
        for (auto visitDay: visitDays) {
            int day = visitDay.first;
            while (difference != differences.end() && difference->first <= day) {
                count += difference->second;
                difference++;
            }
            answer[visitDay.second] = count;
        }

        return answer;
    }
};
