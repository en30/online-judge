#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

ll N;
int main () {
  cin >> N;

  cout << N*(N-1)/2 << endl;

  return 0;
}
