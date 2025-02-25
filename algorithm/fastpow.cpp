#include <iostream>

using namespace std;

/*
    快速幂
    同余性质
    (a * b mod p) = (a mod p) * (b mod p) mod p;
    若n是偶数，a ^ n = (a ^ (n / 2))^2 = (a * a) ^ (n >> 1);
    若n是奇数, a ^ n = a * (a ^ (n - 1));
*/

long long pow(long long a, long long n) {
    long long result = 1;
    while (n > 0) {
        if (n & 1) {
            result *= a;
        }
        a *= a;
        n >>= 1;
    }
    return result;
}

long long powAndMod(long long a, long long n, long long p) {
    long long result = 1;
    a %= p;
    while (n > 0) {
        if (n & 1) {
            result *= a;
        }
        a = a * a % p;
        n >>= 1;
    }
    return result;
}

int main() {
    return 0;
}
