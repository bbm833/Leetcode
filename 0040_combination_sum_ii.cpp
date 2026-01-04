/*
https://leetcode.com/problems/combination-sum-ii/description/

Given a collection of candidate numbers (candidates) and a target number
(target), find all unique combinations in candidates where the candidate numbers
sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.



Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]


Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30

*/

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates,
                                      int target_aimed) {
    std::sort(candidates.begin(), candidates.end());
    vector<vector<int>> results{};

    vector<int> current_combination;
    combinationSumRec(candidates, target_aimed, 0, 0, current_combination,
                      results);

    return results;
  }

  bool combinationSumRec(vector<int> &candidates, int target_aimed, int index,
                         int level, vector<int> &current_combination,
                         vector<vector<int>> &results) {
    const int n = candidates.size();
    for (int i = index; i < n; ++i) {
      const int diff = target_aimed - candidates[i];
      if (diff == 0) {
        current_combination.emplace_back(candidates[i]);
        results.emplace_back(current_combination);
        current_combination.pop_back();
        return true;
      } else if (diff > 0) {
        current_combination.emplace_back(candidates[i]);
        bool found = combinationSumRec(candidates, diff, i + 1, level + 1,
                                       current_combination, results);
        current_combination.pop_back();

        while (i + 1 < n && candidates[i] == candidates[i + 1]) {
          ++i;
        }
      } else {
        return false;
      }
    }
    return false;
  }
};
