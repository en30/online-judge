#include <bits/stdc++.h>
#include "../include/template"

int N;

vector<string> board;

int boardQuality(vector<string>& board) {
  int n = board.size();
  assert(n == board[0].size());
  set<int> s;
  rep(i, n) {
    set<char> t1, t2;
    rep(j, n) {
      if (board[i][j] != '.') t1.insert(board[i][j]);
      if (board[j][i] != '.') t2.insert(board[j][i]);
    }
    s.insert(t1.size());
    s.insert(t2.size());
    if (s.size() > 1) return -1;
  }
  return *(s.begin());
}

bool printBoard(int n) {
  assert(board.size() == n && board[0].size() == n);

  int q = boardQuality(board);
  if (q == -1) return false;

  printf("(n, k) = (%d, %d)\n", n, q);
  rep(i, n) {
    rep(j, n) cout << board[i][j];
    cout << endl;
  }
  return true;
}

bool searchBoard(int i, int n, int k, int v, int h) {
  if (v == 0 && h == 0) return printBoard(n);
  if (i == n * n) return false;

  int r = i / n;
  int c = i % n;
  if (v > 0 && r + 1 < n && board[r][c] == '.' && board[r + 1][c] == '.') {
    board[r][c] = 'a' + v + h;
    board[r + 1][c] = 'a' + v + h;
    if (searchBoard(i + 1, n, k, v - 1, h)) return true;
    board[r][c] = '.';
    board[r + 1][c] = '.';
  }
  if (h > 0 && c + 1 < n && board[r][c] == '.' && board[r][c + 1] == '.') {
    board[r][c] = 'a' + v + h;
    board[r][c + 1] = 'a' + v + h;
    if (searchBoard(i + 1, n, k, v, h - 1)) return true;
    board[r][c] = '.';
    board[r][c + 1] = '.';
  }
  return searchBoard(i + 1, n, k, v, h);
}

void search() {
  for (int n = 3; n < 7; ++n) {
    printf("searching n = %d...\n", n);
    for (int k = 1; k <= n; ++k) {
      for (int m = 1; 4 * m <= n * n; ++m) {
        if (k * n != 3 * m) continue;
        board = vector<string>(n, string(n, '.'));
        searchBoard(0, n, k, m, m);
      }
    }
  }
}

unordered_map<int, vector<string>> tile = {
    {3, {"c..", "c..", ".bb"}},
    {4, {"ihgg", "ihff", "eedc", "bbdc"}},
    {5,
     {
         "kji..",
         "kji..",
         "hggff",
         "h.edd",
         "ccebb",
     }},
    {6,
     {
         "mlk...",
         "mlk...",
         "j.iihh",
         "jgff..",
         ".g.edd",
         "cc.ebb",
     }},
    {7,
     {
         "aa..hi.",
         "....hin",
         "....jkn",
         "....jkl",
         "bbee..l",
         "ccff..m",
         "..ddggm",
     }}};

void validateTiles() {
  for (auto it = tile.begin(); it != tile.end(); it++) {
    if (boardQuality(it->second) == -1) {
      printf("Invalid: %d\n", it->first);
      exit(1);
    }
  }
}

int main() {
  cin >> N;

  if (N == 2) {
    cout << -1 << endl;
    return 0;
  }

  if (N == 3) {
    for (auto& line : tile[3]) cout << line << endl;
    return 0;
  }

  int y = (N % 4);
  if (y != 0) y += 4;
  int x = (N - y) / 4;

  rep(i, x) {
    rep(j, 4) {
      cout << string(i * 4, '.');
      cout << tile[4][j];
      cout << string(N - 4 * (i + 1), '.');
      cout << endl;
    }
  }
  rep(j, y) {
    cout << string(N - y, '.');
    cout << tile[y][j];
    cout << endl;
  }

  return 0;
}
