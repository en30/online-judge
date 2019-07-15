#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  ll N;
  cin >> N;

  cout << (N % 2 ?  N*2 : N) << endl;
  return 0;
}
