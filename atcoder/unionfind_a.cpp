#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

const int N = 1e5;
const int Q = 2*1e5;

int P[N];
int R[N];

int getUnion(int n) {
  if(P[n] == n) return n;
  int res = getUnion(P[n]);
  P[n] = res;
  return res;
}

void unite(int a, int b) {
  a = getUnion(a);
  b = getUnion(b);
  if(a == b) return;

  if(R[a] > R[b]) {
    P[b] = getUnion(a);
  } else {
    P[a] = getUnion(b);
    if(R[a] == R[b]) R[b]++;
  }
}

int same(int a, int b) {
  return getUnion(a) == getUnion(b);
}

int main () {
  int n, q;
  cin >> n >> q;
  REP(i,n) {
    P[i] = i;
    R[i] = 1;
  }

  REP(i,q) {
    int p, a, b;
    cin >> p >> a >> b;
    if(p) {
      cout << (same(a,b) ? "Yes" : "No") << endl;
    } else {
      unite(a, b);
    }
  }
  return 0;
}
