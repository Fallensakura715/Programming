#include <iostream>
#include <algorithm>
using namespace std;

#define N 1010
int dp1[N], dp2[N][N];
int n, m, v[N], w[N];

void dp_2() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp2[i][j] = dp2[i-1][j];
            if (j >= v[i]) {
                dp2[i][j] = max(dp2[i][j], dp2[i - 1][j - v[i]] + w[i]);
            }
        }
    }
}

void dp_1() {
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= v[i]; --j) {
            dp1[j] = max(dp1[j], dp1[j - v[i]]+w[i]);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> w[i];
    }
    dp_1();
    dp_2();
    cout << dp1[m] << endl;
    cout << dp2[n][m] << endl;
    return 0;
}
