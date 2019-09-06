/**
 * https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
 * 
 * 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 
注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
*/

#include <iostream>
#include <string>
using namespace std;

string reverseWords(string s)
{
    int from = 0, to = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i + 1] == ' ' || s[i + 1] == '\0')
        {
            to = i + 1;
            reverse(s.begin() + from, s.begin() + to);
            from = i + 2;
        }
    }
    return s;
}
int main(int argc, char const *argv[])
{
    string s = "Let's take LeetCode contest";
    cout << "reverse:   " << reverseWords(s) << endl;
    return 0;
}
