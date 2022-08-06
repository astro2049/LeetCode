#include <iostream>
#include "vector"
#include "queue"
#include "unordered_map"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    long long taskSchedulerII(vector<int> &tasksV, int space) {
        queue<int> tasks;
        for (int task: tasksV) {
            tasks.push(task);
        }
        long long day = 1;
        unordered_map<int, long long> lastCompletion;
        while (!tasks.empty()) {
            int t = tasks.front();
            if (lastCompletion.find(t) != lastCompletion.end()) {
                if (day <= lastCompletion[t] + space) {
                    day = lastCompletion[t] + space + 1;
                }
                lastCompletion[t] = day;
                tasks.pop();
            } else {
                lastCompletion.insert(pair<int, long long>(t, day));
                tasks.pop();
            }
            day++;
        }
        return day - 1;
    }
};
