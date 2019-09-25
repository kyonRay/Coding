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
bool cmp(int a, int b) { return a > b; }
int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> x(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        vector<int> y(x);
        sort(x.begin(), x.end());
        sort(y.begin(), y.end(), cmp);
        int sum1 = 0, sum2 = 0;

        if (n % 4 == 0)
        {
            for (int i = 0; i < n / 4; i++)
            {
                sum1 += x[i];
                sum1 += y[i];
            }
            for (int i = n / 4; i < n / 2; i++)
            {
                sum2 += x[i];
                sum2 += y[i];
            }
            if (sum1 > sum2)
            {
                cout << sum2 << " ";
                cout << sum1 << endl;
            }
            else
            {
                cout << sum1 << " ";
                cout << sum2 << endl;
            }
        }
        else
        {
            for (int i = 0; i < n / 4; i++)
            {
                sum1 += x[i];
                sum1 += y[i];
            }
            if (n % 2 == 0)
            {
                for (int i = n / 4; i < n / 2 - 1; i++)
                {
                    sum2 += x[i];
                    sum2 += y[i];
                }
                if (sum1 > sum2)
                {
                    cout << sum2 + y[n / 2 - 1] << " ";
                    cout << sum1 + x[n / 2 - 1] << endl;
                }
                else
                {
                    cout << sum1 + y[n / 2 - 1] << " ";
                    cout << sum2 + x[n / 2 - 1] << endl;
                }
            }
            else
            {
                for (int i = n / 4; i < n / 2; i++)
                {
                    sum2 += x[i];
                    sum2 += y[i];
                }
                if (sum1 > sum2)
                {
                    cout << sum2 + y[n / 2] << " ";
                    cout << sum1 << endl;
                }
                else
                {
                    cout << sum1 + y[n / 2] << " ";
                    cout << sum2 << endl;
                }
            }
        }
    }

    return 0;
}