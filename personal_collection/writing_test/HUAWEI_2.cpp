#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <map>
#include <algorithm>
#include <string>
#include <stack>
#include <cstdio>
using namespace std;

bool isValible(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '-' || c == ' ')
        return true;
    return false;
}

void spilt(string s, vector<string> &v)
{
    string::size_type pos1, pos2;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == ' ' && s[i - 1] == ' ')
            s.erase(s.begin() + i);
    }

    pos2 = s.find(" ");
    pos1 = 0;
    while (string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2 - pos1));
        pos1 = pos2 + 1;
        pos2 = s.find(" ", pos1);
    }
    if (pos1 != s.length())
    {
        v.push_back(s.substr(pos1));
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "")
        {
            v.erase(v.begin() + i);
            if (i != 0)
            {
                i--;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    string s;
    getline(cin, s);
    vector<string> v;
    while (!isValible(s[0]))
    {
        if (!isValible(s[0]) || s[0] == '-')
        {
            s.erase(s.begin());
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (!isValible(s[i]))
        {
            s.erase(s.begin() + i);
        }
    }
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == ' ' && s[i - 1] == '-')
        {
            s.erase(s.begin() + i - 1);
        }
        if (s[i] == '-' && s[i - 1] == ' ')
        {
            s.erase(s.begin() + i);
        }
    }
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == '-' && s[i - 1] == '-')
        {
            s.erase(s.begin() + i);
            s.erase(s.begin() + i - 1);
            s.insert(i - 1, " ");
        }
    }

    spilt(s, v);
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i];
        if (i != 0)
            cout << " ";
        else
            cout << endl;
    }

    return 0;
}

// --I am an 20-years  out--standing @ * -stu- dent