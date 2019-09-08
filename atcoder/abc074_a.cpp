#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, A;
int main () {
  cin >> N >> A;
  cout << (N*N-A) << endl;
  return 0;
}
