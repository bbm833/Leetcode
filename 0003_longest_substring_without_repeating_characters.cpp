/*
Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

#include <algorithm>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {

        int i{0};
        std::unordered_map<char, int> char_map{};
        int start{0};
        int max_size{0};
        for(i=0; i<s.size();++i)
        {
            const char ch{s.at(i)};
            auto it = char_map.find(ch);
            if( it != char_map.end())
            {
                if(it->second >= start)
                {
                    max_size = std::max(max_size, i - start);
                    start = it->second + 1;
                }
            }
            char_map[ch] = i;
        }

        max_size = std::max(max_size, i - start);

        return max_size;
    }
};
