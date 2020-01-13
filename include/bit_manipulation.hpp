int first_fixed_size_subset(int n, int k) { return (1 << k) - 1; }

int next_fixed_size_subset(int n, int k, int& s) {
  int x = s & -s, y = s + x;
  s = (((s & ~y) / x) >> 1) | y;
  if (s >= (1 << n)) return 0;
  return s;
}
