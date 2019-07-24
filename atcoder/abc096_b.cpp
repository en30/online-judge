#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int A, B, C, K;

int solve(int a, int b, int c, int k) {
  if(k == 0) return a + b + c;
  return max(solve(2*a, b, c, k -1), max(solve(a, 2*b, c, k - 1), solve(a, b, 2*c, k - 1)));
}

int main () {
  cin >> A >> B >> C >> K;

  cout << solve(A, B, C, K) << endl;
  return 0;
}
