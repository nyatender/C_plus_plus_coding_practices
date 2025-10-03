
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <ranges>


using namespace std;

void minimumShoppingUtils(vector<pair<int, int>> firstAndSecondShop, int i, int sum1, int sum2, int& result, int k) {
    if (k == 0) {
        int sumSoFar = min(sum1, sum2);
        result = max(result, sumSoFar);
        return;
    }

    if (i >= firstAndSecondShop.size())
        return;

    minimumShoppingUtils(firstAndSecondShop, i + 1, sum1 + firstAndSecondShop[i].first,
        sum2 + firstAndSecondShop[i].second, result, k - 1);
    minimumShoppingUtils(firstAndSecondShop, i + 1, sum1, sum2, result, k);
}

int minimumShopping(vector<int> firstShop, vector<int> secondShop, int k) {
    vector<pair<int, int>> firstAndSecondShop;
    for (int i = 0; i < firstShop.size(); i++) {
        firstAndSecondShop.push_back({ firstShop[i], secondShop[i] });
    }
    int result = 0;
    minimumShoppingUtils(firstAndSecondShop, 0, 0, 0, result, k);

    return result;
}

int main_microsoft1()
{
    // Test case 1
    // int k = 3;
    //vector<int> firstShop = {6,3,6,5,1};
    //vector<int> secondShop = {1,4,5,9,2};

    // Test case 2
    int k = 1;
    vector<int> firstShop = { 10,2,4 };
    vector<int> secondShop = { 1,9,6 };

    cout << minimumShopping(firstShop, secondShop, k);

    return 0;
}