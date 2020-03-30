---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: 第二種スターリング数(Stirling-Number-Of-The-Second-Kind)

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#9f51e9d7dafe7714c7b48d2b6a166473">写像12相</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/stiring-number-second.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-30 21:00:16+09:00




### 定義
$S(n, k) $

$:= \frac{1}{k!}\sum_{i=0}^{k} (-1)^{i} {}_{k} C _{i} (k-i)^n$

$i$ を $k - i$に変換して

$= \frac{1}{k!}\sum_{i=0}^{k} (-1)^{k-i} {}_{k} C _{i} {i}^n$ 　　$({}_k C _{k-i} = {}_k C _ i)$を用いた

### 計算量
$O(Klog{N})$

### 説明
#### 問題
$n$個の区別できる玉を $k$個の区別できない箱に入れるとき、その入れ方の総数を求めてください。

ただし、玉の入れ方は以下のルールにしたがいます：
- どの玉も、必ずいずれかの箱に入れる。
- どの箱にも$1$つ以上の玉を入れる。

#### 方針
簡単のため、箱の区別もあるものとして問題を考え、最後に$k!$で割ることにする（これで玉も箱も区別ができ、扱いやすくなる）。

$k$個の箱全てに1つ以上のボールが入っているということは、「玉をちょうど$k$グループに分ける」問題と捉えることができる。つまり、「空のグループを1つも作ってはいけない」ということである。
「1つも作ってはいけない」というのは考えにくいが、よくある余事象の考え方になれば、空のグループが少なくとも$1$個ある場合の数を、全事象から引けばよいということがわかる。

余事象は包除原理を用いればよい。空のグループ数で場合わけして、包除原理を適用すると少なくとも1個空の分け方が求めることができる。

### 参考
- [写像12相」を総整理！ 〜 数え上げ問題の学びの宝庫 〜](https://qiita.com/drken/items/f2ea4b58b0d21621bd51#4-%E3%82%B9%E3%82%BF%E3%83%BC%E3%83%AA%E3%83%B3%E3%82%B0%E6%95%B0)




## Depends on

* :heavy_check_mark: <a href="../macro/macros.hpp.html">macro/macros.hpp</a>
* :heavy_check_mark: <a href="comb.hpp.html">組み合わせ(Combination)</a>
* :heavy_check_mark: <a href="mint.hpp.html">合同算術(Modular Arithmetic)</a>


## Required by

* :heavy_check_mark: <a href="bell-number-2.cpp.html">ベル数(Bell Number) slower ver.</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/DPL_5_G_2.test.cpp.html">玉区別する、箱区別しない、制限なし(ベル数($O(NKlog N$))</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_I.test.cpp.html">玉区別する、箱区別しない、1個以上(第二種スターリング数)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef STIRING_NUMBER_SECOND_CPP
#define STIRING_NUMBER_SECOND_CPP
#include "../macro/macros.hpp"
#include "mint.hpp"
#include "comb.hpp"

/*
@title 第二種スターリング数(Stirling-Number-Of-The-Second-Kind)
@category 写像12相
@docs ../docs/math/stiring-number-second.md
*/
mint stirling_number_second(int n, int k){
    combination C(k+1);
    mint res = 0;
    for(int i = 0; i <= k;i++){
        mint x = C.Comb(k, i) * mint(i).modpow(n);
        res += ((k-i) & 1) ? -x:x;
    }
    res *= C.ifact[k];
    return res;
}

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/stiring-number-second.cpp"


#line 1 "macro/macros.hpp"



#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;

template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << "{" <<p.first << ", " << p.second << "}";
  return os;
}
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;

const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";


#line 1 "math/mint.hpp"



#line 5 "math/mint.hpp"
/*
@title 合同算術(Modular Arithmetic)
*/
struct mint {
    long long x;
    mint(long long _x=0):x((_x%MOD+MOD)%MOD){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += MOD-a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint modpow(long long t) const {
        if (!t) return 1;
        mint a = modpow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime MOD
    mint inv() const {
        return modpow(MOD-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
    friend std::ostream& operator<<(std::ostream& os, const mint& a){
        os << a.x;
        return os;
    }
};

#line 1 "math/comb.hpp"


#line 5 "math/comb.hpp"

/*
@title 組み合わせ(Combination)
*/
struct combination {
    vector<mint> fact, ifact;
    combination(int n):fact(n+1),ifact(n+1) {
        assert(n < MOD);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
    }
    mint Comb(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n]*ifact[k]*ifact[n-k];
    }
    mint H(int n, int m){
        return Comb(n + m - 1, n);
    }
    //nPk
    mint Perm(int n, int k){
        if (k < 0 || n < k) return 0;
        return fact[n]*ifact[n-k];
    }
};

#line 6 "math/stiring-number-second.cpp"

/*
@title 第二種スターリング数(Stirling-Number-Of-The-Second-Kind)
@category 写像12相
@docs ../docs/math/stiring-number-second.md
*/
mint stirling_number_second(int n, int k){
    combination C(k+1);
    mint res = 0;
    for(int i = 0; i <= k;i++){
        mint x = C.Comb(k, i) * mint(i).modpow(n);
        res += ((k-i) & 1) ? -x:x;
    }
    res *= C.ifact[k];
    return res;
}



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

