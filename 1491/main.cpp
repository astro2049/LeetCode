#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    double average(vector<int>& salary) {
        int maxSalary = 0, minSalary = 1000000, salarySum = 0;
        for (int salaryOfAnEmployee : salary) {
            if (salaryOfAnEmployee > maxSalary) {
                maxSalary = salaryOfAnEmployee;
            }
            if (salaryOfAnEmployee < minSalary) {
                minSalary = salaryOfAnEmployee;
            }
            salarySum += salaryOfAnEmployee;
        }

        return (double)(salarySum - maxSalary - minSalary) / (double)(salary.size() - 2);
    }
};
