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


# :heavy_check_mark: ベル数($O(\min(N,K) \log N)$)

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/bell-number.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-30 16:55:27+09:00




### 計算量
$O(\min(N,K) \log N)$

### 説明
[第二種スターリング数](https://knagakura.github.io/procon_library/library/math/stiring-number-second.cpp.html)を$S(n, k)$とすると、ベル数は

$B(n, k) := \sum_{j = 0}^{k}S(n, j)$

と表される。第二種スターリング数を「ちょうど$k$個のグループに分ける場合の数」だと考えると、ベル数は「$k$個以下のグループに分ける場合の数」と考えることができるからである。

愚直に計算すると$O(NK\log N)$かかる計算量が、以下のような式変形により、第二種スターリング数の直接計算と同等の計算量に落ちる。

$B(n, k)$

$= \sum_{j = 0}^{k}S(n, j)$

$=  \sum_{j = 0}^{k} \frac{1}{j!}\sum_{i=0}^{j} (-1)^{j-i} {}_{j} C _{i} {i}^n$

$= \sum_{i = 0}^{k} \frac{1}{j!}\sum_{j=i}^{k} (-1)^{j-i} {}_{j} C _{i} {i}^n$　　　　($\sum$の入れ替え。$i \leq j$が保たれていればよい)

$= \sum_{i = 0}^{k} \sum_{j=i}^{k} \frac{1}{j!}(-1)^{j-i} {}_{j} C _{i} {i}^n$

$= \sum_{i = 0}^{k} \sum_{j=i}^{k} \frac{1}{j!}(-1)^{j-i} \frac{j!}{i!(j-i)!} {i}^n$

$= \sum_{i = 0}^{k} \sum_{j=i}^{k}  \frac{(-1)^{j-i}}{i!(j-i)!} {i}^n$　　 

$ = \sum_{i = 0}^{k} \sum_{j=0}^{k-i} \frac{(-1)^{j}}{i!{j}!} {i}^n$　　　　($j' = j - i$と変数変換し、$j' = j$と置き換える)


$ = \sum_{i = 0}^{k}\frac{{i}^n}{i!} \sum_{j=0}^{k-i} \frac{(-1)^{j}}{{j}!}$



$\sum_{j=0}^{k-i} \frac{(-1)^{j}}{{j}!}$については前処理により$O(K)$で計算可能なので、ベル数$B(n, k)$を$k$個の足し算で計算できる。$i^n$に$O(\log N)$だけかかるので、全体として$O(\min(N,K) \log N)$である。


## Depends on

* :heavy_check_mark: <a href="../macro/macros.hpp.html">macro/macros.hpp</a>
* :heavy_check_mark: <a href="comb.hpp.html">組み合わせ(Combination)</a>
* :heavy_check_mark: <a href="mint.hpp.html">math/mint.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/DPL_5_G.test.cpp.html">玉区別する、箱区別しない、制限なし(ベル数($O(\min(N,K)log N$))</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef BELL_NUMBER_CPP
#define BELL_NUMBER_CPP
#include "../macro/macros.hpp"
#include "mint.hpp"
#include "comb.hpp"

/*
@title ベル数($O(\min(N,K) \log N)$)
@docs ../docs/math/bell-number.md
*/

template<typename T>
mint bell_number(T n, T k){
    combination C(max(n, k)+1);
    vector<mint> temp(k+1);
    temp[0] = 1;
    for(int j = 1; j <= k;j++){
        temp[j] = temp[j-1] + ((j & 1) ? -C.ifact[j]: C.ifact[j]);
    }
    mint res = 0;
    for(int i = 0; i <= k;i++){
        res += mint(i).modpow(n) * C.ifact[i] * temp[k-i];
    }
    return res;
}

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/bell-number.cpp"


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

#line 6 "math/bell-number.cpp"

/*
@title ベル数($O(\min(N,K) \log N)$)
@docs ../docs/math/bell-number.md
*/

template<typename T>
mint bell_number(T n, T k){
    combination C(max(n, k)+1);
    vector<mint> temp(k+1);
    temp[0] = 1;
    for(int j = 1; j <= k;j++){
        temp[j] = temp[j-1] + ((j & 1) ? -C.ifact[j]: C.ifact[j]);
    }
    mint res = 0;
    for(int i = 0; i <= k;i++){
        res += mint(i).modpow(n) * C.ifact[i] * temp[k-i];
    }
    return res;
}



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

