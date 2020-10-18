/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/24/
 * 存在重复
 * 给定一个整数数组，判断是否存在重复元素。
 * 如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
 */

#include <iostream>
using namespace std;
#include <algorithm>
int cmp(const void *a, const void *b)
{
    return *(int *)a > *(int *)b;
}
bool containsDuplicate(int *nums, int numsSize)
{
    if (numsSize == 0 || numsSize == 1)
        return false;
    if (nums == nullptr)
        return false;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] == nums[i - 1])
            return true;
    }
    return false;
}