/**
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/climbing-stairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

思路：
动态规划的经典题目
后一段结果与前一段结果有关：
在爬上第n阶的时候，可以从n-1阶上1层，也可以从n-2上2层，所以爬上n阶的方法总数是爬上(n-1)阶的次数与爬上(n-2)阶次数的和
f(n)=f(n-1)+f(n-2)
*/

#include <iostream>
using namespace std;

int climbStairs(int n)
{
    if (n == 1 || n == 2)
        return n;
    int a = 1;
    int b = 2;
    int re;
    for (int i = 2; i < n; i++)
    {
        re = a + b;
        a = b;
        b = re;
    }
    return re;
}
