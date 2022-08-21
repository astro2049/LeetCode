#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
        vector<int> differences(n, 0);
        for (auto booking: bookings) {
            int first = booking[0], last = booking[1], seats = booking[2];
            differences[first - 1] += seats;
            if (last != n) {
                differences[last] -= seats;
            }
        }

        for (int i = 1; i < n; i++) {
            differences[i] += differences[i - 1];
        }
        return differences;
    }
};
