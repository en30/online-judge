#include <bits/stdc++.h>
#include "../include/template"
#include "../include/run_length.hpp"

int main () {
  string s;
  cin >> s;
  auto res = RunLength<char>::compress(s);
  for(auto e: res) {
    cout << e.value << e.count;
  }
  cout << endl;
  return 0;
}
