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

  int res = *max_element(dp.begin(), dp.end());
  cout << res << endl;

  return 0;
}
