#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

string S, T;

int main () {
  cin >> S >> T;

  vector<string> cands;

  for(int i = 0; i < S.size(); i++) {
    string s = string(S);
    int j;
    for(j = 0; j < T.size() && i + j < S.size(); j++) {
      if(S[i+j] != '?' && S[i+j] != T[j]) break;
      s[i+j] = T[j];
    }
    if(j == T.size()) {
      for(int k = 0; k < S.size(); k++) {
        if(s[k] == '?') s[k] = 'a';
      }
      cands.push_back(s);
    }
  }
  sort(all(cands));

  cout << (cands.size() == 0 ? "UNRESTORABLE" : cands[0]) << endl;

  return 0;
}
