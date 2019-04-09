/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/5/strings/40/
 * 编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.size() == 0)
        return "";
    int minSize = strs[0].length();
    for (int i = 1; i < strs.size(); i++)
    {
        minSize = minSize < strs[i].length() ? minSize : strs[i].length();
    }
    string sample = "";
    string lastSample = "";
    for (int i = 0; i < minSize; i++)
    {
        lastSample = sample;
        sample += strs[0][i];
        for (int j = 1; j < strs.size(); j++)
        {
            if (sample[i] != strs[j][i])
                return lastSample;
        }
    }
    return sample;
}
