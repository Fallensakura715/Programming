#include <iostream>

using namespace std;

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