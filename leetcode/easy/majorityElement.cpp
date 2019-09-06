/**
 * 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

思路：
首先想到的是按位记录，但是好像范围就太大了，还有map做记录，排序做检索

有个特殊的投票方法，假设，所有众数都持有票数+1，其他数都持有票数-1，那么所有票数加起来一定是正数
将第一个数假设为众数，如果下一个数与他相等则++，不想等就--，若票数为负了，那么就更换众数的假设
*/

#include <iostream>
#include <vector>
using namespace std;
int majorityElement(vector<int> &nums)
{
    int flag = 1;
    int val = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == val)
        {
            flag++;
        }
        else
        {
            flag--;
        }
        if (flag < 0)
        {
            val = nums[i];
            flag = 0;
        }
    }
    return val;
}