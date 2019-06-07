#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

bool isPrime(int e) {
  for(int i = 2; i <= (int) sqrt(e); i++) {
    if(e % i == 0) return false;
  }
  return true;
}

int main () {
  int n;
  cin >> n;
  int c = 0;
  for(int i = 0; i < n; i++) {
    int e;
    cin >> e;
    c += isPrime(e);
  }
  cout << c << endl;
  return 0;
}
