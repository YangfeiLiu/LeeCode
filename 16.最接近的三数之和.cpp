/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        for(int i = 0; i < len - 2; i++){
            int temp = target - nums[i];
            int l = i + 1, r = len - 1;
            while(l < r){
                int sum = nums[l] + nums[r];
                if(abs(sum - temp) < abs(diff)){ // 注意处理这里
                    diff = temp - sum;
                }
                if(sum == temp) return target;
                if(sum > temp) {
                    r--;
                }
                if(sum < temp) {
                    l++;
                }
            }
        }
        return target - diff;
    }
};
// @lc code=end

