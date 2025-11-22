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

vector<int> getUnExpiredTokens(int time_to_live, vector<string> queries) {

	map<string, int> tokensMap;
	vector<int> result;
	for (auto& query : queries) {
		auto temp = query | std::ranges::views::split(' ');
		vector<string>tokens;
		for (auto&& token : temp) {
			std::string s(token.begin(), token.end());
			tokens.push_back(s);
		}
		if (query.starts_with("generate")) {
			tokensMap.insert({ tokens[1], std::stoi(tokens[2]) + time_to_live });
		}
		else if (query.starts_with("renew")) {
			if (tokensMap[tokens[1]] > std::stoi(tokens[2])) {
				tokensMap[tokens[1]] = std::stoi(tokens[2]) + time_to_live;
			}
		}
		else {
			int count = 0;
			for (auto& token : tokensMap) {
				if (token.second > std::stoi(tokens[1])) {
					count++;
				}
			}
			result.push_back(count);
		}
	}

	return result;

}

//Optimized all test cases passed
//vector<int> getUnExpiredTokens(int time_to_live, vector<string> queries) {
//	unordered_map<string, int> tokensMap;
//	priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> min_heap;
//	vector<int> result;
//	int time, expiry;
//	string command, token;
//
//	for (const string& query : queries) {
//		istringstream ss(query);
//		ss >> command;
//		if (command == "generate") {
//			ss >> token >> time;
//			expiry = time + time_to_live;
//			tokensMap[token] = expiry;
//			min_heap.emplace(expiry, token);
//		}
//		else if (command == "renew") {
//			ss >> token >> time;
//			if (tokensMap.count(token) && tokensMap[token] > time) {
//				expiry = time + time_to_live;
//				tokensMap[token] = expiry;
//				min_heap.emplace(expiry, token);
//			}
//		}
//		else { // count
//			ss >> time;
//			while (!min_heap.empty() && min_heap.top().first <= time) {
//				auto [exp, tk] = min_heap.top();
//				min_heap.pop();
//				if (tokensMap[tk] == exp) tokensMap.erase(tk);
//			}
//			result.push_back(tokensMap.size());
//		}
//	}
//	return result;
//}

int main_microsoft2() {

	// Test case 1
	//vector<string> test = {
	//	"generate aaa 1",
	//	"renew aaa 2",
	//	"count 6",
	//	"generate bbb 7",
	//	"renew aaa 8",
	//	"renew bbb 10",
	//	"count 15"
	//};
	//int time_to_live = 5;

	//Test case 2
	vector<string> test = {
		"generate token1 3",
		"count 4",
		"generate token2 6",
		"count 7",
		"generate token3 11",
		"count 41",
	};
	int time_to_live = 35;

	vector<int> result = getUnExpiredTokens(time_to_live, test);
	for (auto& it : result) {
		cout << it << " ";
	}

	return 0;
}