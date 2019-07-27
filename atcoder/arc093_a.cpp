#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N;
vector<int> A;

int main () {
  cin >> N;
  A.resize(N+2, 0);

  rep(i,N) cin >> A[i+1];

  ll S = 0;
  rep(i,N+1) {
    S += abs(A[i] - A[i+1]);
  }

  for(int i = 1; i <= N; i++) {
    cout << S - abs(A[i-1] - A[i]) - abs(A[i+1] - A[i]) + abs(A[i+1] - A[i-1]) << endl;
  }

  return 0;
}
