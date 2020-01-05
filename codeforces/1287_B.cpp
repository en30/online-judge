#include <bits/stdc++.h>
#include "../include/template"

int n, k;

int main() {
  cin >> n >> k;
  vector<string> cards(n);
  rep(i, n) cin >> cards[i];

  sort(all(cards));

  int ans = 0;
  rep(i, n) for (int j = i + 1; j < n; ++j) {
    string s = "";
    rep(l, k) {
      if (cards[i][l] == cards[j][l])
        s += cards[i][l];
      else
        s += char('S' + 'E' + 'T' - cards[i][l] - cards[j][l]);
    }
    auto it = cards.begin() + j + 1;
    ans += distance(lower_bound(it, cards.end(), s),
                    upper_bound(it, cards.end(), s));
  }

  cout << ans << endl;
  return 0;
}
