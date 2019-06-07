#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n;
  cin >> n;
  vector<int> t(2402, 0);
  rep(i,n)  {
    int s, e;
    scanf("%04d-%04d", &s, &e);
    s = s - (s % 5);
    if(e % 5 != 0) e += 5 - (e % 5);
    if(e % 100 == 60) e += 100 - 60;
    t[s] += 1;
    t[e+1] += -1;
  }

  bool inRange = false;
  for(int i = 0; i < 2402; i++) {
    if(i != 0) t[i] += t[i-1];
    if(!inRange && t[i] > 0) {
      printf("%04d-", i);
      inRange = true;
    } else if(inRange && t[i] == 0) {
      printf("%04d\n", i-1);
      inRange = false;
    }
  }

  return 0;
}
