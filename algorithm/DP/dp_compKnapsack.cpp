#include <iostream>
#include <algorithm>
using namespace std;

constexpr int N = 1010;
int n, capacity;
int v[N], w[N], dp[N], dp2[N][N];

int main() {
    cin >> n >> capacity;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> w[i];
    }

    //¶þÎ¬dp
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= capacity; ++j) {
            dp2[i][j] = dp2[i - 1][j];
            if (j >= v[i]) dp2[i][j] = max(dp2[i][j], dp2[i][j - v[i]] + w[i]);
        }
    }
    
    //Ò»Î¬ÓÅ»¯°æ
    for (int i = 1; i <= n; ++i) {
        for (int j = v[i]; j <= capacity; ++j) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    cout << dp[capacity] << endl;
    cout << dp2[n][capacity] << endl;
    return 0;
}
