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
    int T, n;
    vector<long> a, b;
    cin >> T >> n;
    long temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
        cin >> temp;
        b.push_back(temp);
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += b[i] - a[i];
    }
    if (sum <= 0)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}
