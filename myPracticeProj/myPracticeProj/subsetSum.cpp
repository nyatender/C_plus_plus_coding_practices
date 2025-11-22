
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <unordered_set>
#include <string>
#include <set>
#include <queue>
#include <stack>

using namespace std;

//class Solution {
//public:
//    bool canPartitionUtis(vector<int>& nums, int i, int sum, int totalSum) {
//        if (i >= nums.size())
//            return false;
//
//        if (sum + nums[i] == totalSum)
//            return true;
//
//        if (!canPartitionUtis(nums, i + 1, sum + nums[i], totalSum))
//            return canPartitionUtis(nums, i + 1, sum, totalSum);
//
//        return false;
//    }
//
//    bool canPartition(vector<int>& nums) {
//
//        // int row = nums
//        // vector<vector<bool> dp(nums) 
//        int sum = 0;
//        for (auto& item : nums)
//            sum += item;
//
//        if (sum % 2 != 0)
//            return false;
//
//        return canPartitionUtis(nums, 0, 0, sum / 2);
//
//    }
//};
//
//void countLeftAndRightRec(const string& input, unordered_map<char, int>& countFrequency,
//                        int i, int j, unordered_set<string>& result, unordered_set<char>& vowels) {
//    if (countFrequency.size() != vowels.size())
//        return;
//    else {
//        string sr = std::to_string(i) + "-" + std::to_string(j);
//        if(result.contains(sr))
//            return;
//        result.insert(sr);
//        
//        countFrequency[input[i]]--;
//        if (countFrequency[input[i]] == 0)
//            countFrequency.erase(input[i]);
//        countLeftAndRightRec(input, countFrequency, i + 1, j, result, vowels);
//        if(!countFrequency.contains(input[i]))
//            countFrequency.insert({ input[i], 0 });
//        countFrequency[input[i]]++;
//
//        countFrequency[input[j]]--;
//        if (countFrequency[input[j]] == 0)
//            countFrequency.erase(input[j]);
//        countLeftAndRightRec(input, countFrequency, i, j-1, result, vowels);
//        if (!countFrequency.contains(input[j]))
//            countFrequency.insert({ input[j], 0 });
//        countFrequency[input[j]]++;
//    }
//}
//
//void getSubString(string input) {
//    unordered_map<char, int> countFrequency;
//    unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
//    unordered_set<string> result;
//    int k = 0;
//    int previous_vowels = 0;
//    int count = 0;
//    // aeioaexaaeuiou -> 4
//    // aaeiouxa -> 2
//
//    for (int i = 0; i < input.size(); i++) {
//        if (vowels.contains(input[i])) {
//            if (!countFrequency.contains(input[i]))
//                countFrequency.insert({ input[i], 0 });
//            countFrequency[input[i]]++;
//            if (countFrequency.size() == vowels.size()) {
//                int k = previous_vowels;
//                countLeftAndRightRec(input, countFrequency, k, i, result, vowels);
//            }
//        }
//        else {
//            previous_vowels = i + 1;
//            countFrequency.clear();
//        }
//
//    }
//    // return result.size();
//
//}
//
////===========
//long getMaximumProfit(long* Arr, int n) {
//    // Create two arrays to store the profits ahead of the current position (0 for not holding, 1 for holding)
//    vector<long> ahead(2, 0);
//    vector<long> cur(2, 0);
//
//    // Base condition: When there are no stocks left, the profit is 0.
//    ahead[0] = ahead[1] = 0;
//
//    long profit;
//
//    // Loop through the array in reverse order
//    for (int ind = n - 1; ind >= 0; ind--) {
//        for (int buy = 0; buy <= 1; buy++) {
//            if (buy == 0) { // We can buy the stock
//                profit = max(0 + ahead[0], -Arr[ind] + ahead[1]);
//            }
//
//            if (buy == 1) { // We can sell the stock
//                profit = max(0 + ahead[1], Arr[ind] + ahead[0]);
//            }
//            cur[buy] = profit;
//        }
//
//        ahead = cur; // Update the "ahead" array with the current values
//    }
//
//    // The maximum profit is stored in cur[0] after all calculations
//    return cur[0];
//}
//
//
////=============
///*
//* given a string "123456789" and sum 100 print all the possible comboinations
//* you can use + and - or nothing between the numbers
//*  1 + 2 + 3 - 4 + 5 + 6 + 78 + 9 = 100
//*/ 
//void printCombinationUtils(string str, int i, int sum, int tempSum, string curResult, vector<string>& result) {
//    if (i > str.size()) {
//        return;
//    }
//
//    int currNum = (str[i] - '0');
//    if (sum == tempSum) {
//        result.push_back(curResult);
//    }
//
//    /*if(tempSum < sum)*/
//        printCombinationUtils(str, i + 1, sum, tempSum + currNum, curResult + "+" + to_string(currNum), result);
//
//    //else if(tempSum > sum)
//        printCombinationUtils(str, i + 1, sum, tempSum - currNum, curResult + "-" + to_string(currNum), result);
//
//    //else 
//        
//
//}
//
//void printCombination(string str) {
//    vector<string> result;
//    for (int i = 0; i < str.size()-3;i++) {
//        for (int j = i; j <= i+3; j++) {
//            int curr = str.substr(i, j).size() == 0 ? 0 : stoi(str.substr(i, j));
//            printCombinationUtils(str.substr(j, str.size()), j, 100, curr, str.substr(0, i), result);
//        }
//    }
//    //for (auto& it : str) {
//    //    cout << it << ends;
//    //}
//    cout << " hello " << ends;
//}
//
//
//// Hash for state: i, k, sum1 (sum2 can be deduced: sum2 = total_sum2 - taken_sum2)
//struct State {
//    int i, k, sum1;
//    bool operator==(const State& other) const {
//        return i == other.i && k == other.k && sum1 == other.sum1;
//    }
//};
//namespace std {
//    template<>
//    struct hash<State> {
//        size_t operator()(const State& s) const {
//            return ((hash<int>()(s.i) ^ (hash<int>()(s.k) << 1)) >> 1)
//                ^ (hash<int>()(s.sum1) << 1);
//        }
//    };
//}
//
//int dp(vector<pair<int, int>>& items, int i, int k, int sum1, int sum2,
//    unordered_map<State, int>& memo) {
//    if (k == 0) {
//        return min(sum1, sum2);
//    }
//    if (i >= items.size()) {
//        return 0;
//    }
//    State state = { i, k, sum1 };
//    if (memo.count(state)) return memo[state];
//
//    // Option 1: pick current item
//    int pick = dp(items, i + 1, k - 1, sum1 + items[i].first, sum2 + items[i].second, memo);
//
//    // Option 2: skip current item
//    int skip = dp(items, i + 1, k, sum1, sum2, memo);
//
//    return memo[state] = max(pick, skip);
//}
//
//int minimumShopping(vector<int> firstShop, vector<int> secondShop, int k) {
//    vector<pair<int, int>> items;
//    for (int i = 0; i < firstShop.size(); ++i)
//        items.push_back({ firstShop[i], secondShop[i] });
//    unordered_map<State, int> memo;
//    return dp(items, 0, k, 0, 0, memo);
//}
//
///*
//* given numbers from 1 to 9 in a string form i.e. "123456789". your task is to find all the combination of these number
//* where number is in increading order and can be add and subrtract from each other 
//* and yield out as 100
//example: one of the combination is 1+2+3-4+5+6+78+9
//
//* 
//*/
//
//
////int main() {
////    printCombination("123456789");
////
////    const int n = 6;
////    long Arr[n] = { 7, 1, 5, 3, 6, 4 };
////
////    // Call the getMaximumProfit function and print the result
////    cout << "The maximum profit that can be generated is " << getMaximumProfit(Arr, n);
////
////
////    /*
////    vector<string> input = { "aeioaexaaeuiou", "aaeiouxa", "aaaeiouuu" };
////    for (int i = 0; i < input.size(); i++) {
////        cout << getSubString(input[i]) << " ";
////    }
////
////    */
////}
//
//
//
////    vector<int> vec = { 3,3,3,4,5 };
////    Solution obj;
////    obj.canPartition(vec) == 0 ? (cout << "false") : (cout << "true");
////}
//
//
//// sunset view
//// river size
//// longest peek
//// Binary tree Diameter
//// Levenshtein distance
//// min rewards -> hard
//// boggle board -> hard
//// sort k sorted array
//// group anagram
//// longest palindrome by concatenating 2 letter
//
//void printCombination(string str, int index, int currSum, int totalSum, string exp, vector<string>& result) {
//
//    if (index >= str.size()) {
//        if (currSum == totalSum) {
//            result.push_back(exp);
//        }
//        return;
//    }
//
//    for (int next = 1; index + next <= str.size(); next++) {
//
//        string numString = str.substr(index, next);
//        long num = stol(numString);
//
//        if (index == 0) {
//            printCombination(str, index + next, num, totalSum, numString, result);
//        }
//        else {
//
//            printCombination(str, index + next, currSum + num, totalSum, exp + " + " + numString, result);
//
//            printCombination(str, index + next, currSum - num, totalSum, exp + " - " + numString, result);
//        }
//
//    }
//}
//
///*
//
//An investor is looking to maximize their capital by undertaking a set of profitable projects. 
//Due to limited time and resources, 
//they can complete at most k distinct projects.
//There are
//n
//n
// available projects. Each project i has:
//
//A profit of profits[i] earned upon completion.
//
//A minimum capital requirement of capital[i] needed to start the project.
//
//The investor starts with an initial capital of c. After completing a project, 
//its profit is immediately added to the investor's current capital.
//
//The goal is to choose up to k different projects in a way that maximizes the investor’s final capital. 
//Return the maximum capital achievable after completing these projects.
//
//k = 3
//c = 1
//
//total capital: 
//
//1 -> 4
//3 -> 11
//5 -> 17
//
//profits    [3, 5, 7, 6]
//capitals   [1, 2, 3, 5]
//
//*/
//
////void dfs(int pos, long long currVal, string expr, const string& digits, vector<string>& result) {
////    if (pos == digits.length()) {
////        if (currVal == 100) result.push_back(expr);
////        return;
////    }
////    for (int len = 1; len <= digits.length() - pos; ++len) {
////        string part = digits.substr(pos, len);
////        long long num = stoll(part);
////        if (pos == 0) {
////            // First number, no operator
////            dfs(pos + len, num, part, digits, result);
////        }
////        else {
////            // Plus operator
////            dfs(pos + len, currVal + num, expr + "+" + part, digits, result);
////            // Minus operator
////            dfs(pos + len, currVal - num, expr + "-" + part, digits, result);
////        }
////    }
////}
//
////void getLargestOddString(string str, int pos, vector<long>& result) {
////
////    if (pos >= str.length())
////        return;
////
////    for (int i = 1; i < str.length(); i++) {
////        string numStr = str.substr(pos, i);
////        long num = stol(numStr);
////        if ((num & 1) == 1) {
////            result[0] = std::max(num, result[0]);
////        }
////        getLargestOddString(str, pos + i, result);
////    }
////
////}
//
////bool wordBreak(string s, vector<string>& wordDict) {
////    int n = s.length();
////    vector<bool> dp(n + 1, false);
////    dp[0] = true;
////    set<string> disc(wordDict.begin(), wordDict.end());
////
////    for (int i = 1; i <= n; i++) {
////        for (int j = 0; j < i; j++) {
////            cout << std::to_string(j) + " - " + std::to_string(i) + " " << s.substr(j, i-j) << endl;
////            if (dp[j] && disc.contains(s.substr(j, i))) {
////                dp[i] = true;
////                break;
////            }
////        }
////    }
////
////    return dp[n];
////}
//
//struct node {
//    int data;
//    node* left;
//    node* right;
//};
//
//void BtToList(node* root) {
//    if (root == nullptr)
//        return;
//
//    BtToList(root->left);
//    BtToList(root->right);
//
//    node* temp = root->left;
//    while (temp->right != nullptr)
//        temp = temp->right;
//
//    temp->right = root->right;
//    root->right = root->left;
//    root->left = nullptr;
//
//}
//
//void successor(node* root, node* suc) {
//    node* succer = nullptr;
//
//    while (root != nullptr) {
//        if (suc->data >= root->data) {
//            root = root->right;
//        }
//        else {
//            succer = root;
//            root = root->left;
//        }
//    }
//
//}
//
//int deletedUtils(node* root, node* del);
//int deleted(node* root, node* del) {
//    return max(deletedUtils(root->left, del), deletedUtils(root->right, del));
//}
//
//
//int deletedUtils(node* root, node* del) {
//    
//    if (root == nullptr || root->data == del->data)
//        return 0;
//
//    int left = deleted(root->left, del);
//    int right = deleted(root->right, del);
//
//    return 1 + max(left, right);
//}
//
//
//int meetingRooms(vector < vector<int>> meeting, int rooms) {
//
//    auto cmp1 = [](const vector<int>& v1, const vector<int>& v2) {
//        return v1[0] < v2[0];
//     };
//
//    auto cmp = [](int v1[], int v2[]) {
//        return v1[0] < v2[0];
//        };
//
//    priority_queue<int> minHeap;
//    //priority_queue<int[], std::vector<int[]>, greater<int[]>> maxHeap;
//    priority_queue<int[], std::vector<int[]>, decltype(cmp)> maxHeap(cmp);
//
//    for (int i = 0; i < rooms; i++)
//        minHeap.push(i);
//
//    for (int i = 0; i < meeting.size(); i++) {
//
//    }
//
//
//    return 0;
//
//}
//
//int digitsParity(int num) {
//    auto cmp = [](int a, int b) {
//        return a < b;
//        };
//    priority_queue<int, std::vector<int>, decltype(cmp)> maxHeap1(cmp);
//    priority_queue<int, std::vector<int>, decltype(cmp)> maxHeap2(cmp);
//
//    bool reverse = true;
//    int count = 0;
//    while (num > 0) {
//        int lastDigit = num % 10;
//        num = num / 10;
//        if (reverse) {
//            maxHeap1.push(lastDigit);
//        }
//        else {
//            maxHeap1.push(lastDigit);
//        }
//        count++;
//        reverse = !reverse;
//    }
//    // 12323
//    num = 0;
//    while (!maxHeap1.empty() && !maxHeap2.empty()) {
//        if (reverse == false) {
//            num = num * 10 + maxHeap1.top();
//            maxHeap1.pop();
//        }
//        else {
//            num = num * 10 + maxHeap2.top();
//            maxHeap2.pop();
//        }
//    }
//    if (!maxHeap1.empty()) {
//        num = num * 10 + maxHeap1.top();
//    }
//    else if (!maxHeap2.empty()) {
//        num = num * 10 + maxHeap2.top();
//    }
//    return num;
//}
//
///*
//
//0-2, 2-4, 3-5
//
//0 - 1
//
//
//0-2
//
//0 - 1
//
//
//98123
//
//
//9 3 1
//8 2
//
//9 8 3 2 1
//
//
//
//*/
//
///*
//* 
//* 2[ax2[fw]]3[a]
//* 
//* 2 ax
//* 2 2  | ax fw
//* 2 | ax result = fwfw
//* 2 | axfwfw
//* axfwfwaxfwfw
//* 3 | a
//* aaa
//* fwfw
//*/
//
//string getAppendedString(string str, int count) {
//    while (count-- > 0) {
//        str += str;
//    }
//
//}
//
//int removeString(string input) {
//    stack<char> st;
//    stack<int> stNumCount;
//    
//
//    for (auto ch : input) {
//        if (st.empty()) {
//            st.push(ch);
//            continue;
//        }
//
//        if ((ch == 'B' && !st.empty() && st.top() == 'A') || 
//            (ch == 'D' && !st.empty() && st.top() == 'C')) {
//            st.pop();
//        }
//        else {
//            st.push(ch);
//        }
//    }
//    return st.size();
//}
//
//string decodeString(string input) {
//
//    if (input.size() == 0)
//        return input;
//
//    string result = "";
//    string tempDecodeString = "";
//    int count = 0;
//    string temp = "";
//    int tempCount = 0;
//
//    stack<string> st;
//    stack<int> stNumCount;
//
//    for (int index = 0; index < input.size(); index++) {
//        string tempString = "";
//        const char ch = input[index];
//        switch (ch) {
//        case ']':
//            temp = "";
//            tempCount = 0;
//            if (!st.empty()) {
//                temp = st.top();
//                st.pop();
//            }
//            if (!stNumCount.empty()) {
//                tempCount = stNumCount.top();
//                stNumCount.pop();
//            }
//            tempDecodeString += getAppendedString(tempDecodeString, tempCount) + temp;
//            break;
//        case '[':
//            stNumCount.push(count);
//            st.push(tempDecodeString);
//            count = 0;
//            tempDecodeString = "";
//            break;
//        default:
//            int tempCount = ch - '0';
//            if (count <= 9 && count >= 0) {
//                count = tempCount * 10 + count;
//            }
//            else {
//                tempDecodeString += std::to_string(ch);
//            }
//        }
//
//    }
//
//}
//
//
//int main_() {
//    //vector<string> vec = { "apple", "pen" };
//    //string str = "applepenapple";
//   // cout << wordBreak(str, vec);
//
//    string digits = "123456789";
//    vector<string> result;
//    //dfs(0, 0, "", digits, result);
//    printCombination(digits, 0, 0, 100, "", result);
//
//    for (auto& expr : result) {
//        cout << expr << endl;
//    }
//    return 0;
//}


/*
0 1 1 1
1 1 1 2
1 1 2 1
1 2 1 1


1234523467

123.45.234.67

0 -> 1 -> 2 -> 3
1 -> 4
2 -> 4
3 -> 4

1 -> 0
2 -> 0
3 -> 1
4 -> 3

in-degree
0 -> 2
1 -> 1
3 -> 1
4 -> 1

*/