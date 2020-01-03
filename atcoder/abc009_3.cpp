#include <bits/stdc++.h>
#include "../include/template"

int N, K;

string S;

int main() {
  cin >> N >> K;
  cin >> S;

  const int R = 26;
  vector<int> rest(R, 0);
  rep(i, N) rest[S[i] - 'a']++;

  // (i, N)
  auto minCost = [&](int i, int j) {
    vector<int> freq(R, 0);
    for (int l = i + 1; l < N; ++l) {
      freq[S[l] - 'a']++;
    }
    int c = (N - 1 - i);
    rep(d, R) c -= min(freq[d], rest[d] - (j == d));
    c += (S[i] - 'a' != j);
    return c;
  };

  string ans;
  int cost = 0;
  rep(i, N) {
    rep(j, R) {
      if (!rest[j] || cost + minCost(i, j) > K) continue;
      ans += 'a' + j;
      cost += (S[i] != ans[i]);
      rest[j]--;
      break;
    }
  }

  cout << ans << endl;
  return 0;
}
