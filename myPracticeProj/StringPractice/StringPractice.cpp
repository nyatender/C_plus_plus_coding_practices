// StringPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <ranges>

using namespace std;

//class Solution {
//public:

    //struct palindromInfo {
    //    int start;
    //    int end;
    //    int val;
    //    palindromInfo() :start(0), end(0), val(-1) {}
    //    palindromInfo(int i, int j, int k) :start(i), end(j), val(k) {}
    //};

    //string longestPalindrome(string s) {
    //    if (s.empty() || s.size() == 1)
    //        return s;
    //    int maxLen = 0;
    //    vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
    //    palindromInfo result = longestPalindromeutils(s, 0, s.size() - 1, dp, maxLen);
    //    return string(s.begin() + result.start, s.end() + result.end);
    //}

//    palindromInfo longestPalindromeutils(string s, int i, int j, vector<vector<int>> dp, int& maxLen) {
//        if (i > j)
//            return palindromInfo();
//
//        if (i == j)
//            return palindromInfo(i, j, 1);
//
//        palindromInfo result;
//        if (dp[i][j] == -1) {
//            if (s[i] == s[j]) {
//                int remLen = j - i - 1;
//                palindromInfo retVal = longestPalindromeutils(s, i + 1, j - 1, dp, maxLen);
//                if (retVal.val == remLen) {
//                    dp[i][j] = 2 + remLen;
//                    if (maxLen < dp[i][j]) {
//                        result.start = i;
//                        result.end = j;
//                        result.val = dp[i][j];
//
//                        maxLen = dp[i][j];
//                    }
//                }
//            }
//            else {
//                palindromInfo len1 = longestPalindromeutils(s, i, j - 1, dp, maxLen);
//                palindromInfo len2 = longestPalindromeutils(s, i + 1, j, dp, maxLen);
//
//                if (len1.val > len2.val) {
//                    dp[i][j] = len1.val;
//
//                    if (maxLen < dp[i][j]) {
//                        result.start = i;
//                        result.end = j-1;
//                        result.val = dp[i][j];
//
//                        maxLen = dp[i][j];
//                    }
//                }
//                else if(len1.val < len2.val) {
//                    dp[i][j] = len2.val;
//
//                    if (maxLen < dp[i][j]) {
//                        result.start = i+1;
//                        result.end = j;
//                        result.val = dp[i][j];
//
//                        maxLen = dp[i][j];
//                    }
//                }
//            }
//        }
//
//        return result;
//    }
//};

void groupAngram(list<string> words) {

    unordered_map < string, list<string>> disc;
    for (string str : words) {
        string val = str;
        sort(val.begin(), val.end());
        if (!disc.contains(val))
            disc.insert({ val, list<string>() });

        disc[val].push_back(str);
    }

    for (auto& item : disc) {
        cout << " { ";
        for (auto& val : item.second)
            cout << val << "  ";
        cout << "}\n";
    }

}

void fun() {
    string s = "abc";
    map<string, bool> m;
    for (int i = 0; i < s.size(); i++) {
        string str = string(s.begin() + i, s.begin() + i + 1);
        m[str] = 1;
    }
}

//void strTok() {
//    char str[] = "Geeks-for-Geeks";
//
//    // Returns first token 
//    char* token = strtok(str, "-");
//
//    // Keep printing tokens while one of the
//    // delimiters present in str[].
//    while (token != NULL)
//    {
//        printf("%s\n", token);
//        token = strtok(NULL, "-");
//    }
//}


void sunset(int arr[], int n, int dir) {
    vector<int> result;
    int preMax = arr[n - 1];
    if (dir == 0) {
        result.push_back(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > preMax) {
                preMax = arr[i];
                result.push_back(i);
            }
        }
    }
    else {
        preMax = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > preMax) {
                preMax = arr[i];
                result.push_back(i);
            }
        }
    }
}

void sortStack(stack<int>& st) {
    if (st.empty() || st.size() == 1)
        return;

    int preTopElm = st.top();
    st.pop();
    sortStack(st);
    int currentTop = st.top();
    if (preTopElm < currentTop) {
        st.pop();
        st.push(preTopElm);
        sortStack(st); 
        st.push(currentTop);
    }
    else {
        st.push(preTopElm);
    }

}

//void preOrderToBSTUtils(int arr[], int n, int i) {
//    if (i >= n) {
//        return null;
//    }
//}
//
//void preOrderToBST(int arr[], int n) {
//    
//}

void zigzag(vector<vector<int>> arr) {
    int ROW = arr.size();
    int COLUMN = arr[0].size();
    int r = 0;
    int c = 0;
    vector<int> result;
    int level = 0;
    bool isGoingDown = true;
    while (r < ROW && r >= 0 && c >= 0 && c < COLUMN) {
        result.push_back(arr[r][c]);
        if (isGoingDown) {
            if (c == 0 || r == ROW - 1) {
                isGoingDown = !isGoingDown;
                if (r == ROW - 1) {
                    c++;
                }
                else {
                    r++;
                }
            }
            else {
                r++;
                c--;
            }
        }
        else {
            
            if (r == 0 || c == COLUMN - 1) {
                isGoingDown = !isGoingDown;
                if (c == COLUMN - 1) {
                    r++;
                }
                else {
                    c++;
                }
            }
            else {
                r--;
                c++;
            }
        }

    }
}

list<char> buildSequence(vector < vector < vector<int>>>& lcs) {
    int row = lcs.size();
    int col = lcs[0].size();

    int i = row-1;
    int j = col-1;
    list<char> result;
    while (i != 0 && j != 0) {
        vector<int> it = lcs[i][j];
        if (it[0] != -1) {
            result.push_front(char(it[0]));
        }
        i = it[2];
        j = it[3];
    }

    return result;
}

