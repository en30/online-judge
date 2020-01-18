#include <bits/stdc++.h>
#include "../include/template"
#include "../include/bit_manipulation.hpp"

struct Card {
  int G, Y;
};

struct Elem {
  bool green;
  int v;
};

int main() {
  int N;
  cin >> N;

  vector<Card> C(N);
  rep(i, N) {
    if (i % 2 == 0) {
      cin >> C[i].G;
    } else {
      cin >> C[i].Y;
    }
  }
  rep(i, N) {
    if (i % 2 == 0) {
      cin >> C[i].Y;
    } else {
      cin >> C[i].G;
    }
  }

  int nGreen = (N + 1) / 2;
  int green = first_fixed_size_subset(N, nGreen);

  int ans = 1e9;

  do {
    int cost = 0;

    vector<Elem> sorting(N);
    rep(i, N) {
      if ((green >> i) & 1) {
        sorting[i] = Elem{true, C[i].G};
      } else {
        sorting[i] = Elem{false, C[i].Y};
      }
    }

    bool flag = true;
    for (int i = 0; flag; i++) {
      flag = false;
      for (int j = N - 1; j >= i + 1; --j) {
        if (sorting[j].v < sorting[j - 1].v) {
          swap(sorting[j], sorting[j - 1]);
          flag = 1;
          ++cost;
        }
      }
    }

    rep(i, N) {
      if (i % 2 == 0 && !sorting[i].green) {
        int j = i + 1;
        while (j < N && sorting[i].v == sorting[j].v && !sorting[j].green) ++j;
        if (j == N || sorting[i].v != sorting[j].v) goto end;
        for (int k = j; k > i; --k) {
          swap(sorting[k], sorting[k - 1]);
          ++cost;
        }
      }
      if (i % 2 == 1 && sorting[i].green) {
        int j = i + 1;
        while (j < N && sorting[i].v == sorting[j].v && sorting[j].green) ++j;
        if (j == N || sorting[i].v != sorting[j].v) goto end;
        for (int k = j; k > i; --k) {
          swap(sorting[k], sorting[k - 1]);
          ++cost;
        }
      }
    }

    ans = min(ans, cost);
  end:;
  } while (next_fixed_size_subset(N, nGreen, green));

  cout << (ans == 1e9 ? -1 : ans) << endl;

  return 0;
}
