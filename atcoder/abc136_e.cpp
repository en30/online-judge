#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, K;
vector<int> A;

bool ok(ll i) {
  ll k = 0;

  priority_queue<ll> pq;
  rep(j,N) {
    k += A[j] % i;
    pq.push(A[j]%i);
  }

  while(k != 0) {
    ll p = pq.top();
    pq.pop();
    k -= i;
    pq.push(p-i);
  }

  ll s = 0;
  while(!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    s += abs(p);
  }
  return s/2 <= K;
}

int main () {
  cin >> N >> K;
  A.resize(N);

  ll M = 0;
  rep(i,N) {
    cin >> A[i];
    M += A[i];
  }

  vector<ll> R;
  for(ll i = 1; i <= sqrt(M); i++) {
    if(M % i == 0) {
      R.push_back(i);
      R.push_back(M/i);
    }
  }
  sort(all(R));

  for(int i = R.size() - 1; i >= 0; i--) {
    if(ok(R[i])) {
      cout << R[i] << endl;
      return 0;
    }
  }

  return 0;
}
