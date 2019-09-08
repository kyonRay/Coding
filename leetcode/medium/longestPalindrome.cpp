/**
 * 
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestPalindrome(string s)
{
    int len = s.length();
    if (len == 0 || len == 1)
        return s;
    int begin = 0;
    int max = 1;
    vector<vector<int>> dp(len, vector<int>(len));
    for (int i = 0; i < len; i++)
    {
        dp[i][i] = 1;
        if (i < len - 1 && s[i] == s[i + 1])
        {
            dp[i][i + 1] = 1;
            max = 2;
            begin = i;
        }
    }
    for (int l = 3; l <= len; l++)
    {
        for (int i = 0; i + l - 1 < len; i++)
        {
            int j = l + i - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
            {
                dp[i][j] = 1;
                begin = i;
                max = l;
            }
        }
    }
    return s.substr(begin, max);
}