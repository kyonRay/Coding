/**
 * 给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

示例:

输入: [1,2,3,4]
输出: [24,12,8,6]
说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/product-of-array-except-self
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

思路：
如果使用暴力算法，每个连乘，那么时间复杂度是 O(n^2)，题目规定也不能用除法，可以使用位运算实现除法（难度大）
方法很巧妙，一个数字的乘积 = 左乘积 * 右乘积
*/

#include <iostream>
#include <vector>
using namespace std;
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> re(n, 1);
    int left = 1, right = 1;
    for (int i = 0; i < n; i++)
    {
        re[i] *= left;
        left *= nums[i];
        re[n - 1 - i] *= right;
        right *= nums[n - 1 - i];
    }
    return re;
}
