/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        string ans;
        for(int i = 0; s[i] != '\0'; i++){
            if(s[i] == ' '){
                while(!st.empty()){
                    ans += st.top();
                    st.pop();
                }
                ans += s[i];
            }
            else st.push(s[i]);
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
// @lc code=end

