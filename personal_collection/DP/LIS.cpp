/**
 * 最长递增子序列
 * 给定一个长度为n的整数序列S，求这个序列中最长的严格递增子序列的长度。
输入描述:
第一行，一个整数n (2<=n<=50000)，表示序列的长度

第二行，有n个整数 (-10^9 <= S[i] <= 10^9)，表示这个序列
输出描述:
输出一个整数，表示最长递增子序列的长度
输入
6
4 0 5 8 7 8
输出
4
备注:
样例解释 子序列为 0 5 7 8
 */

#include <iostream>
#include <vector>

using namespace std;

// DP方法 时间复杂度 O(n^2)
int LIS(vector<int> &arr)
{
    int size = arr.size();
    vector<int> dp(size, 0);
    int ans = -1;
    for (int i = 1; i < size; i++)
    {
        dp[i] = max(dp[i], 1);
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] > arr[i])
                dp[j] = max(dp[j], dp[i] + 1);
        }
        ans = max(ans, dp[i]);
    }
}
