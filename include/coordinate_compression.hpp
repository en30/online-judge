#pragma once

template <typename T>
class CoordinateCompression {
  map<T, int> compressed;
  map<int, T> reverse;

 public:
  /**
   * @brief O(NlogN)
   * @param a
   */
  CoordinateCompression(const vector<T>& a) {
    for (T v : a) compressed[v];
    int i = 0;
    for (auto& p : compressed) {
      p.second = i;
      reverse[i] = p.first;
      ++i;
    }
  }

  /**
   * @brief 座標から圧縮済みの座標を得る O(logN)
   * @param v
   * @return
   */
  int compress(T v) { return compressed[v]; }

  /**
   * @brief 圧縮済みの座標からもとの座標に戻す O(logN)
   * @param i
   * @return
   */
  T uncompress(int i) { return reverse[i]; }

  int size() { return compressed.size(); }
};
