/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/31/
 * 旋转图像
给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
 */

#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int row = matrix.size() - 1;
    int col = matrix[0].size() - 1;
    for (int i = 0; i < row; i++) //对角翻转
    {
        for (int j = 0; j < col - i; j++)
        {
            swap(matrix[i][j], matrix[row - j][col - i]);
        }
    }
    for (int i = 0; i < matrix.size() / 2; i++) //上下翻转
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            swap(matrix[i][j], matrix[row - i][j]);
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix;
    matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    rotate(matrix);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
