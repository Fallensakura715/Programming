#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2005;
int dp[N][N], dp_01[N], dp_dq[N];
int value[N], select[N], weight[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  int n, c;
  cin >> n >> c;

  for (int i = 1; i <= n; ++i) {
    cin >> weight[i] >> value[i] >> select[i];
  }

//O(N^3)超级朴素算法
  dp[1][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= c; ++j) {
      for (int k = 0; k <= select[i] && k * weight[i] <= j; ++k) {
        dp[i][j] = max(dp[i - 1][j - weight[i] * k] + k * value[i], dp[i][j]);
      }
    }
  }

//O(NClogS)01优化版本
  vector<int> vv, ww;
  for (int i = 1; i <= n; ++i) {
    int k = 1;
    int num = select[i];
    while (num > 0) {
      int take = min(k, num);
      vv.push_back(k * value[i]);
      ww.push_back(k * weight[i]);
      num -= take;
      k *= 2;
    }
  }

  n = vv.size();
  for (int i = 1; i <= n; ++i) {
    for (int j = c; j >= vv[i]; --j) {
      dp_01[j] = max(dp_01[j], dp_01[j - ww[i]] + vv[i]);
    }
  }

//O(NC)单调队列优化版本
  for (int i = 1; i <= N; i++) {
    deque<int> dq;
    for (int r = 0; r < value[i]; r++) {
      dq.clear();
      for (int j = r; j <= c; j += value[i]) {
        if (!dq.empty() && dq.front() < j - select[i] * value[i]) dq.pop_front();
        int val = dp_dq[j] - (j / value[i]) * weight[i];
        while (!dq.empty() && dp_dq[dq.back()] - (dq.back() / value[i]) * weight[i] <= val) {
          dq.pop_back();
        }
        dq.push_back(j);
        dp_dq[j] = dp_dq[dq.front()] + (j / value[i]) * weight[i];
      }
    }
  }

  cout << dp[n][c] << endl;
  cout << dp_01[c] << endl;
  cout << dp_dq[c] << endl;

  return 0;
}
