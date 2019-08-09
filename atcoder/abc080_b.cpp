#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N;

int f(int x) {
  if(x < 10) return x;
  return x % 10 + f(x/10);
}

bool harshad(int x) {
  return x % f(x) == 0;
}

int main () {
  cin >> N;

  cout << (harshad(N) ? "Yes" : "No") << endl;
  return 0;
}
