#include <iostream>
#include <vector>

using namespace std;

void prime_Eratosthenes(int n, vector<bool> &isPrime) {
    if (n < 2) return;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    prime_Eratosthenes(n, isPrime);
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    return 0;
}