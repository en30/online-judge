#include <bits/stdc++.h>
#include "../include/template"
#include "../include/lis.hpp"

struct Box {
  int i, w, h;
};

int main() {
  int N;
  cin >> N;

  vector<Box> B(N);
  int W = 0;
  rep(i, N) {
    B[i].i = i;
    cin >> B[i].w >> B[i].h;
    chmax(W, B[i].w);
  }

  sort(all(B), [](const Box& a, const Box& b) {
    return a.h == b.h ? a.w > b.w : a.h < b.h;
  });

  vector<int> w(N);
  rep(i, N) w[i] = B[i].w;
  cout << lis(w, true) << endl;

  return 0;
}
