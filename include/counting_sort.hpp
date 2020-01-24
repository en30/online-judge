/**
 * @brief Counting Sort, Bucket Sort. O(N + R)
 * @param A ソートする対象
 * @param R 最大の値
 * @return ソート済み配列
 */
vector<int> countingSort(const vector<int>& A, int R) {
  vector<int> count(R + 2, 0);
  for (int e : A) ++count[e + 1];
  for (int i = 0; i < R; ++i) count[i + 1] += count[i];

  int N = A.size();
  vector<int> res(N);
  for (int i = 0; i < N; ++i) res[count[A[i]]++] = A[i];

  return res;
}