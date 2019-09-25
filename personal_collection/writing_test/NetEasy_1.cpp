#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    int len;
    cin >> T;
    long num;
    long temp1, temp2;
    while (T--)
    {
        cin >> num;
        temp1 = 1;
        temp2 = num >> 1;
        len = 1;
        while (temp2)
        {
            temp1 <<= 1;
            temp2 >>= 1;
            len++;
        }
        len = len / 2;
        bool flag = true;
        while (len--)
        {
            if ((temp1 & num) != 0 && (num & 1) == 0)
            {
                cout << "NO" << endl;
                flag = false;
                break;
            }
            if ((temp1 & num) == 0 && (num & 1) != 0)
            {
                cout << "NO" << endl;
                flag = false;
                break;
            }
            num &= (~temp1);
            num >>= 1;
            temp1 >>= 2;
        }
        if (flag)
            cout << "YES" << endl;
    }

    return 0;
}
