#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        vector<int> days;
        vector<int> answers(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            if (days.empty()) {
                days.push_back(i);
            } else {
                while (!days.empty()) {
                    if (temperatures[days.back()] < temperatures[i]) {
                        answers[days.back()] = i - days.back();
                        days.pop_back();
                    } else {
                        break;
                    }
                }
                days.push_back(i);
            }
        }
        return answers;
    }
};
