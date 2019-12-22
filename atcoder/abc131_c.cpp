#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#include "../include/gcd.hpp"

int main() {
  ll A, B, C, D;
  cin >> A >> B >> C >> D;

  ll E = C * D / gcd(C, D);
  cout << B - A + 1 - (B / C - (A + C - 1) / C + 1) -
              (B / D - (A + D - 1) / D + 1) + (B / E - (A + E - 1) / E + 1)
       << endl;
  return 0;
}
