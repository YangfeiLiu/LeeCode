/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() == 0) return ans;
        dfs(nums, 0);
        return ans;
    }

    bool Isswap(vector<int>& nums, int l, int r){
        for(int i = l; i < r; i++){
            if(nums[i] == nums[r]) return false;
        }
        return true;
    }

    void dfs(vector<int>& nums, int index){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = index; i < nums.size(); i++){
            // if(!Isswap(nums, index, i)) continue;
            if(i == index || nums[i] != nums[index]){
                swap(nums[i], nums[index]);
                dfs(nums, index+1);
                swap(nums[i], nums[index]);
            }
        }
    }
    
   /*
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> visit;//用来表示是否访问过
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() == 0) return ans;
        sort(nums.begin(), nums.end());
        visit = vector<bool>(nums.size(), false);
        dfs(nums);
        return ans;
    }

    void dfs(vector<int>& nums){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!visit[i]){
                if(i > 0 && nums[i] == nums[i-1] && visit[i-1]) continue;//去重
                temp.push_back(nums[i]);
                visit[i] = true;
                dfs(nums);
                visit[i] = false;
                temp.pop_back();
            }
        }
    }
    */
};
// @lc code=end

