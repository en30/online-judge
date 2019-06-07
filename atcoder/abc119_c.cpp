#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int N, A, B, C;
vector<int> l;

const int INF = 1e9;

int solve(int i, int a, int b, int c) {
  if(i == N) {
    return min(a, min(b, c)) == 0 ? INF : abs(A-a) + abs(B-b) + abs(C-c) - 30;
  }

  int ans = INF;
  ans = min(ans, solve(i+1, a, b, c));
  ans = min(ans, solve(i+1, a + l[i], b, c) + 10);
  ans = min(ans, solve(i+1, a, b + l[i], c) + 10);
  ans = min(ans, solve(i+1, a, b, c + l[i]) + 10);
  return ans;
}

int main () {
  cin >> N >> A >> B >> C;
  l = vector<int>(N);
  rep(i,N) cin >> l[i];

  cout << solve(0, 0, 0, 0) << endl;

  return 0;
}
