/**
 * https://leetcode-cn.com/problems/maximum-subarray/
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 */

/**
 * 解题思路：
 * sum做记录，若大于0，说明一直是增益的，加入；若小于0则说明是减益的，需要舍弃
 * ans记录最大和
 */

#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    int sum = 0, ans = nums[0];
    for (int n : nums)
    {
        if (sum > 0)
            sum += n;
        else
            sum = n;
        ans = max(ans, sum);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> test = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(test) << endl;
    return 0;
}
