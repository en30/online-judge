#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

typedef pair<ll, ll> res;

int N;
vector<ll> A, S;

// [a, b), [b, c)
ll sumdiff(int a, int b, int c) {
  return abs(S[c] - 2 * S[b] + S[a]);
}

int main () {
  cin >> N;

  A.resize(N), S.resize(N+1, 0);
  rep(i,N) {
    cin >> A[i];
    S[i+1] = S[i] + A[i];
  }

  ll ans = 1e15;
  int p = 1, r = 3;
  for(int q = 2; q < N - 1; q++) {
    while(sumdiff(q, r+1, N) < sumdiff(q, r, N)) r++;
    while(sumdiff(0, p+1, q) < sumdiff(0, p, q)) p++;
    vector<ll> B = {S[p]-S[0], S[q]-S[p], S[r]-S[q], S[N]-S[r]};
    sort(B.begin(), B.end());
    ans = min(ans, B[3] - B[0]);
  }

  cout << ans << endl;
  return 0;
}
