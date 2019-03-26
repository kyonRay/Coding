/**
 * 计算十进制数转换到二进制数中1的个数
 * 计算十进制数转换到二进制数中0的个数
 * 
 */
#include <iostream>
using namespace std;

int countOne(int binary)
{
    int count = 0;
    while (binary)
    {
        count++;
        binary &= (binary - 1);
    }
    return count;
}
int countZero(int binary){
    int count = 0;
    while (binary+1)
    {
        count++;
        binary |= (binary + 1);
    }
    return count;
}
int countOne2(int n){
    n = (n &0x55555555) + ((n >>1)&0x55555555) ;
    n = (n &0x33333333) + ((n >>2)&0x33333333) ;
    n = (n &0x0f0f0f0f) + ((n >>4)&0x0f0f0f0f) ;
    n = (n &0x00ff00ff) + ((n >>8)&0x00ff00ff) ;
    n = (n &0x0000ffff) + ((n >>16)&0x0000ffff) ;

    return n ;
}
int main(int argc, char const *argv[])
{
    cout << countOne(-1) << endl;
    cout << countZero(-1) << endl;
    cout << countOne2(-1) << endl;
    return 0;
}
