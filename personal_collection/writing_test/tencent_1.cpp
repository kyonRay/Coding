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
#include <limits.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    int n;
    string s;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cin >> s;
        if (n < 11)
        {
            cout << "NO" << endl;
            continue;
        }
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == '8')
            {
                if ((s.length() - j) >= 11)
                {
                    cout << "YES" << endl;
                    break;
                }
            }
            if ((s.length() - j) < 11)
            {
                cout << "NO" << endl;
                break;
            }
        }
    }

    return 0;
}