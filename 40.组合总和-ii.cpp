/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size() < 0) return ans;
        sort(candidates.begin(), candidates.end()); //因为每个数字只能出现一次，所以要先排序
        dfs(candidates, 0, target);
        return ans;
    }

    void dfs(vector<int>& vec, int index, int target){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int i = index; i < vec.size() && target >= 0; i++){
            if(i > index && vec[i] == vec[i-1]) continue; //这里 i>index这个条件
            temp.push_back(vec[i]);
            dfs(vec, i+1, target - vec[i]);
            temp.pop_back();
        }
    }
};
// @lc code=end

