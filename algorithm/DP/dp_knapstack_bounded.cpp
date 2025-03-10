#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2005;
// dp[i][j]：前 i 个物品在总容量 j 下能获得的最大价值（朴素算法）；
int dp[N][N];
int dp_01[N];
int dp_dq[N];

int value[N], select[N], weight[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  
  int n, c;
  cin >> n >> c;

  for (int i = 1; i <= n; ++i) {
    cin >> weight[i] >> value[i] >> select[i];
  }

  // O(N^3) 超级朴素算法
  dp[1][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= c; ++j) {
      for (int k = 0; k <= select[i] && k * weight[i] <= j; ++k) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i] * k] + k * value[i]);
      }
    }
  }

  // O(NC logS) 的 01 背包优化版本
  vector<int> vv, ww;
  for (int i = 1; i <= n; ++i) {
    int k = 1;
    int num = select[i];
    while (num > 0) {
      int take = min(k, num);
      vv.push_back(take * value[i]);
      ww.push_back(take * weight[i]);
      num -= take;
      k *= 2;
    }
  }

  int m = vv.size();
  dp_01[0] = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = c; j >= ww[i]; --j) {
      dp_01[j] = max(dp_01[j], dp_01[j - ww[i]] + vv[i]);
    }
  }

  // O(NC) 单调队列优化版本
  for (int i = 1; i <= n; i++) {
    
  }

  cout << dp[n][c] << "\n";
  cout << dp_01[c] << "\n";
  cout << dp_dq[c] << "\n";

  return 0;
}
