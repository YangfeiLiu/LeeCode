/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int c = 0;
        int row = grid.size(), col = 0;
        if(row) col = grid[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    if(i == 0) c++;
                    if(i == row-1) c++;
                    if(j == 0) c++;
                    if(j == col-1) c++;
                    if(i > 0 && grid[i-1][j] == 0) c++;
                    if(i < row-1 && grid[i+1][j] == 0) c++;
                    if(j > 0 && grid[i][j-1] == 0) c++;
                    if(j < col-1 && grid[i][j+1] == 0) c++;
                }
            }
        }
        return c;
    }
};
// @lc code=end

