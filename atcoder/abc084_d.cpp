#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

vector<int> prime;
vector<bool> isPrime;
void sieve(int n) {
  isPrime.resize(n+1, true);
  isPrime[0] = isPrime[1] = false;
  for(int i = 2; i <= n; i++) {
    if(isPrime[i]) {
      prime.push_back(i);
      for(int j = 2*i; j <= n; j += i) isPrime[j] = false;
    }
  }
}

int main () {
  int N = 1e5;
  sieve(N);
  vector<int> S(N+1, 0);
  rep(i,N) {
    S[i+1] = S[i] + (((i+1) & 1) && isPrime[i+1] && isPrime[(i+2)/2]);
  }

  int Q;
  cin >> Q;
  while(Q--) {
    int l, r;
    cin >> l >> r;
    cout << S[r] - S[l-1] << endl;
  }

  return 0;
}
