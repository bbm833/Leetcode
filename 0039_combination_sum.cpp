/*
https://leetcode.com/problems/combination-sum/description/

Given an array of distinct integers candidates and a target integer target,
return a list of all unique combinations of candidates where the chosen numbers
sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two
combinations are unique if the frequency of at least one of the chosen numbers
is different.

The test cases are generated such that the number of unique combinations that
sum up to target is less than 150 combinations for the given input.



Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple
times. 7 is a candidate, and 7 = 7. These are the only two combinations. Example
2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []


Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40
*/

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates,
                                     int target_aimed) {
    std::sort(candidates.begin(), candidates.end());
    vector<vector<int>> results{};

    vector<int> current_combination;
    combinationSumRec(candidates, target_aimed, 0, current_combination,
                      results);

    return results;
  }

  void combinationSumRec(vector<int> &candidates, int target_aimed, int index,
                         vector<int> &current_combination,
                         vector<vector<int>> &results) {
    const int n = candidates.size();
    for (int i = index; i < n; ++i) {
      const int diff = target_aimed - candidates[i];
      if (diff == 0) {
        current_combination.emplace_back(candidates[i]);
        results.emplace_back(current_combination);
        current_combination.pop_back();
        return;
      } else if (diff > 0) {
        current_combination.emplace_back(candidates[i]);
        combinationSumRec(candidates, diff, i, current_combination, results);
        current_combination.pop_back();
      } else {
        return;
      }
    }
  }
};
