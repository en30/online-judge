#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int main () {
  int X, A, B;
  cin >> X >> A >> B;
  cout << (X - A) % B << endl;
  return 0;
}
