/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0) return ans;
        dfs(nums, 0);
        return ans;
    }

    void dfs(vector<int>& nums, int index){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = index; i < nums.size(); i++){
            swap(nums[i], nums[index]);
            dfs(nums, index+1);
            swap(nums[i], nums[index]);
        }
    }
};
// @lc code=end

