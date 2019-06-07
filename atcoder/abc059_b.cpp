#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

string G = "GREATER";
string L = "LESS";

string compare(string &a, string &b) {
  int la = a.size(), lb = b.size();
  if(la > lb) return G;
  if(la < lb) return L;

  for(int i = 0; i < la; i++) {
    if(a[i] > b[i]) return G;
    if(a[i] <b[i]) return L;
  }
  return "EQUAL";
}
int main () {
  string a, b;
  cin >> a >> b;
  cout << compare(a, b) << endl;
  return 0;
}
