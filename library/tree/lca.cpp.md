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


# :heavy_check_mark: 最小共通祖先/LCA(Lowest Common Acestor)

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/lca.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 17:06:20+09:00




## Depends on

* :question: <a href="../macro/macros.hpp.html">macro/macros.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/GRL_5_C.test.cpp.html">test/GRL_5_C.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
@title 最小共通祖先/LCA(Lowest Common Acestor)
*/
#include "../macro/macros.hpp"

class LCA{
  public:
    int N;
    int bitlen = 1;
    vector<vector<int>> edges;
    vector<int> d; //depth
    vector<vector<int>> anc; // bitlen * N
    // the number of vertexs
    LCA(int _N):N(_N){
        init(N);
    }
    LCA(int _N, vector< vector<int>> G):N(_N){
        init(N, G);
    }
    void init(int n){
        while((1 << bitlen) < n){
            bitlen++;
        }
        d.assign(n, 0);
        anc.assign(bitlen, vector<int>(n,-1));
        dfs();
    }
    void init(int n, vector<vector<int>> G){
        edges = G;
        init(n);
    }
    void dfs(int v = 0, int p = -1){
        anc[0][v] = p;
        for(int i = 0; i+1 < bitlen; ++i){
            anc[i+1][v] = (anc[i][v] >= 0) ? anc[i][anc[i][v]] : -1;
        }
        for(auto nv: edges[v]) if(nv != p){
            d[nv] = d[v]+1;
            dfs(nv, v);
        }
    }
    int lca(int u, int v){
        if(d[u] > d[v]) swap(u, v);
        for(int i = 0; i < bitlen;i++){
            if((d[v] - d[u]) & (1<<i)){
                v = anc[i][v];
            }
        }
        if(u == v) return u;
        for(int i = bitlen-1; i >= 0;i--){
            if(anc[i][u] != anc[i][v]){
                u = anc[i][u];
                v = anc[i][v];
            }
        }
        return anc[0][u];
    }
    int calc_dist(int u, int v) {
		int l = lca(u, v);
		return d[u] + d[v] - d[l] * 2;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tree/lca.cpp"
/*
@title 最小共通祖先/LCA(Lowest Common Acestor)
*/
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


#line 5 "tree/lca.cpp"

class LCA{
  public:
    int N;
    int bitlen = 1;
    vector<vector<int>> edges;
    vector<int> d; //depth
    vector<vector<int>> anc; // bitlen * N
    // the number of vertexs
    LCA(int _N):N(_N){
        init(N);
    }
    LCA(int _N, vector< vector<int>> G):N(_N){
        init(N, G);
    }
    void init(int n){
        while((1 << bitlen) < n){
            bitlen++;
        }
        d.assign(n, 0);
        anc.assign(bitlen, vector<int>(n,-1));
        dfs();
    }
    void init(int n, vector<vector<int>> G){
        edges = G;
        init(n);
    }
    void dfs(int v = 0, int p = -1){
        anc[0][v] = p;
        for(int i = 0; i+1 < bitlen; ++i){
            anc[i+1][v] = (anc[i][v] >= 0) ? anc[i][anc[i][v]] : -1;
        }
        for(auto nv: edges[v]) if(nv != p){
            d[nv] = d[v]+1;
            dfs(nv, v);
        }
    }
    int lca(int u, int v){
        if(d[u] > d[v]) swap(u, v);
        for(int i = 0; i < bitlen;i++){
            if((d[v] - d[u]) & (1<<i)){
                v = anc[i][v];
            }
        }
        if(u == v) return u;
        for(int i = bitlen-1; i >= 0;i--){
            if(anc[i][u] != anc[i][v]){
                u = anc[i][u];
                v = anc[i][v];
            }
        }
        return anc[0][u];
    }
    int calc_dist(int u, int v) {
		int l = lca(u, v);
		return d[u] + d[v] - d[l] * 2;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

