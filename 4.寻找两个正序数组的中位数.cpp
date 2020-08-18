/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int left = (m+n+1)/2, right = (m+n+2)/2;
        return 0.5 * (getKth(nums1, 0, m - 1, nums2, 0, n - 1, left)
        + (getKth(nums1, 0, m - 1, nums2, 0, n - 1, right)));
    }
    // 二分法，判断前 k/2个数是否可能是中位数，如果不是，就去除
    double getKth(vector<int>& num1, int b1, int e1, vector<int>& num2, int b2, int e2, int k){
        int len1 = e1 - b1 + 1, len2 = e2 - b2 + 1;
        if(len1 > len2) return getKth(num2, b2, e2, num1, b1, e1, k);
        if(len1 == 0) return num2[b2 + k - 1]; // num1为空
        if(k == 1) return min(num1[b1], num2[b2]);
        int a = b1 + min(len1, k / 2) - 1;
        int b = b2 + min(len2, k / 2) - 1;
        if(num1[a] < num2[b]){
            return getKth(num1, a + 1, e1, num2, b2, e2, k - (a - b1 + 1));
        }
        else return getKth(num1, b1, e1, num2, b + 1, e2, k - (b - b2 + 1));
    }
};
// @lc code=end

