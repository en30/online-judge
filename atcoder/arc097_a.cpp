#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

string s;
int K;
set<string> subs;

int main () {
  cin >> s >> K;
  int N = s.size();

  for(int i = 0; i < N; i++) {
    for(int j = 1; j <= K && i + j - 1 < N; j++) {
      subs.insert(s.substr(i, j));
      while(subs.size() > K) subs.erase(prev(subs.end()));
    }
  }

  cout << *(subs.rbegin()) << endl;

  return 0;
}
