#include <bits/stdc++.h>
using namespace std;

constexpr int N = 105;
int dp[N][N];
int value[N], select[N], weight[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  int n, v;
  cin >> n >> v;

  for (int i = 1; i <= n; ++i) {
    cin >> weight[i] >> value[i] >> select[i];
  }

  dp[1][0] = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= v; ++j) {
      for (int k = 0; k <= select[i] && k * weight[i] <= j; ++k) {
        dp[i][j] = max(dp[i - 1][j - weight[i] * k] + k * value[i], dp[i][j]);
      }
    }
  }

  cout << dp[n][v] << endl;

  return 0;
}