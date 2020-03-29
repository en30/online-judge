#pragma once

template <typename T, T IDENTITY = numeric_limits<T>::min()>
struct MaxMonoid {
  T v;
  bool operator==(const MaxMonoid& that) const { return v == that.v; }
  bool operator!=(const MaxMonoid& that) const { return !(*(this) == that); }

  static MaxMonoid identity() { return IDENTITY; }

  MaxMonoid(T v = identity()) : v(v) {}
  MaxMonoid& operator+=(const MaxMonoid& that) {
    v = max(v, that.v);
    return *this;
  }
  MaxMonoid operator+(const MaxMonoid& that) const {
    return MaxMonoid(*this) += that;
  }
};
