#pragma once

template <typename T>
struct WeightedEdge {
  int from, to;
  T _weight;
  WeightedEdge(){};
  WeightedEdge(int from, int to, T weight)
      : from(from), to(to), _weight(weight) {}

  void scanFrom(std::istream& strm, int base = 1) {
    strm >> from >> to >> _weight;
    if (base == 1) --from, --to;
  }

  T weight() { return _weight; }

  WeightedEdge reverse() const { return WeightedEdge(to, from, _weight); }
};

template <typename T>
inline std::istream& operator>>(std::istream& strm, WeightedEdge<T>& t) {
  t.scanFrom(strm);
  return strm;
}
