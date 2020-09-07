/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    struct cmp
    {
        bool operator()(pair<int, int>& a, pair<int, int>& b){
            return a.second > b.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int x: nums) mp[x]++;//统计每个元素的频率
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;//定义小顶堆存放前K个
        for(auto& [key, val]: mp){
            if(pq.size() == k){
                if(pq.top().second < val){
                    pq.pop();
                    pq.emplace(key, val);
                }
            }
            else
                pq.emplace(key, val);
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end

