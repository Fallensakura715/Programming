#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 105;

int dp[N], value[N][N], c[N][N], s[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  int n, C;
  cin >> n >> C;

  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    for (int j = 0; j < s[i]; ++j) {
      cin >> c[i][j] >> value[i][j];
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = C; j >= 0; --j) {
      for (int k = 0; k < s[i]; ++k) {
        if (c[i][k] <= j)
          dp[j] = max(dp[j], dp[j - c[i][k]] + value[i][k]);
      }
    }
  }

  cout << dp[C];

  return 0;
}