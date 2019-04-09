/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/5/strings/39/
 * 报数
报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。

注意：整数顺序将表示为一个字符串。
 */

#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n)
{
    if (n == 1)
        return "1";
    if (n == 2)
        return "11";
    if (n == 3)
        return "21";
    if (n == 4)
        return "1211";
    string str = "111221";
    string strNew = "";
    int count = 1;
    for (int i = 6; i <= n; i++)
    {
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j + 1] != str[j])
            {
                strNew += to_string(count);
                strNew += str[j];
                count = 1;
            }
            else
            {
                count++;
            }
        }
        str = strNew;
        strNew = "";
    }
    return str;
}