list<char> longestIncreasingSequence(string str1, string str2) {
    if (str1.size() == 0 || str2.size() == 0)
        return list<char>();

    int row = str1.size();
    int col = str2.size();
    vector < vector < vector<int>>> lcs(row+1, vector<vector<int>>(col + 1, vector<int>({0,0,0,0})));

    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            vector<int> vec;
            if (str1[i - 1] == str2[j - 1]) {
                vec = { (int)str1[i - 1], lcs[i - 1][j - 1][1] + 1, i - 1, j - 1 };
            }
            else if(lcs[i-1][j][1] > lcs[i][j-1][1]) {
                vec = { -1, lcs[i - 1][j][1], i - 1, j };
            }
            else {
                vec = { -1, lcs[i][j-1][1], i, j-1 };
            }
            lcs[i][j].assign(vec.begin(), vec.end());
            // std::copy(std::begin(vec), std::end(vec), std::begin(lcs[i][j]));
        }
    }

    return buildSequence(lcs);
}

struct trie {
    unordered_map<char, trie*> children;
    bool isEndOfTheWord;
    trie() {
        this->isEndOfTheWord = false;
    }
};

bool findString(trie* root, string input) {
    trie *tempRoot = root;
    for (int i = 0; i < input.size(); i++) {
        char ch = input[i];
        tempRoot = tempRoot->children[ch];
        if (tempRoot == nullptr)
            return false;
    }

    return tempRoot->isEndOfTheWord;
}

vector<bool>& multiStringSearch(string bigString, vector<string> smallString) {
    trie* root = new trie();

    auto temp = bigString | std::ranges::views::split(' ');
    vector<string>tokens;
    for (auto&& token : temp) {
        std::string s(token.begin(), token.end());
        tokens.push_back(s);
    }

    for (int i = 0; i < tokens.size(); i++) {
        trie *tempRoot = root;
        for (auto& it : tokens[i]) {
            if(tempRoot && !tempRoot->children.contains(it))
                tempRoot->children.insert({ it, new trie() });

            tempRoot = tempRoot->children[it];
        }
        tempRoot->isEndOfTheWord = true;
    }

    static vector<bool> result(smallString.size(), false);
    int i = 0;
    for (const auto& it : smallString) {
        result[i] = findString(root, it);

        //if (result[i] == true)
        //    cout << " true \t";
        //else
        //    cout << " false \t";
        i++;
    }

    return result;
}
/*

gogopowerrangergogopowerranger -> 30

go, powerranger

8, 22

xxyxxy

6 - 22
x-1
y-13

x-2
y-11

*/

// clementisacap

void longestStrWithoutDuplicate(string str) {
    unordered_map<char, int> visited;
    int maxLen = 0;
    int start = 0;
    string result;
    for (int i = 0; i < str.size(); i++) {
        if (!visited.contains(str[i])) {
            visited.insert({ str[i], i });
        }
        else {
            start = max(start, visited[str[i]] + 1);
            if ((i - start + 1) > maxLen) {
                result = result.substr(start, i+1);
                maxLen = i - start + 1;
            }
            visited[str[i]] = i;
        }
    }
}

bool interLeavingStrUtils(string str1, string str2, string str3, int i, int j) {
    int k = i + j;
    if (k == str3.size()) {
        return true;
    }

    if (i < str1.size() && str1[i] == str3[k]) {
        if (interLeavingStrUtils(str1, str2, str3, i + 1, j))
            return true;
    }

    if (j < str2.size() && str2[j] == str3[k]) {
        return interLeavingStrUtils(str1, str2, str3, i, j+1);
    }

    return false;
}

bool interLeavingStr(string str1, string str2, string str3) {
    return interLeavingStrUtils(str1, str2, str3, 0, 0);
}

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int getPivotNode(int arr[], int left, int right) {

    int j = 0;
    int pivot = arr[right];
    int i = left - 1;

    for (; j <= right-1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, right);
    return i + 1;
}

void quickSort(int arr[], int left, int right) {

    if (right > left)
        return;

    int pivotNodeIndex = getPivotNode(arr, left, right);

    quickSort(arr,left, pivotNodeIndex-1);
    quickSort(arr, pivotNodeIndex+1, right-1);

}
/*

2 -> 1 -> 3 -> 4
3 -> 1 -> 4
4 -> 2 

*/

int main()
{
    vector<string> smallString = { "this","yo", "is", "a", "bigger", "string", "kappa" };
    static vector<bool> result1 = multiStringSearch("this is a big string", smallString);

    for (int i = 0; i < result1.size(); i++) {
        if (result1[i] == true)
            cout << " true \t";
        else
            cout << " false \t";
    }
    //string str1 = "xkykzpw";
    //string str2 = "zxvvyzw";

    string str1 = "ezupkr";
    string str2 = "ubmrapg";

    list<char> result = longestIncreasingSequence(str1, str2);
    for (auto& it : result) {
        cout << it << " ";
    }
    cout << "\n";

    int a[] = { 1, 2, 3, 4 };
    int b[4];
    std::copy(std::begin(a), std::end(a), std::begin(b));

    vector<int> v = { -2, 2, -5, 4, 3, 1 };
    stack<int> st;
    for (auto& it : v) {
        st.push(it);
    }

    sortStack(st);
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }


    return 0;
}

    //fun();
   /* Solution obj;
    obj.longestPalindrome("babad");*/

    //list<string> words = { "act", "cat", "tca", "foo", "oof", "ofo", "oy","yo" };

    //groupAngram(words);

//    std::cout << "Hello World!\n";
//}

