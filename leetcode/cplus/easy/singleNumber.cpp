/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/25/
 * 只出现一次的数字
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 * 说明：
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 */

#include <iostream>
using namespace std;

int singleNumber(int *nums, int numsSize)
{
    if (numsSize == 1)
        return nums[0];
    int temp = 0;
    for (int i = 0; i < numsSize; i++)
    {
        temp = temp ^ nums[i];  //相同的数字异或为0，数字异或0为本身
    }
    return temp;
}