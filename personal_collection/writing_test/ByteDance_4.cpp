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
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    char temp;
    cin >> s;
    string temp1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '0')
            temp = s[i] - '1' + 'A';
    }
    cout << temp1 << endl;

    

    return 0;
}
