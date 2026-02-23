/*
https://leetcode.com/problems/spiral-matrix-ii/description/

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:
Input: n = 1
Output: [[1]]
 

Constraints:
1 <= n <= 20
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));

        int num{1};
        for(int layer = 0; layer < n; ++layer)
        {
            // left
            for(int i=layer; i<n-layer-1; ++i)
            {
                result[layer][i] = num;                
                ++num;
            }

            // bottom
            for(int i=layer; i<n-layer-1; ++i)
            {
                result[i][n-layer-1] = num;

                ++num;
            }

            // right
            for(int i=n-layer-1; i>layer; --i)
            {
                result[n-layer-1][i] = num;    
                ++num;
            }

            // top
            for(int i=n-layer-1; i>layer; --i)
            {
                result[i][layer] = num;                
                ++num;
            }
        }

        if(n%2 != 0)
        {
            result[n/2][n/2] = num;   
        }

        return result;
    }
};
