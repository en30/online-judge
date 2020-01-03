#include <bits/stdc++.h>
#include "../include/template"

string S;

struct Word {
  string raw, down;
};

int main() {
  cin >> S;

  vector<Word> words;

  bool in = false;
  for (char c : S) {
    if ('A' <= c && c <= 'Z') {
      if (!in) words.push_back(Word{});
      words[words.size() - 1].raw += c;
      words[words.size() - 1].down += (c - 'A') + 'a';
      in = !in;
    } else {
      words[words.size() - 1].raw += c;
      words[words.size() - 1].down += c;
    }
  }

  sort(all(words),
       [&](const Word& a, const Word& b) { return a.down < b.down; });

  rep(i, words.size()) { cout << words[i].raw; }
  cout << endl;

  return 0;
}
