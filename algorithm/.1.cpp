#include <bits/stdc++.h>
using namespace std;

vector<int> computeNext(const string& pattern) {
  int n = pattern.size();
  vector<int> next(n, 0);

  for (int i = 1, j = 0; i < n; ++i) {
    while (j > 0 && pattern[i] != pattern[j]) {
      j = next[j - 1];
    }
    if (pattern[i] == pattern[j]) {
      j++;
    }
    next[i] = j;
  }
  return next;
}

int kmpSearch(const string& text, const string& pattern) {
  int n = text.size();
  int m = pattern.size();
  vector<int> next = computeNext(pattern);

  for (int i = 0, j = 0; i < n; ++i) {
    while (j > 0 && text[i] != pattern[j]) {
      j = next[j - 1];
    }
    if (text[i] == pattern[j]) {
      j++;
    }
    if (j == m) {
      return i - m + 1;
    }
  }
  return -1;
}

int main() {
  return 0;
}