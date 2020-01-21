#include <bits/stdc++.h>
#include "../include/template"

int N;
int query(int a, int b) {
  assert(1 <= a <= N);
  assert(1 <= b <= N);
  cout << "? " << a << " " << b << endl;
  int dist;
  cin >> dist;
  return dist;
}

int main () {
  cin >> N;

  int j = 1;
  int d = 0;
  for(int i = 2; i <= N; ++i) {
    int cd = query(1, i);
    if(chmax(d, cd)) j = i;
  }
  for(int i = 1; i <= N; ++i) {
    if(i == j) continue;
    int cd = query(j, i);
    chmax(d, cd);
  }

  cout << "! " << d << endl;

  return 0;
}
