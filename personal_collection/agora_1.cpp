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
    long number;
    int a;
    cin >> number;
    int num = 0;
    int maxCount = 0;
    vector<int> vec;
    while (number)
    {
        if (number % 2 == 1)
        {
            vec.push_back(1);
        }
        else if (number % 2 == 0)
        {
            vec.push_back(0);
        }
        number /= 2;
    }
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        if (*it == 1)
        {
            num++;
        }
        else if (*it == 0)
        {
            num = 0;
        }
        maxCount = maxCount > num ? maxCount : num;
    }
    cout << maxCount << endl;
    return 0;
}