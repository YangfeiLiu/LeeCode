/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    vector<vector<bool>> vis;
    int cnt = 0;
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = 0;
        if(row) col = grid[0].size();
        vis = vector<vector<bool>>(row, vector<bool>(col, false));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(grid, i, j, row, col);
                    cnt++;
                }
            }
        }
        return cnt;
    }

    void dfs(vector<vector<char>>& grid, int x, int y, int row, int col){
        if(x < 0 || x >= row || y < 0 || y >= col || vis[x][y] || grid[x][y] == '0') 
            return;
        vis[x][y] = true;
        dfs(grid, x-1, y, row, col);
        dfs(grid, x+1, y, row, col);
        dfs(grid, x, y-1, row, col);
        dfs(grid, x, y+1, row, col);
    }
};
// @lc code=end

