#include <bits/stdc++.h>
#include "../include/template"

string s;

int main() {
  cin >> s;
  map<string, int> m;
  m["SUN"] = 7;
  m["MON"] = 6;
  m["TUE"] = 5;
  m["WED"] = 4;
  m["THU"] = 3;
  m["FRI"] = 2;
  m["SAT"] = 1;
  cout << m[s] << endl;
  return 0;
}
