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



/*
* 4 7 3 8 2
*/



/*
2 4 8 10

6

0 1 2 3
1 2 4 5
3

prefix
0 1 3 7 12

3 4 9

3 * n-i = 3 * 3 = 9
min diff = 1
sum += num[i];
remamingSum = 4 * 2 = 8
3 + 8 = 1
min = 1

3 4 5 6
6 10 10 13 14 15 17 19


10

3 4 5 8 10

3 0 6 1 5

n = 5
papers[]
0 1 2 3 4 5
1 1 0 1 0 2

1 2 3 3 5

9
1 2 4 8 9 10

3 7 8 9



*/

int twoSumLessThenK(vector<int> vec, int target) {

    std::sort(vec.begin(), vec.end());

    int low = 0;
    int high = vec.size() - 1;
    int min = INT_MIN;
    while (low < high) {
        if (vec[low] + vec[high] > target)
            high--;
        else {
            if (min < vec[low] + vec[high])
                min = vec[low] + vec[high];
            low++;
        }
    }
    return min;
}


int hIndex(vector<int> citations)
{
    int n = citations.size();

    vector<int> papers(n + 1);

    for (int c : citations) {
        papers[min(n, c)] += 1;
    }

    int k = n;
    int s = papers[n];

    while (k > s) {
        k--;
        s += papers[k];
    }

    return k;
}

int apartmenthunting(vector<map<int, int>> blocks, vector<int> req) {

    int blockIndex = -1;
    int best_facility = 0;
    int result = INT_MAX;
    for (int x = 0; x < blocks.size(); x++) {
        for (int y = 0; y < blocks.size(); y++) {
            if (x == y)
                continue;
            int max_facility = 0;
            for (auto& re : req) {
                if (blocks[x].contains(re)) {
                    max_facility++;
                }
            }
            if (best_facility < max_facility) {
                blockIndex = y;
                best_facility = max_facility;
            }
        }
        result = min(result, abs(x - blockIndex));
    }
    return result;
}

/*
1 -> 2 5
2 -> 2 4 5
4 -> 2 5
5 -> 1

0 1 2 3 4 5 6
4 3 31 1 9 5 6

start = 0
end = 7
mid = 3

start = 0
end = 3
mid = 1

start = 0  -> start = 1
end = 1    -> end   = 3

start = 0, mid = 1, end = 3

left  = 0
right = middle = 1
end   = 3

0 1 2 3 4 5 6
2 3 3 1 9 5 6

left = 1
sortedArray = 2 3 3

0 1 2 3 4 5 6
2 3 3 1 9 5 6

start = 3
end = 7
middle = 5

left = 3
right = middle = 5
end = 7

0 1 2 3 4 5 6
2 3 3 1 9 5 6

sortedArray = 1
left=4
incersion=1
right = 6
incersion=2






// 0 -> 1 -> 2 -> 3 -> 3 -> 2 -> 1 -> 0

*/


void maxLen(string str) {

    stack<int> st;
    int maxLength = 0;
    st.push(-1);
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            st.push(i);
        }
        else {
            //maxLength = (st.empty() == true ? 0 : st.top())
            if (!st.empty()) {
                int length = st.top() - i + 1;
                st.pop();
                maxLength = max(maxLength, length);
            }
        }
    }

}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int i = 0;
    int j = 0;
    int k = 0;
    int totalSize = nums1.size() + nums2.size();
    vector<int> nums(nums1.size() + nums2.size());
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            nums[k] = nums[i];
            i++;
        }
        else {
            nums[k] = nums[j];
            j++;
        }
        k++;
    }
    while (i < nums1.size())
        nums[k++] = nums1[i++];
    while (j < nums2.size())
        nums[k++] = nums2[j++];

    double median = 0.0;
    if (nums.size() == 1)
        return nums[0] / 2;
    if (nums.size() == 2) {
        median = (double)(nums[0] + nums[1]) / 2;
    }
    int mid = totalSize / 2;

    if (totalSize % 2 == 0) {
        median = (double)(nums[mid] + nums[mid - 1]) / 2;
    }
    else
        median = (double)nums[mid];

    return median;
}

vector<int> nextGreater(int arr[], int n) {
    stack<int> st;
    vector<int> result(n, -1);
    for (int i = 0; i < 2 * n; i++) {
        int index = i % n;
        while (!st.empty() && arr[i] > arr[st.top()]) {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}

struct trieNode {
    unordered_map<char, trieNode*> childrens;
};
class suffixTrieConstruction {
private:
    trieNode* root;
    void insertUtils(string str, int i, trieNode& tempNode) {
        if (i == str.length()) {
            tempNode.childrens.insert({ '*', nullptr });
            return;
        }
        for (int index = i; index < str.length(); index++) {
            if (!tempNode.childrens.contains(str[index])) {
                tempNode.childrens.insert({ str[index], new trieNode() });
            }
            insertUtils(str, index + 1, *tempNode.childrens[str[index]]);        
        }
    }
    void populateSuffixTrieFromUtils(trieNode* temp) {
        if (temp == nullptr)
            return;
        while (temp != nullptr) {
            unordered_map<char, trieNode*> tempChilds = temp->childrens;
            for (auto& entry : tempChilds) {
                cout << " { " + to_string(entry.first) + " : ";
                populateSuffixTrieFromUtils(entry.second);
            }
            if (temp->childrens.contains('*')) {
                cout << "{ " + to_string('*') + " } ";
            }
        }
    }
public:

    suffixTrieConstruction() {
        root = new trieNode();
    }

    void insert(string str) {
        insertUtils(str, 0, *root);
    }

    void populateSuffixTrieFrom() {
        populateSuffixTrieFromUtils(root);
    }
};

int getMaxAreaOfHistogram(int heights[], int size) {

    stack<int> st;
    int maxArea = 0;
    for (int i = 0; i < size; i++) {

        while (!st.empty() && heights[i] < heights[st.top()]) {
            int h = heights[st.top()];
            st.pop();
            int l = st.empty() ? -1 : (i - st.top() - 1);
            maxArea = max(maxArea, h * l);
        }
        st.push(i);
    }
    return maxArea;
}

string longestStringWithoutDuplication(string input) {

    unordered_map<char, int> indexMap;
    int previousIndex = 0;
    int maxLength = 0;
    string output = "";
    for (int i = 0; i < input.length(); i++) {
        if (!indexMap.contains(input[i])) {
            indexMap.insert({ input[i], i });
        }
        else {
            if (maxLength < i - previousIndex) {
                maxLength = i - previousIndex;
                output = input.substr(previousIndex, i - previousIndex);
            }  
            if (indexMap[input[i]] > previousIndex)
                previousIndex = indexMap[input[i]] + 1;
            indexMap[input[i]] = i;
        }
    }
    return output;
}

/*

-5 -3 0 3 4 5 9

 

*/

int indexEqualValue(int arr[], int n) {

    int resultIndex = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0 && arr[i] <= n - 1 && arr[i] == i) {
            resultIndex = i;
            break;
        }
    }
    return resultIndex;
}

