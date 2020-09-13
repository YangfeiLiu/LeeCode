/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxv = 0;
        for(int i = 0; s[i] != '\0'; i++){
            if(s[i] == '(') st.push(i); //左括号直接进栈，因为能与之匹配的都在后面
            else{
                // 因为提前push了-1，所以这里不需要比较当前栈顶是左括号还是右括号，因为，如果当前栈顶是左括号，那么现在进来的是右括号
                // 则可以直接pop，如果当前栈顶是右括号，那么pop之后，栈肯定为空，因为栈里存的是当前最大的没有匹配的元素。
                st.pop();
                if(!st.empty()){
                    int len = i - st.top();
                    maxv = max(maxv, len);
                }
                else st.push(i);
            }
        }
        return maxv;
    }
};
// @lc code=end

