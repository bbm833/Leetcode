/*
https://leetcode.com/problems/valid-parentheses/

Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

*/
class Solution {
public:
  bool isValid(string s) {
    std::stack<char> ch_stack{};

    for (auto ch : s) {
      if (ch == '(' || ch == '{' || ch == '[') {
        ch_stack.push(ch);
      } else {
        if (ch_stack.empty()) {
          return false;
        }
        const char ch_top = ch_stack.top();
        if (ch == ')' && ch_top != '(')
          return false;
        if (ch == '}' && ch_top != '{')
          return false;
        if (ch == ']' && ch_top != '[')
          return false;

        ch_stack.pop();
      }
    }

    return ch_stack.empty();
  }
};
