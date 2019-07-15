#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int N;
  cin >> N;

  vector<int> A(N);
  rep(i,N) cin >> A[i];

  int ans = 0;
  for(int i = 0; i < N - 1; i++){
    for(int j = i+1; j < N; j++) {
      ans = max(ans, abs(A[i]-A[j]));
    }
  }

  cout << ans << endl;

  return 0;
}
