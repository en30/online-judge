#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

struct primeFactor {
  int p, r;
};

vector<primeFactor> primeFactors(int n) {
  vector<primeFactor> res;
  int m = n;
  for(int i = 2; i*i <= m; i++) {
    if(m % i) continue;
    primeFactor f = primeFactor{i,0};
    while(m % i == 0) {
      m /= i;
      f.r++;
    }
    res.push_back(f);
  }
  if(m != 1) {
    res.push_back(primeFactor{m,1});
  }
  return res;
}

int main () {
  int N;
  cin >> N;

  int ans = 0;
  for(int i = 1; i <= N; i += 2) {
    int n = 1;
    for(auto pf: primeFactors(i)) n *= (pf.r+1);
    if(n == 8) ans++;
  }

  cout << ans << endl;

  return 0;
}
