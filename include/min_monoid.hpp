#pragma once

template <typename T, T IDENTITY = numeric_limits<T>::max()>
struct MinMonoid {
  T v;
  bool operator==(const MinMonoid& that) const { return v == that.v; }
  bool operator!=(const MinMonoid& that) const { return !(*(this) == that); }

  static MinMonoid identity() { return IDENTITY; }

  MinMonoid(T v = identity()) : v(v) {}
  MinMonoid& operator+=(const MinMonoid& that) {
    v = min(v, that.v);
    return *this;
  }
  MinMonoid operator+(const MinMonoid& that) const {
    return MinMonoid(*this) += that;
  }
};
