/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/28/
 * 移动零
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
 */
#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int count = 0;
    for (auto it = nums.begin(); it != nums.end(); it++)
    {
        if(*it==0){
            count++;
            nums.erase(it);
            it--;
        }
    }
    for(int i = 0; i < count; i++)
    {
        nums.push_back(0);
    }
    
}