/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return ans;
    }

    void dfs(int n, int k, int start){
        if(tmp.size() == k){
            ans.push_back(tmp);
        }
        for(int i = start; i <= n; i++){
            tmp.push_back(i);
            dfs(n, k, i + 1);
            tmp.pop_back();
        }
    }
};
// @lc code=end

