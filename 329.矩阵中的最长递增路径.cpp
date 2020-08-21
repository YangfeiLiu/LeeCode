/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
class Solution {
public:
    int longest = 0;
    vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0) return 0;
        int col = matrix[0].size();
        vector<vector<int>> visit(row, vector<int>(col, 0));//visit[i][j]里面存放的是到i,j位置的最长递增路径
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(visit[i][j] == 0)//没有访问过
                    dfs(row, col, i, j, matrix, visit);
            }
        }
        return longest;
    }

    int dfs(int row, int col, int x, int y, vector<vector<int>>& arr, vector<vector<int>>& visit){
        if(visit[x][y] != 0){
            return visit[x][y];
        }
        visit[x][y] = 1;//至少长度是1
        for(auto d: dir){
            int x_ = x + d[0];
            int y_ = y + d[1];
            if(x_ >= 0 && x_ < row && y_ >= 0 && y_ < col && arr[x_][y_] < arr[x][y])
                visit[x][y] = max(visit[x][y], dfs(row, col, x_, y_, arr, visit) + 1);
        }
        longest = max(visit[x][y], longest);
        return visit[x][y];
    }
};
// @lc code=end

