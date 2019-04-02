/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/21/
 * 从排序数组中删除重复项
 * 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
 * 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
 */

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    int number = nums.capacity();
    for (auto it = nums.begin() + 1; it != nums.end(); it++)
    {
        if (*it == *(it - 1))
        {
            nums.erase(it);
            it--;
            number--;
        }
    }
    return number;
}