//#include<stdio.h>
//#include <iostream>
//#include<sstream>
//#include<unordered_map>
//#include<map>
//#include<vector>
//
//using namespace std;
//
//long palindromic(string str) {
//	int num = stoi(str);
//
//	unordered_map<int, int> map;
//
//    return 0;
//}
//
//void functionOrderAndUnorderedMap() {
//    std::map<int, std::string> ordered = { {3, "three"}, {1, "one"}, {2, "two"} };
//    std::unordered_map<int, std::string> unordered = { {3, "three"}, {1, "one"}, {2, "two"} };
//
//    std::cout << "map (ordered):\n";
//    for (auto& pair : ordered)
//        std::cout << pair.first << " : " << pair.second << "\n";
//
//    std::cout << "unordered_map:\n";
//    for (auto& pair : unordered)
//        std::cout << pair.first << " : " << pair.second << "\n";
//
//}
//
//int numberOfSolutions(int total, const std::vector<int>& coins) {
//    int n = coins.size();
//    std::vector<std::vector<int>> temp(n + 1, std::vector<int>(total + 1, 0));
//
//    // Initialize base cases
//    for (int i = 0; i <= n; i++) {
//        temp[i][0] = 1;
//    }
//
//    // Fill the DP table
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= total; j++) {
//            if (coins[i - 1] > j) {
//                temp[i][j] = temp[i - 1][j];
//            }
//            else {
//                temp[i][j] = temp[i][j - coins[i - 1]] + temp[i - 1][j];
//            }
//        }
//    }
//    return temp[n][total];
//}
//
//int longestPalindromeutils1(string s, int i,int j, string result, int& maxLen) {
//    if (i > j)
//        return 0;
//    if (i == j)
//        return 1;
//
//    if (s[i] == s[j]) {
//        int maxLenSoFar = 2 + longestPalindromeutils1(s, i + 1, j - 1, result, maxLen);
//        if (maxLenSoFar > maxLen) {
//            maxLen = maxLenSoFar;
//            result = s.substr(i, j+1);
//        }
//    }
//    else {
//        return max(longestPalindromeutils1(s, i + 1, j, result, maxLen),
//            longestPalindromeutils1(s, i, j - 1, result, maxLen));
//    }
//}
//
//int longestPalindromeutils(string s, int i, int j, string result) {
//    if (i > j)
//        return 0;
//
//    while (i <= j) {
//        if (s[i] == s[j]) {
//            i = i + 1;
//            j = j - 1;
//        }
//        else {
//            int maxSoFar = max(longestPalindromeutils(s, i + 1, j, result),
//                longestPalindromeutils(s, i, j - 1, result));
//        }
//
//    }
//}
//
//
//
///*    if (i == j)
//        return 1;
//
//    if (s[i] == s[j]) {
//        return 2 + longestPalindromeutils(s, i + 1, j - 1);
//    }
//    else {
//        return max(longestPalindromeutils(s, i + 1, j), longestPalindromeutils(s, i, j - 1));
//    }
//}
//*/
//
//int main6() {
//
//	cout << " hello ";
//
//    int arr[] = { 1,2 };
//
//    functionOrderAndUnorderedMap();
//
//    return 0;
//}