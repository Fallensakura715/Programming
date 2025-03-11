#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string a, b;
int n, m;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  cin >> n >> m;
  cin >> a >> b;

  int dp[n + 1][m + 1] = {0};

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  int dp1[m + 1] = {0};

  for (int i = 1; i <= n; ++i) {
    int prev = 0;
    for (int j = 1; j <= m; ++j) {
      int temp = dp1[j];
      if (a[i - 1] == b[j - 1]) {
        dp1[j] = prev + 1;
      } else {
        dp1[j] = max(dp1[j], dp1[j - 1]);
      }
      prev = temp;
    }
  }

  cout << dp[n][m] << endl;
  cout << dp1[m] << endl;

  return 0;
}