//
//

int houseRobber(int money[], int i, int sum, unordered_map<int, int>& dp, int& maxSum, int n, bool isTrue) {

    if (i == n) {
        return sum;
    }

    if (dp.contains(i + 1))
        return dp[i + 1];

    int sum1 = 0;
    int sum2 = 0;

    if (isTrue) {
        houseRobber(money, i + 1, sum1, dp, maxSum, n, !isTrue);

    }
    else {
        houseRobber(money, i + 1, sum2 + money[i], dp, maxSum, n, !isTrue);
    }
    dp.insert({ i + 1, max(sum1, sum2) });
}

bool wordBreakUtils(string s, int index, unordered_set<string>& seen) {

    if (index == s.length())
        return true;

    for (int i = index; i < s.size(); i++) {
        string sustr = s.substr(index, i - index + 1);
        if (seen.contains(sustr) && wordBreakUtils(s, i + 1, seen)) {
            return true;
        }
    }

    // Replace this placeholder return statement with your code
    return false;
}
bool wordBreak(string s, vector<string>& wordDict) {

    unordered_set<string> seen;
    for (auto& word : wordDict)
        seen.insert(word);


    return wordBreakUtils(s, 0, seen);
}

vector<string> wordBreakDP(string s, vector<string>& wordDict) {
    int n = s.length();
    vector<vector<string>> dp(n + 1, vector<string>({ "" }));
    set<string> disc(wordDict.begin(), wordDict.end());

    for (int i = 1; i <= n; i++) {
        vector<string> temp;
        for (int j = 0; j < i; j++) {
            string value = s.substr(j, i - j);
            if (disc.contains(s.substr(j, i - j))) {
                string subStr = s.substr(j, i - j);
                for (auto& it : dp[j]) {
                    if (it.empty()) {
                        temp.push_back(subStr);
                    }
                    else {
                        temp.push_back(it + subStr);
                    }
                }
            }
        }
        dp[i] = temp;
    }

    return dp[n];
}


void print_TicTacToe(vector<vector<char>>& matrix) {
    for (int j = 0; j < matrix[0].size(); j++) {
        cout << "--------";
    }
    for (int i = 0; i < matrix.size(); i++) {
        cout << "\n|  ";
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << "\t|  ";   

        }
        cout << "\n|";
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << "\t|";
        }
        cout << "\n";
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << "--------";
        }
    }
}

int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    queue<int> q;
    q.push(1);
    vector<bool> seen(1 + n * n);
    vector<int> arr(1 + n * n);

    // Map 2D -> 1D according to the Boustrophedon  
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int index = (n - 1 - i) * n + ((n - i) % 2 == 0 ? n - j : j + 1);
            arr[(n - 1 - i) * n + ((n - i) % 2 == 0 ? n - j : j + 1)] = board[i][j];
        }

    int step = 1;
    while (!q.empty()) {
        for (int sz = q.size(); sz > 0; --sz) {
            int curr = q.front();
            q.pop();
            for (int next = curr + 1; next <= min(curr + 6, n * n); ++next) {
                int dest = arr[next] > 0 ? arr[next] : next;
                if (dest == n * n) return step;
                if (seen[dest]) continue;
                q.push(dest);
                seen[dest] = true;
            }
        }
        ++step;
    }
    return -1;
}



int main() {
    vector<vector<int>> board({
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1 },
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1}});

    snakesAndLadders(board);

    vector<vector<char>> matrix(3, vector<char>(3, 'O'));
    matrix[0][0] = 'X';
    matrix[1][1] = 'X';
    matrix[2][2] = 'X';
    print_TicTacToe(matrix);
   // vector<string> vec({ "leet", "code" });
    //wordBreak("leetCode", vec);
    //string s = "abcd";
    //int i = 0;
    //int x = 1;
    //cout << s.substr(i, x-i+1);

   // cout << longestStringWithoutDuplication("clementisacap");
    //suffixTrieConstruction obj;
   /* obj.insert("babc");
    obj.populateSuffixTrieFrom();*/
    //vector<int>num1({ 1,3 });
    //vector<int>num2({ 2 });
    //findMedianSortedArrays(num1, num2);
    //vector<int> vec{ 3, 0, 6, 1, 5 };
    //cout << hIndex(vec);
    return 0;
}

