#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <unordered_set>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

// Helper function for subvector slicing (for compilers without std::ranges::views::slice)
std::vector<int> slice(const std::vector<int>& arr, size_t l, size_t r) {
    return std::vector<int>(arr.begin() + l, arr.begin() + r);
}

class HouseRobber {
public:
    static int houseRobber(const std::vector<int>& money) {
        if (money.empty()) {
            return 0;
        }

        if (money.size() == 1) {
            return money[0];
        }

        // Use helper slicing function or views::slice if available
        int loot1 = houseRobberHelper(slice(money, 0, money.size() - 1));
        int loot2 = houseRobberHelper(slice(money, 1, money.size()));
        return std::max(loot1, loot2);
    }

private:
    static int houseRobberHelper(const std::vector<int>& money) {
        if (money.empty())
            return 0;
        std::vector<int> lookupArray(money.size() + 1, 0);
        lookupArray[0] = 0;
        lookupArray[1] = money[0];

        for (size_t i = 2; i <= money.size(); ++i) {
            lookupArray[i] = std::max(money[i - 1] + lookupArray[i - 2], lookupArray[i - 1]);
        }
        return lookupArray[money.size()];
    }
};

// Utility to print vector as string
std::string vecToStr(const std::vector<int>& vec) {
    std::string ret = "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        ret += std::to_string(vec[i]);
        if (i + 1 < vec.size()) ret += ", ";
    }
    ret += "]";
    return ret;
}



int main_house() {
    std::vector<std::vector<int>> inputs = {
        {2, 3, 2},
        {1, 2, 3, 1},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
        {7, 4, 1, 9, 3},
        {}
    };

    for (size_t i = 0; i < inputs.size(); ++i) {
        std::cout << (i + 1) << ".\tHouses: " << vecToStr(inputs[i]) << "\n";
        std::cout << "\n\tMaximum loot: " << HouseRobber::houseRobber(inputs[i]) << "\n";
        std::cout << "-" << std::string(100, '-') << "\n";
    }

    return 0;
}
