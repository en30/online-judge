#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string s;
  cin >> s;
  if (s == "Sunny") {
    cout << "Cloudy";
  } else if (s == "Cloudy") {
    cout << "Rainy";
  } else if (s == "Rainy") {
    cout << "Sunny";
  }
  cout << endl;

  return 0;
}
