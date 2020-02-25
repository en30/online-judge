#pragma once

/**
 * @brief O(log max(a,b))
 * @param a
 * @param b
 * @return
 */
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

long long lcm(long long a, long long b) { return a * b / gcd(a, b); }

/**
 * @brief a*x + b*y = gcd(a,b)を満たすx,y, gcd(a,b)を求める。O(log max(a,b))
 * @param a
 * @param b
 * @param x
 * @param y
 * @return
 */
long long extgcd(long long a, long long b, long long& x, long long& y) {
  long long d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}
