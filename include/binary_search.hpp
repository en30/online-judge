#pragma once

/**
 * @brief predicateを満たす最大の値mを返す。[l,r)内では[l,
 * m]はpredicateがtrueを返し、[m+1,
 * r)ではpredicateがfalseを返さなければならない。
 * @tparam T
 * @param l
 * @param r
 * @param predicate
 * @return
 */
template <typename T>
T integer_partition_point(T l, T r, const function<bool(T)>& predicate) {
  while (r - l > 1) {
    T m = (l + r) / 2;
    if (predicate(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  return l;
}
