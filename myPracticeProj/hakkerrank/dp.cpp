#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int dp(const vector<pair<int, int>>& items, int i, int k, int sum1, vector<vector<vector<int>>>& memo) {
    if (k == 0) return sum1; // or min(sum1, sum2) if required by the problem
    if (i >= items.size()) return -1e9; // impossible state, make sure it never outcompetes

    if (memo[i][k][sum1] != -1) return memo[i][k][sum1];

    // Pick current item
    int pick = dp(items, i + 1, k - 1, sum1 + items[i].first, memo);
    // Skip current item
    int skip = dp(items, i + 1, k, sum1, memo);

    memo[i][k][sum1] = max(pick, skip);
    return memo[i][k][sum1];
}

int minimumShopping(vector<int> firstShop, vector<int> secondShop, int k) {
    vector<pair<int, int>> items;
    int max_sum1 = 0;
    for (int v : firstShop) max_sum1 += v;
    for (int i = 0; i < firstShop.size(); ++i)
        items.push_back({ firstShop[i], secondShop[i] });

    // +1 to size for 0-based, and to include max_sum1 itself
    vector<vector<vector<int>>> memo(firstShop.size() + 1, vector<vector<int>>(k + 1, vector<int>(max_sum1 + 1, -1)));

    return dp(items, 0, k, 0, memo);
}

//#include <vector>
//#include <algorithm>
//using namespace std;

int minimumShopping(vector<int> firstShop, vector<int> secondShop, int k) {
    int n = firstShop.size();
    int max_sum = accumulate(firstShop.begin(), firstShop.end(), 0);

    // dp[i][c][s] = true if it’s possible to pick c items with sum s from firstShop
    vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(k + 1, vector<bool>(max_sum + 1, false)));
    dp[0][0][0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int c = 0; c <= k; ++c) {
            for (int s = 0; s <= max_sum; ++s) {
                if (dp[i - 1][c][s]) {
                    // Don’t pick current
                    dp[i][c][s] = true;
                    // Pick current
                    if (c + 1 <= k && s + firstShop[i - 1] <= max_sum)
                        dp[i][c + 1][s + firstShop[i - 1]] = true;
                }
            }
        }
    }

    // Compute total secondShop sum for all picks
    int best = 0;
    int totalSecond = accumulate(secondShop.begin(), secondShop.end(), 0);

    for (int s = 0; s <= max_sum; ++s) {
        if (dp[n][k][s]) {
            // All choices with sum s can be paired with some selection from secondShop
            // We select k items, so their total second shop values is totalSecond - sum_of_unpicked
            // But to balance, we can just treat sum1 = s, sum2 = (sum of k selected in secondShop)
            // That value is ambiguous for this problem setup; in general you can solve for actual indices if required.
            // For demonstration, we assume the exact k items are common to both selections.
            best = max(best, min(s, totalSecond - (max_sum - s)));
        }
    }
    return best;
}

