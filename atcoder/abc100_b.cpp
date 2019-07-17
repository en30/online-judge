#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int D, N;

int main () {
  cin >> D >> N;

  int k = 1;
  rep(i,D) k *= 100;

  cout << k * N + (N == 100 ? k : 0) << endl;

  return 0;
}
