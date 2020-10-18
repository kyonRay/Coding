/* 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

思路：
简单的想法就是两个数组进行归并，然后找中位数, 时间复杂度为O(m+n)
大神给的二分切割法可以学习一下，时间复杂度O(long(m+n))
*/
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

double findMedianSortedArraysLow(vector<int> &nums1, vector<int> &nums2)
{
    int len1 = nums1.size();
    int len2 = nums2.size();
    int n1 = 0, n2 = 0;
    vector<int> v(len1 + len2);
    int i;
    for (i = 0; i < len1 + len2; i++)
    {
        if (n1 >= len1 || n2 >= len2)
            break;
        if (nums1[n1] > nums2[n2])
        {
            v[i] = nums2[n2++];
        }
        else
        {
            v[i] = nums1[n1++];
        }
    }
    if (n1 < len1)
    {
        while (n1 != len1)
        {
            v[i++] = nums1[n1++];
        }
    }
    if (n2 < len2)
    {
        while (n2 != len2)
        {
            v[i++] = nums2[n2++];
        }
    }
    return (len1 + len2) & 1 ? (double)v[(len1 + len2) / 2] : (double)(v[(len1 + len2) / 2] + v[(len1 + len2) / 2 - 1]) / 2;
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();

    if (n > m) //保证数组1一定最短
    {
        return findMedianSortedArrays(nums2, nums1);
    }

    // Ci 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
    int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n; //我们目前是虚拟加了'#'所以数组1是2*n长度

    while (lo <= hi) //二分
    {
        c1 = (lo + hi) / 2; //c1是二分的结果
        c2 = m + n - c1;

        LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
        RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
        LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
        RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

        if (LMax1 > RMin2)
            hi = c1 - 1;
        else if (LMax2 > RMin1)
            lo = c1 + 1;
        else
            break;
    }
    return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
}
