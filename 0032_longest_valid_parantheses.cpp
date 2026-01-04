/*
https://leetcode.com/problems/longest-valid-parentheses/description/

Given a string containing just the characters '(' and ')', return the length of
the longest valid (well-formed) parentheses substring.

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0


Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.

*/

class Solution {
public:
  int longestValidParentheses(string s) {

    int left{0};
    int right{0};
    int max_pair{0};

    for (auto ch : s) {
      if (ch == '(')
        ++left;
      else
        ++right;

      if (left == right) {
        max_pair = std::max(max_pair, right);
      } else if (right > left) {
        left = right = 0;
      }
    }

    const int n = s.size();
    left = right = 0;
    for (int i = n - 1; i > 0; --i) {
      if (s[i] == '(')
        ++left;
      if (s[i] == ')')
        ++right;
      if (left == right) {
        max_pair = std::max(max_pair, right);
      }
      if (left > right) {
        left = right = 0;
      }
    }

    return max_pair * 2;
  }
};
