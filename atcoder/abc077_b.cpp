#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N;

int main () {
  cin >> N;

  int i = 1;
  while((i+1)*(i+1) <= N) i++;

  cout << i*i << endl;
  return 0;
}
