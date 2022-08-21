#include <iostream>
#include "vector"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience) {
        int hours = 0;
        int myEnergy = initialEnergy, myExp = initialExperience;
        for (int i = 0; i < energy.size(); i++) {
            if (myEnergy > energy[i] && myExp > experience[i]) {
                myEnergy -= energy[i];
                myExp += experience[i];
            } else {
                if (myEnergy <= energy[i] && myExp <= experience[i]) {
                    hours += (energy[i] + 1 - myEnergy) + (experience[i] + 1 - myExp);
                    myEnergy = 1;
                    myExp = experience[i] * 2 + 1;
                } else if (myEnergy <= energy[i]) {
                    hours += energy[i] + 1 - myEnergy;
                    myEnergy = 1;
                    myExp += experience[i];
                } else {
                    hours += experience[i] + 1 - myExp;
                    myEnergy -= energy[i];
                    myExp = experience[i] * 2 + 1;
                }
            }
        }
        return hours;
    }
};
