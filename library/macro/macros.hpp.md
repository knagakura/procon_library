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


# :heavy_check_mark: macro/macros.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#eb320f0c2b6a25b48ca861a120eea902">macro</a>
* <a href="{{ site.github.repository_url }}/blob/master/macro/macros.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 17:06:20+09:00




## Required by

* :heavy_check_mark: <a href="../data_structure/stack.hpp.html">stack</a>
* :heavy_check_mark: <a href="../data_structure/unionfind.hpp.html">UnionFind Tree</a>
* :heavy_check_mark: <a href="../graph/shortest_path/bfs.hpp.html">graph/shortest_path/bfs.hpp</a>
* :heavy_check_mark: <a href="../graph/shortest_path/dijkstra.cpp.html">Dijkstra法</a>
* :heavy_check_mark: <a href="../graph/shortest_path/dijkstra.hpp.html">graph/shortest_path/dijkstra.hpp</a>
* :heavy_check_mark: <a href="../graph/shortest_path/warshall-floyd.cpp.html">graph/shortest_path/warshall-floyd.cpp</a>
* :heavy_check_mark: <a href="../graph/template.hpp.html">graph/template.hpp</a>
* :warning: <a href="../test/ALDS1_1_B.cpp.html">test/ALDS1_1_B.cpp</a>
* :heavy_check_mark: <a href="../tree/lca.cpp.html">最小共通祖先/LCA(Lowest Common Acestor)</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/example/example.test.cpp.html">example(二分探索)</a>
* :heavy_check_mark: <a href="../../verify/test/ALDS1_11_C.test.cpp.html">test/ALDS1_11_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/ALDS1_3_A.test.cpp.html">test/ALDS1_3_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/DSL_1_A.test.cpp.html">test/DSL_1_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/GRL_1_A.test.cpp.html">test/GRL_1_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/GRL_1_A_2.test.cpp.html">test/GRL_1_A_2.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/GRL_1_C.test.cpp.html">test/GRL_1_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/GRL_5_C.test.cpp.html">test/GRL_5_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/union_find_tree.yosupo.test.cpp.html">test/union_find_tree.yosupo.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef MACROS_HPP
#define MACROS_HPP

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

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

