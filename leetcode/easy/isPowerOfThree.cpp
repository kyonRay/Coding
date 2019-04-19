/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/25/math/62/
 * 3的幂
给定一个整数，写一个函数来判断它是否是 3 的幂次方。

示例 1:

输入: 27
输出: true
示例 2:

输入: 0
输出: false
示例 3:

输入: 9
输出: true
示例 4:

输入: 45
输出: false
进阶：
你能不使用循环或者递归来完成本题吗？
 */

#include <iostream>
using namespace std;

bool isPowerOfThree(int n)
{
    // return n > 0 && 1162261467%n == 0; 不循环不递归的方法，1162261467是3^19，int范围内最大的3次幂
    if (n < 1)
        return false;
    while (n != 1)
    {
        if (n % 3 == 0)
            n /= 3;
        else
            return false;
    }
    return true;
}
