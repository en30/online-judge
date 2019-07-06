#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

string S;

bool ok() {
  if(S[0] != 'A') return false;

  int ic = -1;
  for(int i = 2; i <= S.size() - 2; i++){
    if(S[i] == 'C') {
      if(ic != -1) return false;
      ic = i;
    }
  }
  if(ic == -1) return false;

  for(int i = 1; i < S.size(); i++) {
    if(i == ic) continue;
    if(!(S[i] >= 'a' && S[i] <= 'z')) return false;
  }

  return true;
}

int main () {

  cin >> S;

  cout << (ok() ? "AC" : "WA") << endl;
  return 0;
}
