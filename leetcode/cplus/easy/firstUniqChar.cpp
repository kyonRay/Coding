/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/5/strings/34/
 * 字符串中的第一个唯一字符
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

案例:

s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.
 */

#include <iostream>
#include <string>
#include <map>
using namespace std;

int firstUniqChar(string s)
{
    int countChar[26] = {0};
    int firstPlace[26] = {0};
    int size = s.length();
    for (int i = 0; i < size; i++)
    {
        if (countChar[s[i] - 'a'] == 0)
            firstPlace[s[i] - 'a'] = i;
        countChar[s[i] - 'a']++;
    }
    for (int i = 0; i < size; i++)
    {
        if (countChar[s[i] - 'a'] == 1)
            return firstPlace[s[i] - 'a'];
    }
    return -1;
}