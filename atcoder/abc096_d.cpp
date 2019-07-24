#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N;

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
  cin >> N;

  sieve(55555);

  for(int i = 0, j = 0; i < N; i++, j++) {
    while(prime[j] % 5 != 1) j++;
    cout << (i == 0 ? "" : " ") << prime[j];
  }
  cout << endl;

  return 0;
}
