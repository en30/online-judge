#include <bits/stdc++.h>
#include "../include/template"
#include "../include/run_length.hpp"

int N;
int main() {
  cin >> N;

  string s;
  cin >> s;

  cout << RunLength<char>::compress(s).size() << endl;
  return 0;
}
