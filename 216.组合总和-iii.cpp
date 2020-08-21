/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k == 0 || n <= 0) return ans;
        dfs(k, n, 1);
        return ans;
    }

    void dfs(int k, int n, int val){
        if(n == 0 && k == 0){
            ans.push_back(temp);
            return;
        }
        if(n < 0 || k < 0) return;
        for(int i = val; i <= 9; i++){
            temp.push_back(i);
            dfs(k-1, n - i, i+1);//这里要添加一个val参数，
            //同时val更新为i+1，是因为数字无重复
            temp.pop_back();
        }
    }
};
// @lc code=end

