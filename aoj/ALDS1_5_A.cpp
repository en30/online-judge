#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

bool creatable(int i, int s, int M, vector<int> &A) {
  if(i == A.size()) return false;
  if(s + A[i] == M) return true;
  return creatable(i+1, s, M, A) || creatable(i+1, s+A[i], M, A);
}

int main () {
  int n, q;
  cin >> n;
  vector<int> A(n);
  rep(i,n) cin >> A[i];
  cin >> q;
  rep(i,q) {
    int M;
    cin >> M;
    cout << (creatable(0, 0, M, A) ? "yes" : "no") << endl;
  }
  return 0;
}
