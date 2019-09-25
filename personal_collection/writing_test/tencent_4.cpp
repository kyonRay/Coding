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
    int n, k;
    cin >> n >> k;
    vector<long> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<long> b(n, 0);
    long temp;
    cout << a[0] << endl;
    for (int i = 1; i < k; i++)
    {
        if (i >= a.size())
        {
            for (int j = 0; j < k - i; j++)
            {
                cout << 0 << endl;
            }
            break;
        }
        b[i] = b[i - 1] + a[i - 1];
        a[i] = a[i] - b[i];
        if (a[i] <= 0)
        {
            a.erase(a.begin() + i);
            i--;
        }
        else
        {
            cout << a[i] << endl;
        }
    }

    return 0;
}