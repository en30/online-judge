#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int N, A, B;
  cin >> N >> A >> B;
  cout << min(N*A, B) << endl;
  return 0;
}
