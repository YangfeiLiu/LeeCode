/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
public:
    vector<string> ans;
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> hash;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto ticket: tickets){
            hash[ticket[0]].push(ticket[1]);
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void dfs(const string& str){
        while(hash.count(str) && hash[str].size() > 0){ // 如果当前的str存在，并且有下一站
            string tmp = hash[str].top();// 当前站首先去的地方
            hash[str].pop();// 已经去过的就不再去了
            dfs(tmp);
        }
        ans.emplace_back(str);
    }
};
// @lc code=end

