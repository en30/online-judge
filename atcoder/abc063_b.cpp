#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int found[40] = {0};
int main () {
  char c;
  while(scanf("%c", &c) != EOF) {
    if(found[c] == 1) {
      cout << "no" << endl;
      return 0;
    }
    found[c] = 1;
  }
  cout << "yes" << endl;
  return 0;
}
