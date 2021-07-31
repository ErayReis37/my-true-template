template<typename T> struct ItSegTree {
  int n;
  vector<T> tree;
  ItSegTree() { } 
  ItSegTree(int _n) : n(_n) {
    tree.resize((n << 1));
  }

  template<typename... M> void modify(int p, M... x) {
    assert(p >= 0 && p < n);
    p += n;
    tree[p].modify(x...);
    while (p > 1) {
      tree[(p >> 1)] = tree[p] + tree[p ^ 1];
      p >>= 1;
    }
  }

  T get(int l, int r) {
    assert(l >= 0 && l <= r && r < n);
    l += n;
    r += n + 1;
    T res;
    while (l < r) {
      if (l & 1) {
        res = res + tree[l];
        ++l; 
      }
      if (r & 1) {
       --r;
       res = res + tree[r];
      }
      l >>= 1;
      r >>= 1;
    }
    return res;
  }
};

