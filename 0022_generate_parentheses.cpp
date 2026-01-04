/*
https://leetcode.com/problems/generate-parentheses/description/

Given n pairs of parentheses, write a function to generate all combinations of
well-formed parentheses


Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]


Constraints:

1 <= n <= 8

*/

class Solution {
public:
  vector<string> generateParenthesis(int n) {

    vector<string> results{};

    generate(n, std::vector<std::string>{"("}, results);

    return results;
  }

  void generate(int n, const vector<string> &sub_str_list,
                vector<string> &results) {

    vector<string> new_sub_str_list{};
    for (const auto &str : sub_str_list) {
      const int count_open = std::count(str.begin(), str.end(), '(');
      const int count_close = std::count(str.begin(), str.end(), ')');
      if (count_open == n) {
        std::string str_close{};
        for (int i = count_close; i < n; ++i) {
          str_close += ")";
        }
        results.emplace_back(str + str_close);
      } else {
        new_sub_str_list.emplace_back(str + "(");
        if (count_open > count_close) {
          new_sub_str_list.emplace_back(str + ")");
        }
      }
    }

    if (!sub_str_list.empty()) {
      generate(n, new_sub_str_list, results);
    }
  }
};
