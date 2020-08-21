/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    struct cmp
    {
        bool operator()(const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        }
    };
    

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if(len < 2) return 0;
        //这里如果按照区间起始位置排序也可以，但是不是最少的
        //正确的做法是选择删除跨度最长的区间。
        sort(intervals.begin(), intervals.end(), cmp());
        int end = intervals[0][1];
        int i = 1;
        int cnt = 0;
        while(i < intervals.size()){
            if(intervals[i][0] < end) cnt++;
            else{
                end = intervals[i][1];
            }
            i++;
        }
        return cnt;
    }
};
// @lc code=end

