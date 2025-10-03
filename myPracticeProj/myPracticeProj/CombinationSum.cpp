//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<vector<int>> combinationSum(vector<int>& nums, int target) {
//    vector<vector<vector<int>>> dp(target + 1);
//    dp[0].push_back({});
//    for (int i = 1; i <= target; ++i) {
//        for (int j = 0; j < nums.size(); ++j) {
//            if (nums[j] <= i) {
//                for (const auto& prev : dp[i - nums[j]]) {
//                    vector<int> temp = prev;
//                    temp.push_back(nums[j]);
//                    sort(temp.begin(), temp.end());
//                    // Avoid duplicates
//                    if (find(dp[i].begin(), dp[i].end(), temp) == dp[i].end()) {
//                        dp[i].push_back(temp);
//                    }
//                }
//            }
//        }
//    }
//    return dp[target];
//}
//
//int main4() {
//    vector<vector<int>> nums = {
//        {2, 3, 5},
//        {3, 6, 7, 8},
//        {4, 5, 6, 9},
//        {20, 25, 30, 35, 40},
//        {3, 5, 7}
//    };
//    vector<int> targets = { 5, 15, 11, 40, 15 };
//    for (int i = 0; i < nums.size(); ++i) {
//        cout << (i + 1) << ". \tnums: [";
//        for (int k = 0; k < nums[i].size(); ++k) {
//            cout << nums[i][k];
//            if (k != nums[i].size() - 1) cout << ", ";
//        }
//        cout << "]" << endl;
//        cout << "\tTarget: " << targets[i] << endl;
//
//        vector<vector<int>> combinations = combinationSum(nums[i], targets[i]);
//
//        cout << "\tCombinations: [";
//        for (int j = 0; j < combinations.size(); ++j) {
//            cout << "[";
//            for (int k = 0; k < combinations[j].size(); ++k) {
//                cout << combinations[j][k];
//                if (k != combinations[j].size() - 1) cout << ", ";
//            }
//            cout << "]";
//            if (j != combinations.size() - 1) cout << ", ";
//        }
//        cout << "]" << endl;
//        cout << string(100, '-') << endl;
//    }
//    return 0;
//}
