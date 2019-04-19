/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/8/sorting-and-searching/53/
 * 你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。

假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。

你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。

示例:

给定 n = 5，并且 version = 4 是第一个错误的版本。

调用 isBadVersion(3) -> false
调用 isBadVersion(5) -> true
调用 isBadVersion(4) -> true

所以，4 是第一个错误的版本。 
 */
#include <iostream>
using namespace std;

bool isBadVersion(int version);

int firstBadVersion(int n)
{
    int start = 0;
    int end = n;
    while (start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (isBadVersion(mid))
        {
            end = mid;
        }
        else
        {
            start = mid;
        }
    }
    if (isBadVersion(start))
        return start;

    if (isBadVersion(end))
        return end;

    return -1;
}
