/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/5/strings/33/
 * 整数反转
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 */

#include <iostream>

using namespace std;

int reverses(int x)
{
    long y = x;
    long z = 0;
    while (y)
    {
        z *= 10;
        z += y % 10;
        y /= 10;
    }
    if (z > INT_MAX || z < INT_MIN)
        return 0;
    return z;
}

int main(int argc, char const *argv[])
{
    cout << reverses(6463847412) << endl;
    return 0;
}
