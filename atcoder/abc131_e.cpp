#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

struct edge {
  int u, v;
};

int main () {
  int N, K;
  cin >> N >> K;

  int rest = (N-1)*(N-2)/2 - K;
  if(rest < 0) {
    cout << "-1" << endl;
    return 0;
  }

  vector<edge> e;
  for(int i = 2; i <= N; i++) {
    e.push_back(edge{1,i});
  }

  int i = 2;
  int j = 3;
  while(rest > 0) {
    if(j > N) {
      i++;
      j = i + 1;
    }
    e.push_back(edge{i,j});
    j++;
    rest--;
  }

  int M = e.size();
  cout << M << endl;
  rep(i,M) {
    cout << e[i].u << " " << e[i].v << endl;
  }

  return 0;
}
