/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int len = A.size();
        if(len == 0) return A;
        vector<int> ans(len, 0);
        int i = 0, j = len - 1;
        int k = j;
        while(i <= j){//这里算上等于，考虑偶数情况
            if(A[i] + A[j] < 0){//说明最小的很小
                ans[k--] = A[i] * A[i];
                i++;
            } 
            else{
                ans[k--] = A[j] * A[j];
                j--;
            }
        }
        return ans;
    }
};
// @lc code=end

