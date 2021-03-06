/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/30/
 * 有效的数独
判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

数独部分空格内已填入了数字，空白格用 '.' 表示。

示例 1:

输入:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
输出: true
 */

#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    bool check[10] = {0};
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
                continue;
            if (check[board[i][j] - '0'])
                return false;
            else
                check[board[i][j] - '0'] = true;
        }
        memset(check, 0, 10);
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[j][i] == '.')
                continue;
            if (check[board[j][i] - '0'])
                return false;
            else
                check[board[j][i] - '0'] = true;
        }
        memset(check, 0, 10);
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int a = 0; a < 3; a++)
            {
                for (int b = 0; b < 3; b++)
                {
                    if (board[i * 3 + a][j * 3 + b] == '.')
                        continue;
                    if (check[board[i * 3 + a][j * 3 + b] - '0'])
                        return false;
                    else
                        check[board[i * 3 + a][j * 3 + b] - '0'] = true;
                }
            }
            memset(check, 0, 10);
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    vector<vector<char>> v = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout << isValidSudoku(v) << endl;
    return 0;
}
