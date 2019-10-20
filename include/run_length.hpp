template <typename T>
class RunLength {
 public:
  struct Element {
    T value;
    int count;
  };

  static vector<Element> compress(auto& s) {
    vector<Element> res;
    if (s.size() == 0) return res;

    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (i == s.size() - 1 || s[i] != s[i + 1]) {
        res.push_back(Element{s[i], cnt});
        cnt = 1;
      } else {
        ++cnt;
      }
    }

    return res;
  }
};
