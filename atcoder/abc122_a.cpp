#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

char ans(char c) {
  if(c == 'A') return 'T';
  if(c == 'T') return 'A';
  if(c == 'C') return 'G';
  if(c == 'G') return 'C';
}

int main () {
  char c;
  cin >> c;
  cout << ans(c) << endl;

  return 0;
}
