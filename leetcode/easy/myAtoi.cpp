/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/5/strings/37/
 * 字符串转换整数 (atoi)
请你来实现一个 atoi 函数，使其能将字符串转换成整数。

首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。

当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。

该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。

注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。

在任何情况下，若函数不能进行有效的转换时，请返回 0。

说明：

假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，qing返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。

示例 1:

输入: "42"
输出: 42
示例 2:

输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
 */

#include <iostream>
#include <string>

using namespace std;

int myAtoi(string str)
{
    bool nagFlag = false;  // 负数
    bool findFlag = false; // 数字
    long long sum = 0;
    if (str[0] == '.')
        return 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ' && (str[i] > '9' || str[i] < '0') && str[i] != '-' && str[i] != '.' && str[i] != '+')
        {
            return 0;
        }
        if (str[i] == '-')
        {
            nagFlag = true;
            if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
                return 0;
        }
        if (str[i] == '+')
        {
            if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
                return 0;
        }
        if ((str[i] >= '0' && str[i] <= '9') && sum == 0)
        {
            sum = str[i] - '0';
            if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
            {
                break;
            }
            findFlag = true;
            continue;
        }
        if ((str[i] >= '0' && str[i] <= '9') && findFlag)
        {
            sum = sum * 10 + (str[i] - '0');
            if (sum > INT_MAX || -sum < INT_MIN)
                break;
            if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
            {
                findFlag = false;
                break;
            }
        }
    }
    sum = nagFlag ? -sum : sum;
    if (sum > INT_MAX)
        return INT_MAX;
    if (sum < INT_MIN)
        return INT_MIN;
    return sum;
}
