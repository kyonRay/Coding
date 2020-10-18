/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/5/strings/38/
 * 实现strStr()
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
 */

#include <iostream>
using namespace std;

int strStr(string haystack, string needle)
{
    int ptrH = 0, ptrN = 0;
    if (needle.length() < 1)
        return 0;
    if (haystack.length() < needle.length())
        return -1;
    if (haystack.length() == needle.length())
    {
        if (haystack == needle)
            return 0;
        else
            return -1;
    }
    for (; ptrH < haystack.length(); ptrH++)
    {

        if (haystack[ptrH] == needle[ptrN])
        {
            ptrN++;
        }
        else
        {
            ptrH = ptrH - ptrN;
            ptrN = 0;
        }
        if (ptrN == needle.length())
        {
            return ptrH - ptrN + 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    string s1 = "mississippi";
    string s2 = "pi";
    cout << strStr(s1, s2) << endl;
    return 0;
}
