#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int N;
vector<int> A;

int main () {
  cin >> N;
  A.resize(N);
  vector<int> B(N);
  rep(i,N) {
    cin >> A[i];
    B[i] = A[i];
  }

  sort(B.begin(), B.end());
  rep(i,N) {
    if(A[i] == B[N-1]) {
      cout << B[N-2] << endl;
    } else {
      cout << B[N-1] << endl;
    }
  }

  return 0;
}
