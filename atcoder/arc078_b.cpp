#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

vector<vector<int>> al;

void dist(int r, int i, vector<int> &d) {
  d[i] = r;
  for(int n : al[i]) {
    if(d[n] != -1) continue;
    dist(r+1, n, d);
  }
}

int main () {
  int n;
  cin >> n;

  al = vector<vector<int>>(n, vector<int>(0));
  rep(i,n-1) {
    int s,t;
    scanf("%d %d", &s, &t);
    al[s-1].push_back(t-1);
    al[t-1].push_back(s-1);
  }

  vector<int> fd(n, -1), sd(n, -1);
  fd[0] = 0;
  sd[n-1] = 0;
  dist(0, 0, fd);
  dist(0, n-1, sd);

  int fs = 0, ss = 0;
  rep(i,n) {
    if(fd[i] <= sd[i]) {
      fs++;
    } else {
      ss++;
    }
  }

  if(fs > ss) {
    printf("Fennec\n");
  } else {
    printf("Snuke\n");
  }

  return 0;
}
