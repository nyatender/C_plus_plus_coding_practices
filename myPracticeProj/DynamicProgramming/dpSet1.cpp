

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <unordered_set>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


void MatrixChainManipulation() {

}

// IP -> 3 4 -1 0 6 2 3
// OP -> -1, 0, 2, 3
// IP -> 2 5 1 8 3
// OP -> 2, 5, 8
void longestIncresingSubSequence(vector<int> vec) {

	vector<int> dp(vec.size(), 1);
	vector<int> sequence(vec.size(), -1);

	for (int i = 1; i < vec.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (vec[j] < vec[i]) {
				if (dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
					sequence[i] = j;
				}
			}
		}
	}

	int max = 1;
	int maxIndex = 0;
	for (int i = 0; i < dp.size();i++) {
		if (dp[i] > max) {
			max = dp[i];
			maxIndex = i;
		}
	}

	cout << " Max count is " << max;
	cout << " \nsequence is below \n";
	int tempIndex = 0;
	if (max > 1) {
		for (int k = maxIndex; k != -1;) {
			cout << " -> " << k;
			if (sequence[k] == -1) {
				break;
			}
			k = sequence[k];
		}
	}
}

int getSum(vector<int>& treeFreq, int i, int j) {
	int sum = 0;
	for (int it = i; it <= j; it++)
		sum += treeFreq[it];

	return sum;
}
int optimalBinarySearchTree(vector<int> treeFreq) {

	int n = treeFreq.size();
	vector<vector<int>> dp(n, vector<int>(n, 0));

	for (int i = 0; i < n;i++) {
		dp[i][i] = treeFreq[i];
	}

	for (int l = 2; l <= treeFreq.size(); l++) {
		for (int i = 0; i < treeFreq.size() - l + 1; i++) {
			int j = i + l - 1;
			int sum = getSum(treeFreq, i, j); // here we including root node also in calculation
			int minVal = INT_MAX;					  // so next step it would not needed to include in calculation
			for (int root = i; root <= j; root++) {
				minVal = min(minVal, sum + (root - 1 < i ? 0 : dp[i][root - 1]) +
					     + (root + 1 > j ? 0 : dp[root+1][j]));
				
			}
			dp[i][j] = minVal;
		}
	}
	return dp[0][n - 1];
}

int eggDropping(int floors, int n) {

	vector<vector<int>> dp(n+1, vector<int>(floors+1, 0));

	for (int i = 0; i <= floors; i++) {
		dp[1][i] = i;
	}

	for (int i = 2; i <= n; i++) {

		for (int l = 1; l <= floors; l++) {
			
			int minVal = INT_MAX;
			for (int j = 1; j <= l; j++) {
				minVal = 1 + min(minVal, max(dp[i][l-j], dp[i - 1][j - 1]));
				dp[i][l] = minVal;
			}
		}
	}
	return dp[n][floors];
}

void cuttingRoad(vector<int> price, int totalLength) {

	vector<int> dp(totalLength + 1, INT_MIN);
	dp[0] = 0;

	for (int i = 1; i <= totalLength; i++) {
		for (int j = 1; j <= price.size(); j++) {
			if (j < i) {
				dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
			}
		}
	}


}

void swap(vector<int>& input, int i, int j) {
	int temp = input[i];
	input[i] = input[j];
	input[j] = temp;
}

// -1 1 2 -3 5 8
// 1 -1 2 -3 5 8
int AlternatePositiveAndNegative(vector<int> input) {

	int i = 0;
	int j = 1;
	int k = 2;
	int n = input.size();

	while (k < n) {
		if (input[i] < 0 && i % 2 == 0) {
			if (input[k] >= 0) {
				swap(input, i, k);
				i++;
				k++;
			}
			else {
				k++;
			}
		}
		else if(input[i] > 0 && i%2 != 0) {
			if (input[k] < 0) {
				swap(input, i, k);
				i++;
				k++;
			}
			else {
				k++;
			}
		}
		else {
			k++;
			i++;		
		}
	}

}

int main() {
	int x = 3;
	cout << pow(x, 2);

	vector<int> vec1({3,4,-1,0,6,2,3});
	vector<int> vec2({2,5,1,8,3});

	vector < vector<int>> input({ vec1,vec2 });
	for (auto& it : input) {
		longestIncresingSubSequence(it);
			cout << "\n";
	}

	return 0;
}