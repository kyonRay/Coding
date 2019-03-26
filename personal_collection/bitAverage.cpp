/**
 * 求两个整数平均数
 */
#include <iostream>
using namespace std;

int ave(int x, int y)
{
    return (x & y) + ((x ^ y) >> 1);
}

int main(){
    cout<<ave(729,271)<<endl; // 500
    return 0;
}