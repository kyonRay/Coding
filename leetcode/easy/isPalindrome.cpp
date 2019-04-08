/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/5/strings/36/
 * 验证回文字符串
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false
 */
#include <iostream>
using namespace std;

bool isPalindrome(string s)
{

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    for (auto i = s.begin(); i != s.end(); i++)
    {
        if (!isalnum(*i))
        {
            s.erase(i);
            i--;
        }
    }
    int size = s.length();
    for (int i = 0; i < size / 2 + 1; i++)
    {
        if (s[i] != s[size - i - 1])
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    string s = "A man, a plan, a canal: Panama";
    cout << isPalindrome(s) << endl;
    return 0;
}
