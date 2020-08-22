/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> dir{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row = board.size();
        int col = 0;
        if(row) col = board[0].size();
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        dfs(board, click[0], click[1], row, col);
        return board;
    }

    void dfs(vector<vector<char>>& board, int x, int y, int row, int col){
        int cnt = 0;
        //先判断该位置周围有几个雷
        for(auto d: dir){
            int x_ = x + d[0];
            int y_ = y + d[1];
            if(x_ >= 0 && x_ < row && y_ >= 0 && y_ < col){
                if(board[x_][y_] == 'M')
                    cnt++;
            }
        }
        //如果有雷，修改成雷的个数，并返回
        if(cnt > 0) {
            board[x][y] = cnt + '0';
            return;
        }
        //如果没有雷，看看周围的位置
        board[x][y] = 'B';
        for(auto d: dir){
            int x_ = x + d[0];
            int y_ = y + d[1];
            if(x_ >= 0 && x_ < row && y_ >= 0 && y_ < col && board[x_][y_] == 'E'){
                dfs(board, x_, y_, row, col);
            }
        }
    }
};
// @lc code=end

