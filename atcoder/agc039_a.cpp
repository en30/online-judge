#include <bits/stdc++.h>
#include "../include/template"

string S;
ll K;

struct Block {
  char c;
  int n;
};

int main() {
  cin >> S >> K;

  vector<Block> B;
  int i = 0;
  while (i < S.size()) {
    char c = S[i++];
    int n = 1;
    while (i < S.size() && S[i] == c) {
      ++n;
      ++i;
    }
    B.push_back(Block{S[i - 1], n});
  }

  ll ans = 0;
  if (B.size() == 1) {
    ans = (B[0].n * K) / 2;
  } else if (B[0].c == B[B.size() - 1].c) {
    for (int i = 1; i < B.size() - 1; ++i) {
      ans += B[i].n / 2;
    }
    ans *= K;
    ans += ((B[0].n + B[B.size() - 1].n) / 2) * (K - 1);
    ans += B[0].n / 2 + B[B.size() - 1].n / 2;
  } else {
    ans = 0;
    for (auto& b : B) ans += b.n / 2;
    ans *= K;
  }

  cout << ans << endl;
  return 0;
}
