template <typename T>
int lis(const vector<T>& a, bool strict) {
  const int N = a.size();
  const T INF = numeric_limits<T>::max();
  vector<T> dp(N, INF);
  for (int i = 0; i < N; ++i) {
    typename vector<T>::iterator it;
    if (strict) {
      it = lower_bound(dp.begin(), dp.end(), a[i]);
    } else {
      it = upper_bound(dp.begin(), dp.end(), a[i]);
    }
    *it = a[i];
  }
  return distance(dp.begin(), lower_bound(dp.begin(), dp.end(), INF));
}
