/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/26/others/68/
 * 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true
 */

#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s)
{
    if (s == "")
        return true;
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        switch (s[i])
        {
        case '{':
            st.push(s[i]);
            break;
        case '[':
            st.push(s[i]);
            break;
        case '(':
            st.push(s[i]);
            break;
        case '}':
            if (st.size() > 0 && st.top() == '{')
                st.pop();
            else
                return false;
            break;
        case ']':
            if (st.size() > 0 && st.top() == '[')
                st.pop();
            else
                return false;
            break;
        case ')':
            if (st.size() > 0 && st.top() == '(')
                st.pop();
            else
                return false;
            break;
        default:
            break;
        }
    }
    return st.empty() ? true : false;
}
