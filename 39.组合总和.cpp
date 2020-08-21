/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size() == 0) return ans;
        dfs(candidates, 0, target);
        return ans;
    }

    void dfs(vector<int>& vec, int index, int target){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0) return;
        for(int i = index; i < vec.size(); i++){
            temp.push_back(vec[i]);
            dfs(vec, i, target - vec[i]); //这里从i开始是因为每个数字可以无限取
            temp.pop_back();
        }
    }
};
// @lc code=end

