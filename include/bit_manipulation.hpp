/**
 * @brief next_fixed_size_subsetに渡す最初の値を返す
 * @param n 集合のサイズ
 * @param k 部分集合のサイズ
 * @return
 */
int first_fixed_size_subset(int n, int k) { return (1 << k) - 1; }

/**
 * @brief
 * サイズnの集合の、サイズkの部分集合を列挙する。次の値がない場合は0を返す。
 * @param n 集合のサイズ
 * @param k 部分集合のサイズ
 * @param s 部分集合のint表現
 * @return
 */
int next_fixed_size_subset(int n, int k, int& s) {
  if (k == 0) return 0;

  int x = s & -s, y = s + x;
  s = (((s & ~y) / x) >> 1) | y;
  if (s >= (1 << n)) return 0;
  return s;
}
