
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    bool canPartitionUtis(vector<int>& nums, int i, int sum, int totalSum) {
        if (i >= nums.size())
            return false;

        if (sum + nums[i] == totalSum)
            return true;

        if (!canPartitionUtis(nums, i + 1, sum + nums[i], totalSum))
            return canPartitionUtis(nums, i + 1, sum, totalSum);

        return false;
    }

    bool canPartition(vector<int>& nums) {

        // int row = nums
        // vector<vector<bool> dp(nums) 
        int sum = 0;
        for (auto& item : nums)
            sum += item;

        if (sum % 2 != 0)
            return false;

        return canPartitionUtis(nums, 0, 0, sum / 2);

    }
};

void countLeftAndRightRec(const string& input, unordered_map<char, int>& countFrequency,
                        int i, int j, unordered_set<string>& result) {
    if (countFrequency.size() != 5)
        return;
    else {
        string sr = std::to_string(i) + "-" + std::to_string(j);
        if(result.contains(sr))
            return;
        result.insert(sr);
        
        countFrequency[input[i]]--;
        if (countFrequency[input[i]] == 0)
            countFrequency.erase(input[i]);
        countLeftAndRightRec(input, countFrequency, i + 1, j, result);
        if(!countFrequency.contains(input[i]))
            countFrequency.insert({ input[i], 0 });
        countFrequency[input[i]]++;

        countFrequency[input[j]]--;
        if (countFrequency[input[j]] == 0)
            countFrequency.erase(input[j]);
        countLeftAndRightRec(input, countFrequency, i, j-1, result);
        if (!countFrequency.contains(input[j]))
            countFrequency.insert({ input[j], 0 });
        countFrequency[input[j]]++;
    }
}

int getSubString(string input) {
    unordered_map<char, int> countFrequency;
    unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
    unordered_set<string> result;
    int k = 0;
    int previous_vowels = 0;
    int count = 0;
    // aeioaexaaeuiou -> 4
    // aaeiouxa -> 2

    for (int i = 0; i < input.size(); i++) {
        if (vowels.contains(input[i])) {
            if (!countFrequency.contains(input[i]))
                countFrequency.insert({ input[i], 0 });
            countFrequency[input[i]]++;
            if (countFrequency.size() == vowels.size()) {
                int k = previous_vowels;
                countLeftAndRightRec(input, countFrequency, k, i, result);
            }
        }
        else {
            previous_vowels = i + 1;
            countFrequency.clear();
        }

    }
    return result.size();

}

int main() {
   vector<string> input = { "aeioaexaaeuiou", "aaeiouxa", "aaaeiouuu"};
    for (int i = 0; i < input.size(); i++) {
       cout << getSubString(input[i]) << " ";
    }
    
    vector<int> vec = { 3,3,3,4,5 };
    Solution obj;
    obj.canPartition(vec) == 0 ? (cout << "false") : (cout << "true");
}
