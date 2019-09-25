#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int k, m;
        cin >> k >> m;
        k++;
        vector<int> fix(m);

        if (m == 0)
        {
            if (30 % k == 0)
                cout << 30 / k << endl;
            else
                cout << 30 / k + 1 << endl;
            continue;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> fix[i];
        }

        int count = 0;

        //最后一次玩游戏后喝咖啡的次数
        int inter = 30 - fix[m - 1] - k + 1;
        if (inter > 0)
        {
            if (inter % k == 0)
                count += inter / k;
            else
                count += inter / k + 1;
        }
        //中间喝咖啡的次数
        for (int i = m - 1; i >= 1; i--)
        {

            inter = fix[i] - fix[i - 1] - 1;
            inter = inter - k + 1;
            if (inter > 0)
            {
                if (inter % k <= (k - 1))
                    count += inter / k;
                else
                    count += inter / k + 1;
            }
        }

        //第一次玩游戏之前喝咖啡的次数
        inter = fix[0] - k;
        if (inter > 0)
        {
            if (inter % k == 0)
                count += inter / k;
            else
                count += inter / k + 1;
        }

        cout << count + m << endl;
    }
    return 0;
}