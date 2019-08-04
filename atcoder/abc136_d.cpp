#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

string S;
vector<int> ans;

int main () {
  cin >> S;
  int N = S.size();
  ans.resize(N, 0);

  int i = 0;
  while(i < N) {
    int j = i;
    while(S[j] == 'R') j++;

    while(i < j) {
      if((j - i) % 2 == 0) {
        ans[j]++;
      } else {
        ans[j-1]++;
      }
      i++;
    }

    while(i < N && S[i] == 'L') {
      if((j - i) % 2 == 0) {
        ans[j]++;
      } else {
        ans[j-1]++;
      }
      i++;
    }
  }

  rep(i,N) {
    if(i != 0) cout << " ";
    cout << ans[i];
  }
  cout << endl;

  return 0;
}
