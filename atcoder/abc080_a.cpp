#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, A, B;
int main () {
  cin >> N >> A >> B;

  cout << min(A*N, B) << endl;
  return 0;
}
