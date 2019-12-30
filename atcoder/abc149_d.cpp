#include <bits/stdc++.h>
#include "../include/template"

int N, K, R, S, P;
string T;

int main() {
  cin >> N >> K >> R >> S >> P >> T;

  unordered_map<char, int> score;
  score['r'] = P;
  score['s'] = R;
  score['p'] = S;
  unordered_map<char, char> enemy;
  enemy['r'] = 'p';
  enemy['p'] = 's';
  enemy['s'] = 'r';

  ll ans = 0;
  rep(i, K) {
    char h = '?';
    for (int j = i; j < N; j += K) {
      if (h == enemy[T[j]]) {
        if (j + K < N) h = T[j + K];
      } else {
        h = enemy[T[j]];
        ans += score[T[j]];
      }
    }
  }

  cout << ans << endl;

  return 0;
}
