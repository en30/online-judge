class Convolution {
  using C = complex<double>;
  const C ZERO = C(0.0, 0.0);
  vector<int> conv;

  vector<C> dft(const vector<C>& x) {
    int n = x.size();

    if (n == 1) return x;

    assert(n % 2 == 0);

    vector<C> even(n / 2), odd(n / 2);
    for (int i = 0; i < n / 2; ++i) {
      even[i] = x[2 * i];
      odd[i] = x[2 * i + 1];
    }

    vector<C> q = dft(even), r = dft(odd);
    vector<C> y(n);
    for (int i = 0; i < n / 2; ++i) {
      double ith = -2.0 * i * M_PI / n;
      C wi(cos(ith), sin(ith));
      y[i] = q[i] + wi * r[i];
      y[i + n / 2] = q[i] - wi * r[i];
    }

    return y;
  }

  vector<C> inverseDft(const vector<C>& x) {
    int n = x.size();
    vector<C> y(n);
    for (int i = 0; i < n; ++i) {
      y[i] = conj(x[i]);
    }

    y = dft(y);

    for (int i = 0; i < n; ++i) {
      y[i] = conj(y[i]);
      y[i] /= n;
    }

    return y;
  }

 public:
  Convolution(const vector<int>& a, const vector<int>& b) {
    int n = a.size(), m = b.size();
    int l = 1;
    while (n + m >= l) l *= 2;

    vector<C> ca(l, ZERO), cb(l, ZERO);
    for (int i = 0; i < n; ++i) ca[i] = C(a[i], 0.0);
    for (int i = 0; i < m; ++i) cb[i] = C(b[i], 0.0);
    vector<C> fa = dft(ca), fb = dft(cb);
    vector<C> fc(l);
    for (int i = 0; i < l; ++i) {
      fc[i] = fa[i] * fb[i];
    }

    vector<C> c = inverseDft(fc);
    conv.resize(l);
    for (int i = 0; i < l; ++i) {
      conv[i] = round(c[i].real());
    }
  }

  int operator[](int i) { return conv[i]; }

  vector<int> toVector() { return conv; }
};
