/**
 * https://leetcode-cn.com/problems/palindrome-number/
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 */

/**
 * 在处理整数的时候往往会触及到整数超界的问题,需要另外的方法解
 */

#include <iostream>
using namespace std;
bool isPalindromeNum(int x)
{
    if (x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }
    int temp = 0;
    while (x > temp)
    {
        temp *= 10;
        temp += x % 10;
        x /= 10;
    }
    return x == temp || x == (temp / 10);
}
int main()
{
    cout << isPalindromeNum(2147483647) << endl;
    cout << isPalindromeNum(121) << endl;
    cout << isPalindromeNum(1222) << endl;
    return 0;
}