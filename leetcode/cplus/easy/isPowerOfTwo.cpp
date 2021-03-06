/**
 * 
 * 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

示例 1:

输入: 1
输出: true
解释: 20 = 1
示例 2:

输入: 16
输出: true
解释: 24 = 16
示例 3:

输入: 218
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/power-of-two
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

思路：
主要是计算二进制中，1的个数，如果个数只有一个，那么就是2的幂数
*/

#include <iostream>
using namespace std;

bool isPowerOfTwo(int n)
{
    return (n > 0) && (!(n & (n - 1)));
}
