#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int A, B ,K;

int main () {
  cin >> A >> B >> K;

  rep(i,K) if(A + i <= B) cout << A + i << endl;
  rep(i,K) {
    int m = B - (K - 1 - i);
    if(m > A + K - 1) cout << m << endl;
  }

  return 0;
}
