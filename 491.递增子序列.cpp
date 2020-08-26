/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if(nums.size() < 2) return ans;
        dfs(nums, 0);
        return ans;
    }

    void dfs(vector<int>& nums, int index){
        int use[201] = {0};
        if(tmp.size() >= 2){
            ans.push_back(tmp);
        }
        for(int i = index; i < nums.size(); i++){
            if((tmp.empty() || nums[i] >= tmp[tmp.size() - 1]) 
            && use[nums[i] + 100] == 0){ //这里的去除重复的条件
                tmp.push_back(nums[i]);
                dfs(nums, i + 1);
                tmp.pop_back();
                use[nums[i] + 100] = 1;
            }
        }
    }
};
// @lc code=end

