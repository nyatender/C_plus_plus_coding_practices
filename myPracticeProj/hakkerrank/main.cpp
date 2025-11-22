#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <list>
#include <algorithm>
#include<unordered_set>
#include<unordered_map>

using namespace std;

struct State {
    int i, k, sum1;
    bool operator==(const State& other) const {
        return i == other.i && k == other.k && sum1 == other.sum1;
    }
};
namespace std {
    template<>
    struct hash<State> {
        size_t operator()(const State& s) const {
            return ((hash<int>()(s.i) ^ (hash<int>()(s.k) << 1)) >> 1)
                ^ (hash<int>()(s.sum1) << 1);
        }
    };
}

int dp(vector<pair<int, int>>& items, int i, int k, int sum1, int sum2,
    unordered_map<State, int>& memo) {
    if (k == 0) {
        return min(sum1, sum2);
    }
    if (i >= items.size()) {
        return 0;
    }
    State state = { i, k, sum1 };
    if (memo.count(state)) return memo[state];

    // Option 1: pick current item
    int pick = dp(items, i + 1, k - 1, sum1 + items[i].first, sum2 + items[i].second, memo);

    // Option 2: skip current item
    int skip = dp(items, i + 1, k, sum1, sum2, memo);

    return memo[state] = max(pick, skip);
}

int minimumShopping(vector<int> firstShop, vector<int> secondShop, int k) {
    vector<pair<int, int>> items;
    for (int i = 0; i < firstShop.size(); ++i)
        items.push_back({ firstShop[i], secondShop[i] });
    unordered_map<State, int> memo;
    return dp(items, 0, k, 0, 0, memo);
}

vector<int> max_products(vector<int> prices, vector<pair<int, int>> queries) {

    vector<int> result;
    for (auto& it : queries) {
        int capacity = it.second;
        vector<int> dp(capacity + 1, 0);
        int startIndex = it.first - 1;
        
        for (int i = startIndex; i < prices.size(); i++) {
            for (int j = capacity; j >= startIndex; j--) {
                if (j >= prices[i]) {
                    dp[j] = max(1 + dp[j - prices[i]], dp[j]);
                }
            }
        }
        result.push_back(dp[capacity]);
     }
    return result;
}

int main() {


    vector<int> shop1 = { 6,3,6,5,1 };
    vector<int> shop2 = { 1,4,5,9,2 };
    int k1 = 3;

    vector<int> shop3 = { 10, 2, 4 };
    vector<int> shop4 = { 1, 9, 6 };
    int k2 = 1;

    cout << minimumShopping(shop1, shop2, k1) << endl;
    cout << minimumShopping(shop3, shop4, k2) << endl;



    // Example usage:
    vector<int> prices = { 3, 4, 5, 5, 7 };
    vector<pair<int, int>> queries = { {2, 10}, {1, 24},{5,5} };

    vector<int> results = max_products(prices, queries);

    for (int res : results) {
        cout << res << " ";
    }
    cout << endl;  // Output: 2 2

    return 0;
}
