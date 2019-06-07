#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

class Dictionary {
  vector<int> S;
  const int NIL = -1;
  const int M = 1046527;

  int charCode(char &c) {
    if(c == 'A') return 1;
    if(c == 'C') return 2;
    if(c == 'G') return 3;
    if(c == 'T') return 4;
  }

  int encode(string v) {
    int i = 1;
    int key = 0;
    for(char&c : v) {
      key += charCode(c) * i;
      i *= 5;
    }
    return key;
  }

  int h1(int key) {
    return key % M;
  }

  int h2(int key) {
    return 1 + (key % (M - 1));
  }

  int hash(int key, int i) {
    return (h1(key) + i * (ll) h2(key)) % M;
  }

public:

  Dictionary() {
    S = vector<int>(M, NIL);
  }

  bool insert(string v) {
    int key = encode(v);
    int i = 0;
    while(true) {
      int h = hash(key, i);
      if(S[h] == key) return false;
      if(S[h] == NIL) {
        S[h] = key;
        return true;
      }
      i++;
    }
  }

  bool find(string v) {
    int key = encode(v);
    int i = 0;
    while(true) {
      int h = hash(key, i);
      if(S[h] == NIL) return false;
      if(S[h] == key) return true;
      i++;
    }
  }
};

int main () {
  int n;
  cin >> n;
  Dictionary dic;
  string command, value;
  rep(i,n) {
    cin >> command >> value;
    if(command == "insert") {
      dic.insert(value);
    } else {
      cout << (dic.find(value) ? "yes" : "no") << endl;
    }
  }

  return 0;
}
