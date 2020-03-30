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


# :heavy_check_mark: 玉区別しない、箱区別しない、1個以上(分割数$P(n-k,k)$)

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#9f51e9d7dafe7714c7b48d2b6a166473">写像12相</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/DPL_5_L.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-30 20:40:57+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_L">https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_L</a>


## Depends on

* :heavy_check_mark: <a href="../../library/macro/macros.hpp.html">macro/macros.hpp</a>
* :heavy_check_mark: <a href="../../library/math/mint.hpp.html">math/mint.hpp</a>
* :heavy_check_mark: <a href="../../library/math/partition-number.cpp.html">分割数($0(NK))</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_L"
#include "../macro/macros.hpp"
#include "../math/mint.hpp"
#include "../math/partition-number.cpp"
/*
@title 玉区別しない、箱区別しない、1個以上(分割数$P(n-k,k)$)
@category 写像12相
*/
int main(){
    int n, k;
    cin >> n >> k;
    Partition<mint> Par(n, k);
    cout << Par.get(n-k, k) << endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/DPL_5_L.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_L"
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

#line 1 "math/partition-number.cpp"


#line 5 "math/partition-number.cpp"

/*
@title 分割数($0(NK))
@docs ../docs/math/partition-number.md
*/

template<typename T = mint>
struct Partition{
    int N,K;
    vector<vector<mint>> Par;
    Partition(int _N, int _K):N(_N),K(_K),Par(N+1, vector<mint>(K+1, 0)){
        build();
    }
    void build(){
        for(int k = 0; k <= K;k++)Par[0][k] = 1;
        for(int n = 1; n <= N; n++){
            for(int k = 1; k <= K; k++){
                if(k-1 >= 0)Par[n][k] += Par[n][k-1];
                if(n-k >= 0)Par[n][k] += Par[n-k][k];
            }
        }
    }
    mint get(int n, int k){
        if(n < 0 || k < 0)return 0;
        return Par[n][k];
    }
};


#line 5 "test/DPL_5_L.test.cpp"
/*
@title 玉区別しない、箱区別しない、1個以上(分割数$P(n-k,k)$)
@category 写像12相
*/
int main(){
    int n, k;
    cin >> n >> k;
    Partition<mint> Par(n, k);
    cout << Par.get(n-k, k) << endl;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

