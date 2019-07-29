#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, Y;

int main () {
  cin >> N >> Y;

  for(int i = 0; i <= N; i++) {
    for(int j = 0; j + i <= N; j++) {
      int k = N - i - j;
      if(10000*i + 5000*j + 1000*k == Y) {
        printf("%d %d %d\n", i, j, k);
        return 0;
      }
    }
  }

  cout << "-1 -1 -1" << endl;

  return 0;
}
