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

long Add(long a, long b)
{
    if (b == 0)
        return a;
    if (a == 0)
        return b;
    long sum, carry;
    sum = a ^ b;
    carry = (a & b) << 1;
    return Add(sum, carry);
}
int main(int argc, char const *argv[])
{
    long n;
    cin >> n;
    vector<long> a(n, 0);
    vector<long> b(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    long sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum ^= (a[i] + b[j]);
        }
    }
    // sort(s.begin(), s.end());
    // for (int i = 1; i < n * n; i++)
    // {
    //     if ((s[i] != 0) && (s[i] == s[i - 1]))
    //     {
    //         s[i] = 0;
    //         s[i - 1] = 0;
    //     }
    // }

    cout << sum << endl;
    return 0;
}