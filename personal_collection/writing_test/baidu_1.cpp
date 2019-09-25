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
    long n, m, k;
    cin >> n >> m >> k;
    if ((n * m) < k)
    {
        cout << 0 << endl;
    }
    cout << ((2 * n + 2 * m) - 4 * sqrt(k)) / 2 << endl;
    return 0;
}
