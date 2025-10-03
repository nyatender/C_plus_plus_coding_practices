//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <climits>
//
//// Top-down DP (memoized) solution
//int minimumCoinTopDown(int total, const std::vector<int>& coins, std::unordered_map<int, int>& memo) {
//    if (total == 0) return 0;
//    if (memo.count(total)) 
//        return memo[total];
//
//    int min_coins = INT_MAX;
//    for (int coin : coins) {
//        if (coin > total) continue;
//        int res = minimumCoinTopDown(total - coin, coins, memo);
//        if (res < min_coins) {
//            min_coins = res;
//        }
//    }
//    min_coins = (min_coins == INT_MAX) ? min_coins : min_coins + 1;
//    memo[total] = min_coins;
//    return min_coins;
//}
//
//// Bottom-up DP solution
//int minimumCoinBottomUp(int total, const std::vector<int>& coins) {
//    std::vector<int> T(total + 1, INT_MAX - 1);
//    std::vector<int> R(total + 1, -1);
//    T[0] = 0;
//    for (size_t j = 0; j < coins.size(); ++j) {
//        for (int i = 1; i <= total; ++i) {
//            if (i >= coins[j]) {
//                if (T[i - coins[j]] + 1 < T[i]) {
//                    T[i] = 1 + T[i - coins[j]];
//                    R[i] = j;
//                }
//            }
//        }
//    }
//
//    // Print coin combination logic adapted from Java code
//    if (R[total] == -1) {
//        std::cout << "No solution is possible\n";
//    }
//    else {
//        std::cout << "Coins used to form total ";
//        int start = total;
//        while (start > 0) {
//            int j = R[start];
//            std::cout << coins[j] << " ";
//            start -= coins[j];
//        }
//        std::cout << "\n";
//    }
//
//    return T[total];
//}
//
//int main3() {
//    int total = 13;
//    std::vector<int> coins = { 7, 3, 2, 6 };
//    std::unordered_map<int, int> memo;
//    int topDownValue = minimumCoinTopDown(total, coins, memo);
//    int bottomUpValue = minimumCoinBottomUp(total, coins);
//    std::cout << "Bottom up and top down result " << bottomUpValue << " " << topDownValue << std::endl;
//    return 0;
//}
