#include <bits/stdc++.h>
#include "../include/template"

struct Student {
  int i, a;
};

int main() {
  int N;
  cin >> N;
  vector<Student> S(N);
  rep(i, N) {
    cin >> S[i].a;
    S[i].i = i;
  }
  sort(S.rbegin(), S.rend(),
       [](const Student& a, const Student& b) { return a.a < b.a; });
  rep(i, N) cout << S[i].i + 1 << endl;
  return 0;
}
