//Bitwise Operation

//按位与（AND）&：
//只有两个相应的二进制位都为1时，结果才为1，否则为0。
//例如：1100 & 1010 = 1000

//按位或（OR）|：
//只要两个二进制位中有一个为1，结果就为1。
//例如：1100 | 1010 = 1110

//按位异或（XOR）^：
//当两个二进制位不同（一个为1，另一个为0）时，结果为1；相同则为0。
//例如：1100 ^ 1010 = 0110

//按位取反（NOT）~：
//对每一个二进制位取反，即0变1，1变0。
//例如：~1100 = 0011（这里是按补码表示）

//左移（<<）：
//将二进制位向左移动指定的位数，右边补0。每左移一位，相当于乘以2。
//例如：1100 << 2 = 110000（相当于 12 * 2^2 = 48）

//右移（>>）：
//将二进制位向右移动指定的位数，左边补符号位（对无符号数补0，对有符号数补符号位）。每右移一位，相当于除以2。
//例如：1100 >> 2 = 11（相当于 12 / 2^2 = 3）
#include <iostream>
using namespace std;
int main (){
    int n=30;
    //n的二进制表示中第i位是几
    for (int i = 3; i >= 0; i--) cout << (n >> i & 1);
    return 0;
}
