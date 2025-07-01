#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1e3;
constexpr int INF = numeric_limits<int>::max();

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> weight(n + 1);
  vector<int> prefix(n + 1, 0);
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  vector<vector<int>> dpMax(n + 1, vector<int>(n + 1, 0));

  for (int i = 1; i <= n; ++i) {
    cin >> weight[i];
    prefix[i] = prefix[i - 1] + weight[i];
  }

  for (int len = 2; len <= n; ++len) {
    for (int i = 1; i <= n - len + 1; ++i) {
      int j = i + len - 1;
      dp[i][j] = INF; 
      for (int k = i; k < j; ++k) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + prefix[j] - prefix[i - 1]);
        dpMax[i][j] = max(dpMax[i][j], dpMax[i][k] + dpMax[k + 1][j] + prefix[j] - prefix[i - 1]);
      }
    }
  }

  cout << dp[1][n] << "\n";
  cout << dpMax[1][n] << "\n";

  return 0;
}
