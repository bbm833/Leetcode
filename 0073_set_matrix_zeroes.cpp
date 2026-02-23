/*
https://leetcode.com/problems/set-matrix-zeroes/

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.


Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        set<int> rows;
        set<int> columns;

        const int m = matrix.size();
        const int n = matrix[0].size();

        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n;++j)
            {
                if(matrix[i][j] == 0)
                {
                    rows.emplace(i);
                    columns.emplace(j);
                }
            }
        }

        for(const auto& row : rows)
        {
            for(int i=0; i<n;++i)
            {              
                matrix[row][i] = 0;
            }
        }

        for(const auto& column : columns)
        {
            for(int i=0; i<m;++i)
            {
                matrix[i][column] = 0;

            }
        }
    }
};
