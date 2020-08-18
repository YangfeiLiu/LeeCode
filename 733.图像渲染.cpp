/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> dir{{1,0}, {-1,0}, {0,1}, {0,-1}};
        queue<pair<int, int>> qu;
        qu.push({sr, sc});
        int val = image[sr][sc];
        if(val == newColor) return image;
        while(!qu.empty()){
            pair<int, int> pos = qu.front();
            qu.pop();
            int x = pos.first, y = pos.second;
            image[x][y] = newColor;
            for(vector<int> p: dir){
                int x_ = x + p[0], y_ = y + p[1];
                if(x_ >= 0 && x_ < image.size() && y_ >= 0 && y_ < image[0].size() && image[x_][y_] == val){
                    qu.push({x_, y_});
                }
            }
        }
        return image;
    }
};
// @lc code=end



