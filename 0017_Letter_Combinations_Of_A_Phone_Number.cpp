/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

1 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].

*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations{};
        std::map<char, std::vector<char>> digits_map{};
        
        char ch_current = 'a';
        for(char ch = '2' ; ch <= '9'; ++ch)
        {
            std::vector<char> letters{ch_current,  static_cast<char>(ch_current+1),  static_cast<char>(ch_current+2)};
            if(ch == '7' || ch == '9')
            {
                letters.emplace_back(ch_current+3);
                ch_current++;
            }

            digits_map[ch] = letters;
            ch_current +=  3;
        }

        const auto& letters = digits_map[digits.at(0)];
        for(auto ch : letters)
        {
            combinations.emplace_back(std::string{ch});
        }

        for(int i= 1; i< digits.size(); ++i)
        {
            const auto& letters = digits_map[digits.at(i)];
            vector<string> new_combinations{};
            for(auto ch : letters)
            {
                for(int j=0; j<combinations.size(); ++j)
                {
                    std::string str = combinations[j];
                    str.push_back(ch);
                    new_combinations.emplace_back(str);
                }
            }
            combinations = new_combinations;
        }

        return combinations;
    }
};
