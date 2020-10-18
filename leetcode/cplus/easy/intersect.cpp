/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/26/
 * 两个数组的交集 II
 * 给定两个数组，编写一个函数来计算它们的交集。
 * 示例 1:
 * 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出: [2,2]
 */

#include <iostream>
using namespace std;

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b)
{
    return *(int *)a > *(int *)b;
}
int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    int *returnArray = (int *)malloc(sizeof(int) * nums1Size);
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    int a = 0, b = 0;
    *returnSize = 0;
    while (a < nums1Size && b < nums2Size)
    {
        if (nums1[a] > nums2[b])
        {
            b++;
        }
        else if (nums1[a] < nums2[b])
        {
            a++;
        }
        else
        {
            returnArray[(*returnSize)++] = nums1[a];
            a++;
            b++;
        }
    }
    return returnArray;
}

void test(char *testName, int *num1, int num1Size, int *num2, int num2Size)
{
    printf("%s:", testName);
    int size = 0;
    int *result = intersect(num1, num1Size, num2, num2Size, &size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", result[i]);
    }
    puts("\n");
    free(result);
}
int main(int argc, char const *argv[])
{
    int nums1[] = {1, 2, 3, 4, 4, 5};
    int nums2[] = {3, 4, 5};
    test("test1", nums1, 6, nums2, 3);
    return 0;
}
