/* 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
思路：
动态规划的思路，按照保存
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int maxArea(vector<int> &height)
{
    int h = 0;
    int res = 0;
    int low = 0;
    int high = height.size() - 1;
    while (low < high)
    {
        h = min(height[low], height[high]);
        res = max(res, h * (high - low));
        if (height[low] > height[high])
            high--;
        else
            low++;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> c = {2, 3, 10, 5, 7, 8, 9};
    cout << maxArea(c);
    return 0;
}
