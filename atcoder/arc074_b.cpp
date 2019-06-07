#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

int N;
const int MAX_N = 1e5;
ll a[3*MAX_N];
ll L[MAX_N+1];
ll R[MAX_N+1];

int main () {
  cin >> N;
  REP(i,3*N) cin >> a[i];

  priority_queue<int, vector<int>, greater<int> > ql;
  priority_queue<int> qr;

  REP(i,N) {
    L[N-1] += a[i];
    ql.push(a[i]);

    R[2*N-1] += a[i + 2*N];
    qr.push(a[i + 2*N]);
  }

  for(int i = N; i < 2*N; i++) {
    int diff = a[i] - ql.top();
    if(diff > 0) {
      L[i] = L[i-1] + diff;
      ql.pop();
      ql.push(a[i]);
    } else {
      L[i] = L[i-1];
    }
  }

  for(int i = 2*N-2; i >= N - 1; i--) {
    int diff = a[i+1] - qr.top();
    if(diff < 0) {
      R[i] = R[i+1] + diff;
      qr.pop();
      qr.push(a[i+1]);
    } else {
      R[i] = R[i+1];
    }
  }

  ll res = L[N-1] - R[N -1];
  for(int i = N - 1; i < 2*N; i++) res = max(res, L[i] - R[i]);

  cout << res << endl;
  return 0;
}
