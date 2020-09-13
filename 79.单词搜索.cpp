/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    vector<vector<char>> arr;
    string str;
    int m, n;
    vector<vector<bool>> vis;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = 0;
        arr = board, str = word;
        if(m) n = board[0].size();
        vis = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dfs(i, j, 0)) return true;
            }
        }
        return false;
    }

    bool dfs(int i, int j, int k){
        if(str[k] == '\0') return true;
        if(i < 0 || i >= m || j < 0 || j >= n || vis[i][j]) return false;
        vis[i][j] = true;
        if(arr[i][j] == str[k]){
            if((dfs(i-1, j, k+1) || dfs(i+1, j, k+1) || dfs(i, j-1, k+1) || dfs(i, j+1, k+1)))
                return true;
        }
        vis[i][j] = false;
        return false;
    }
};
// @lc code=end

