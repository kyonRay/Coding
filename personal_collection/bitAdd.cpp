/**
 * 用位操作实现加法
 */
#include <iostream>
using namespace std;

int Add(int a, int b)
{
    if (b == 0) // 无进位，返回
        return a;
    int sum, carry;
    sum = a ^ b;          // 加法
    carry = (a & b) << 1; // 进位
    return Add(sum, carry);
}
int main()
{
    cout << Add(333, 444) << endl;
    return 0;
}