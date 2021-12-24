
template<int mod> struct Modular {
  int val;
  Modular<mod>(const Modular<mod>& x) {
    val = x.val;
  }
  template<typename T> Modular(T x) {
    if (x >= -mod && x < mod) {
      val = x;
    } else {
      val = x % mod;
    } 
    if (val < 0) {
      val += mod;
    }
  }
  int& operator()() { return val; }
  Modular<mod>& operator +=(Modular<mod> x) {
    if ((val += x.val) >= mod) {
      val -= mod;
    }
    return *this;
  }
  Modular<mod>& operator -=(Modular<mod> x) {
    if ((val -= x.val) < 0) {
      val += mod;
    }
    return *this;
  }
  Modular<mod>& operator *=(Modular<mod> x) {
    val = int((1LL * val * x.val) % mod);
    return *this;
  }

  Modular<mod> inv(Modular<mod> x) {
    int p = mod - 2;
    Modular res = 1;
    while (p > 0) {
      if (p & 1) {
        res *= x;
      }
      x *= x;
      p >>= 1;
    }
    return res;
  } 

  Modular<mod>& operator /=(Modular<mod> x) {
    return *this *= inv(x);
  }

  template<typename O> Modular<mod>& operator += (O x) {
    return *this += Modular<mod>(x);
  }
  template<typename O> Modular<mod>& operator -= (O x) {
    return *this -= Modular<mod>(x);
  }
  template<typename O> Modular<mod>& operator *= (O x) {
    return *this *= Modular<mod>(x);
  }
  template<typename O> Modular<mod>& operator /= (O x) {
    return *this /= Modular<mod>(x);
  }
};

template<int T> Modular<T> operator +(Modular<T> x, Modular<T> y) {
  return x += y;
}
template<int T> Modular<T> operator -(Modular<T> x, Modular<T> y) {
  return x -= y;
}
template<int T> Modular<T> operator *(Modular<T> x, Modular<T> y) {
  return x *= y;
}
template<int T> Modular<T> operator /(Modular<T> x, Modular<T> y) {
  return x /= y;
}

template<int T, typename O> Modular<T> operator +(Modular<T> x, O y) {
  return x + Modular<T>(y);
}
template<int T, typename O> Modular<T> operator -(Modular<T> x, O y) {
  return x - Modular<T>(y);
}
template<int T, typename O> Modular<T> operator *(Modular<T> x, O y) {
  return x * Modular<T>(y);
}
template<int T, typename O> Modular<T> operator /(Modular<T> x, O y) {
  return x / Modular<T>(y);
}

template<int T> string to_string(Modular<T> x) {
  return to_string(x());
}

template<int T, typename O> Modular<T> power(Modular<T> x, O p) {
  Modular<T> res = 1;
  while (p > 0) {
    if (p & 1) {
      res *= x;  
    }
    x *= x;
    p >>= 1;
  }
  return res;
constexpr int md = @@HERE@@;}
using Mint = Modular<md>;
