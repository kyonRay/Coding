/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/5/strings/35/
 * 有效的字母异位词
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
 */

#include <iostream>
#include <map>
using namespace std;

bool isAnagram(string s, string t)
{
    int countS[26] = {0};
    int countT[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        countS[s[i] - 'a']++;
    }
    for (int i = 0; i < t.length(); i++)
    {
        countT[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (countT[i] != countS[i])
            return false;
    }
    return true;
}