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


# :heavy_check_mark: test/ALDS1_1_C.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/ALDS1_1_C.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-31 16:47:02+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C">https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C</a>


## Depends on

* :heavy_check_mark: <a href="../../library/macro/macros.hpp.html">Macro</a>
* :heavy_check_mark: <a href="../../library/math/sieve_of_eratosthenes.cpp.html">エラトステネスの篩(Sieve of Eratosthenes)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C"
#include "../math/sieve_of_eratosthenes.cpp"

int main(){
    vector<bool> is_prime = sieve(100100100);
    int n;
    cin >> n;
    int ans = 0;
    while(n--){
        int x;
        cin >> x;
        ans += is_prime[x];
    }
    cout << ans << endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/ALDS1_1_C.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C"
#line 1 "math/sieve_of_eratosthenes.cpp"


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


#line 4 "math/sieve_of_eratosthenes.cpp"

/*
@title エラトステネスの篩(Sieve of Eratosthenes)
@category math
@brief 計算量$O($NloglogN$)$

*/
template<typename T>
vector<bool> sieve(T x){
    vector<bool> is_prime(x + 1, true);
    if(x >= 0)is_prime[0] = false;
    if(x >= 1)is_prime[1] = false;
    for(T i = 2; i * i <= x;i++){
        if(!is_prime[i])continue;
        for(T j = i + i; j <= x;j+=i){
            is_prime[j] = false;
        }
    }
    return is_prime;
}

#line 3 "test/ALDS1_1_C.test.cpp"

int main(){
    vector<bool> is_prime = sieve(100100100);
    int n;
    cin >> n;
    int ans = 0;
    while(n--){
        int x;
        cin >> x;
        ans += is_prime[x];
    }
    cout << ans << endl;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
