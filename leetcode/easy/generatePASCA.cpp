/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/26/others/67/
 * 帕斯卡三角形
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
 */

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> re;
    if (numRows == 0)
        return re;
    re.push_back({1});
    if (numRows == 1)
        return re;
    re.push_back({1, 1});
    if (numRows == 2)
        return re;
    for (int i = 2; i < numRows; i++)
    {
        vector<int> newRow;
        newRow.push_back(1);
        for (int j = 1; j < re[i - 1].size(); j++)
        {
            newRow.push_back(re[i - 1][j - 1] + re[i - 1][j]);
        }
        newRow.push_back(1);
        re.push_back(newRow);
    }
    return re;
}

int main(int argc, char const *argv[])
{
    generate(4);
    return 0;
}
