/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/23/
 * 旋转数组
 * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
 */

#include <iostream>
using namespace std;

void rotate(int *nums, int numsSize, int k)
{
    if (k == numsSize)
    {
        return;
    }
    if (k > numsSize)
    {
        k %= numsSize;
    }
    int *tempA = (int *)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++)
    {
        tempA[k - 1 - i] = nums[numsSize - 1 - i];
    }
    for (int i = numsSize - 1; i > k; i--)
    {
        nums[i] = nums[i - k - 1];
    }
    for (int i = 0; i < k; i++)
    {
        nums[i] = tempA[i];
    }
    free(tempA);
}