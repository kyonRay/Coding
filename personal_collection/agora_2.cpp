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
inline int findMax(vector<long> &v)
{
    long maxHi = INT_MIN;
    int pos = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > maxHi)
        {
            maxHi = v[i];
            pos = i;
        }
    }
    return pos;
}
inline int findMaxOf3(int a, int b, int c)
{
    int max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    return max;
}
int maxSight(vector<long> &v)
{
    if (v.size() <= 1)
        return 0;
    int maxPos = findMax(v);
    vector<long> vleft(v.begin(), v.begin() + maxPos);
    vector<long> vright(v.begin() + maxPos, v.end());
    int leftMaxPos = findMax(vleft);
    int rightMaxPos = findMax(vright);
    int maxSaw = rightMaxPos - leftMaxPos - 1;
    int leftMax = maxSight(vleft);
    int rightMax = maxSight(vright);
    return findMaxOf3(maxSaw, leftMax, rightMax);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<long> hi(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> hi[i];
    }
    cout << maxSight(hi) << endl;
    return 0;
}
