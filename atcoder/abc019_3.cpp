#include <bits/stdc++.h>
#include "../include/template"

int main () {
  int N;
  cin >> N;

  int ans = 0;
  unordered_map<int,int> m;
  rep(i,N) {
    int a;
    cin >> a;
    while(a % 2 == 0) a /= 2;
    m[a] = 1;
  }
  cout << m.size() << endl;
  return 0;
}
