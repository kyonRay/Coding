/**
 * https://leetcode-cn.com/problems/set-mismatch/
 * 集合 S 包含从1到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个元素复制了成了集合里面的另外一个元素的值，导致集合丢失了一个整数并且有一个元素重复。

给定一个数组 nums 代表了集合 S 发生错误后的结果。你的任务是首先寻找到重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。

示例 1:

输入: nums = [1,2,2,4]
输出: [2,3]
 */

/**
 * 解题思路:
 * 快排寻找重复数
 * 1-n 累加的值减去实际的和,再加上重复数字就是错误数字了
 */

#include <iostream>
#include <vector>
using namespace std;
vector<int> findErrorNums(vector<int> &nums)
{
    int i = 1, temp = 0, sum = 0;
    vector<int> result;
    sort(nums.begin(), nums.end());
    // 找出重複的
    for (auto it = nums.begin(); it != nums.end() - 1; it++)
    {
        sum += *it;
        if (*(it + 1) == *it)
        {
            temp = *it;
        }
    }
    sum += *(nums.end() - 1);
    result.push_back(temp);
    result.push_back((1 + nums.size()) * nums.size() / 2 - sum + temp);
    
    return result;
}
int main()
{
    vector<int> nums = {1, 1};
    findErrorNums(nums);
    return 0;
}