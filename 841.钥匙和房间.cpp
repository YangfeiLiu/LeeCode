 /*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

// @lc code=start
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int num = rooms.size(); // 房间数
        vector<int> ans(num, 0);
        stack<int> st;
        st.push(0);
        ans[0] = 1; // 已经访问过
        while(!st.empty()){
            int index = st.top();
            st.pop();
            for(auto x: rooms[index]){
                if(ans[x]) continue;
                else{
                    ans[x] = 1;
                    st.push(x);
                }
            }
        }
        if(accumulate(ans.begin(), ans.end(), 0) == num) return true;
        return false;
    }
};
// @lc code=end

