/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        return match(s.data(), p.data());
    }

    bool match(char* s, char* p){
        if(!*p) return !*s;//模式串为空，则返回目标串是否为空
        if(*(p + 1) != '*')//如果后一位不是*，则当前这一位必须匹配，否则就返回false
            return (*p == *s || (*p == '.' && *s != '\0')) ? match(s+1, p+1) : false;
        else//如果后一位是*，则1)当前位匹配，进行目标串下一位或者模式串走两位(万一后面也匹配，当前就可以放弃)，2)当前位不匹配，跳过当前位
            return (*s == *p || (*p == '.' && *s != '\0')) ? (match(s+1, p) || match(s, p+2)) : match(s, p+2);
    }
};
// @lc code=end

