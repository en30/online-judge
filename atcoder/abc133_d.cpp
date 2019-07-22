#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int N;
vector<int> A;

int main () {
  cin >> N;
  A.resize(N);
  rep(i,N) cin >> A[i];

  int X = 0;
  for(int i = 0; i < N; i++) {
    if(i % 2 == 0) {
      X += A[i];
    } else {
      X -= A[i];
    }
  }

  cout << X;
  for(int i = 0; i < N - 1; i++) {
    X = 2*A[i] - X;
    printf(" %d", X);
  }
  cout << endl;
  return 0;
}
