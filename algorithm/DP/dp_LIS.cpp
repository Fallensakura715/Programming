#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  int n;
  cin >> n;

  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> dp(n, 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[j] < a[i])
        dp[i] = max(dp[i], dp[j] + 1);
    }
  }

  vector<int> tails;
  //二分+贪心优化nlogn
  //tails[i]存的是 长度为i的上升子序列 的末尾 最可能小的值
  for (int x : a) {
    auto it = lower_bound(tails.begin(), tails.end(), x);
    if (it == tails.end()) {
      tails.push_back(x);
    } else {
      *it = x;
    }
  }

  int res = *max_element(dp.begin(), dp.end());
  cout << res << endl;

  cout << tails.size() << endl;

  return 0;
}
