#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

string S;

int main () {
  cin >> S;

  int N = S.size();
  int ans = N / 2;
  char c = S[N/2];
  while(ans <= N && S[ans] == S[N-1-ans] && S[ans] == c) ans++;
  cout << ans << endl;

  return 0;
}
