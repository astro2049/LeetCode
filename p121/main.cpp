#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int buyDay = 0, sellDay = 1;
        while (buyDay < prices.size() - 1 && sellDay < prices.size()) {
            int profit = prices[sellDay] - prices[buyDay];
            maxProfit = max(maxProfit, profit);
            if (prices[buyDay] > prices[sellDay]) {
                buyDay = sellDay;
            }
            sellDay++;
        }
        return maxProfit;
    }
};
