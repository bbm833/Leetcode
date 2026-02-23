/*
https://leetcode.com/problems/rotate-image/description/

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000

*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        const int n = matrix.size();

        // Transpose
        for(int i=0; i<n; ++i)
        {
            for(int j=i+1; j<n;++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse
         for(int i=0; i<n; ++i)
         {
            std::reverse(matrix[i].begin(), matrix[i].end());
         }
    }
};
