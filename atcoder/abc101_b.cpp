#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int N;
  cin >> N;
  int S = 0;
  for(int d = 1e9, M = N; d >= 1; d/=10) {
    S += M / d;
    M = M % d;
  }
  cout << (N % S ? "No" : "Yes") << endl;
  return 0;
}
