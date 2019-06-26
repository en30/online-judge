#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

struct edge {
  int u, v, w;
};

int main () {
  int L;
  cin >> L;

  int l = 0;
  while((1<<(l+1)) <= L) l++;
  if(L == 1) {
    printf("2 1\n1 2 0\n");
    return 0;
  }

  int N = l+1;
  vector<edge> edges;
  for(int i = 1; i <= l; i++) {
    edges.push_back(edge{i,i+1,0});
    edges.push_back(edge{i,i+1,(1<<(l-i))});
  }

  int k = L - (1<<l);
  int w = (1<<l);
  for(int i = 20; i >= 0; i--) {
    if((k>>i) & 1) {
      edges.push_back(edge{1,N-i,w});
      w += 1<<i;
    }
  }

  printf("%d %d\n", N, edges.size());
  for(auto e: edges) {
    printf("%d %d %d\n", e.u, e.v, e.w);
  }

  return 0;
}
