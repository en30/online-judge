#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int N;
  cin >> N;

  vector<int> A(N);
  rep(i,N) cin >> A[i];
  sort(A.begin(), A.end());
  cout << A[N-1] - A[0] << endl;

  return 0;
}
