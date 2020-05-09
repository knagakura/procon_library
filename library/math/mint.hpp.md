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


# :heavy_check_mark: 合同算術(Modular Arithmetic)

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/mint.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-31 04:16:41+09:00




## Depends on

* :heavy_check_mark: <a href="../macro/macros.hpp.html">Macro</a>


## Required by

* :heavy_check_mark: <a href="bell-number-2.cpp.html">ベル数(Bell Number) slower ver.</a>
* :heavy_check_mark: <a href="bell-number.cpp.html">ベル数(Bell Number) faster ver.</a>
* :heavy_check_mark: <a href="comb.hpp.html">組み合わせ(Combination)</a>
* :heavy_check_mark: <a href="partition-number.cpp.html">分割数(Partition Number)</a>
* :heavy_check_mark: <a href="stiring-number-second-dp.cpp.html">第二種スターリング数(Stirling-Number-Of-The-Second-Kind) DP ver.</a>
* :heavy_check_mark: <a href="stiring-number-second.cpp.html">第二種スターリング数(Stirling-Number-Of-The-Second-Kind)</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/DPL_5_A.test.cpp.html">玉区別する、箱区別する、制限なし($k^{n}$)</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_B.test.cpp.html">玉区別する、箱区別する、1個以内(${}_k P _n$)</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_C.test.cpp.html">玉区別する、箱区別する、1個以上($\sum_{i=0}^{k} (-1)^{i} {}_{k} C _{i} (k-i)^n$)</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_D.test.cpp.html">玉区別しない、箱区別する、制限なし(${}_n H _k$)</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_E.test.cpp.html">玉区別しない、箱区別する、1個以内(${}_k C _n$)</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_F.test.cpp.html">玉区別しない、箱区別する、1個以上(${}_{n-k} H _k$)</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_G.test.cpp.html">玉区別する、箱区別しない、制限なし(ベル数($O(\min(N,K)log N$))</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_G_2.test.cpp.html">玉区別する、箱区別しない、制限なし(ベル数($O(NKlog N$))</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_I.test.cpp.html">玉区別する、箱区別しない、1個以上(第二種スターリング数)</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_I_DP.test.cpp.html">玉区別する、箱区別しない、1個以上(第二種スターリング数(DP))</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_J.test.cpp.html">玉区別しない、箱区別しない、制限なし(分割数$P(n,k)$)</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_L.test.cpp.html">玉区別しない、箱区別しない、1個以上(分割数$P(n-k,k)$)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef MINT_HPP
#define MINT_HPP

#include "../macro/macros.hpp"
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
#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/mint.hpp"



#line 1 "macro/macros.hpp"



/*
@title Macro
@category template
*/
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


```
{% endraw %}

<a href="../../index.html">Back to top page</a>

