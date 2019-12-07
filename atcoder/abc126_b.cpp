#include <bits/stdc++.h>
#include "../include/template"

const vector<string> ans = {"AMBIGUOUS", "MMYY", "YYMM", "NA"};

string S;

bool shouldYY(string s) {
  return !((s[0] == '0' && s[1] != '0') || (s[0] == '1' && (s[1] <= '2')));
}

int main() {
  cin >> S;
  int x = shouldYY(S.substr(2, 2)) + (shouldYY(S.substr(0, 2)) << 1);

  cout << ans[x] << endl;
  return 0;
}
