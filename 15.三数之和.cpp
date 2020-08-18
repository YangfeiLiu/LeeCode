/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int l = i + 1, r = nums.size() - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while(l + 1 < r && nums[l - 1] == nums[l]) l++;
                    r--;
                    while(r - 1 > l && nums[r + 1] == nums[r]) r--;
                }
                else if(sum < 0) l++;
                else r--;
            }
        }
        return ans;
    }
};
// @lc code=end

