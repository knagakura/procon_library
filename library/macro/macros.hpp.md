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


# :heavy_check_mark: Macro

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#66f6181bcb4cff4cd38fbc804a036db6">template</a>
* <a href="{{ site.github.repository_url }}/blob/master/macro/macros.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-31 04:16:41+09:00




## Required by

* :heavy_check_mark: <a href="../data_structure/bit.cpp.html">BIT(Binary Indexed Tree)</a>
* :heavy_check_mark: <a href="../data_structure/inversion-num.cpp.html">転倒数(The Number of Inversion)</a>
* :heavy_check_mark: <a href="../data_structure/lazy-segment-tree-raq.cpp.html">遅延評価セグメント木(Lazy Segment Tree) 区間加算</a>
* :heavy_check_mark: <a href="../data_structure/segment-tree.cpp.html">抽象化セグ木</a>
* :heavy_check_mark: <a href="../data_structure/unionfind.hpp.html">素集合データ構造(UnionFind Tree)</a>
* :heavy_check_mark: <a href="../graph/shortest_path/bfs.hpp.html">graph/shortest_path/bfs.hpp</a>
* :heavy_check_mark: <a href="../graph/shortest_path/dijkstra.cpp.html">Dijkstra法</a>
* :heavy_check_mark: <a href="../graph/shortest_path/dijkstra.hpp.html">graph/shortest_path/dijkstra.hpp</a>
* :heavy_check_mark: <a href="../graph/shortest_path/warshall-floyd.cpp.html">graph/shortest_path/warshall-floyd.cpp</a>
* :heavy_check_mark: <a href="../graph/template.hpp.html">Graph Class</a>
* :heavy_check_mark: <a href="../math/bell-number-2.cpp.html">ベル数(Bell Number) slower ver.</a>
* :heavy_check_mark: <a href="../math/bell-number.cpp.html">ベル数(Bell Number) faster ver.</a>
* :heavy_check_mark: <a href="../math/comb.hpp.html">組み合わせ(Combination)</a>
* :heavy_check_mark: <a href="../math/mint.hpp.html">合同算術(Modular Arithmetic)</a>
* :heavy_check_mark: <a href="../math/partition-number.cpp.html">分割数(Partition Number)</a>
* :heavy_check_mark: <a href="../math/sieve_of_eratosthenes.cpp.html">エラトステネスの篩(Sieve of Eratosthenes)</a>
* :heavy_check_mark: <a href="../math/stiring-number-second-dp.cpp.html">第二種スターリング数(Stirling-Number-Of-The-Second-Kind) DP ver.</a>
* :heavy_check_mark: <a href="../math/stiring-number-second.cpp.html">第二種スターリング数(Stirling-Number-Of-The-Second-Kind)</a>
* :heavy_check_mark: <a href="../tree/lca.cpp.html">最小共通祖先/LCA(Lowest Common Acestor)</a>
* :heavy_check_mark: <a href="../tree/template.cpp.html">Tree Class</a>
* :heavy_check_mark: <a href="../tree/tree-diameter-height.cpp.html">木の直径と高さ/Diameter and Height of a Tree (全方位木DP/Rerooting ver.)</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/example/example.test.cpp.html">example(二分探索)</a>
* :heavy_check_mark: <a href="../../verify/test/ALDS1_11_C.test.cpp.html">test/ALDS1_11_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/ALDS1_1_B.test.cpp.html">test/ALDS1_1_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/ALDS1_1_C.test.cpp.html">test/ALDS1_1_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/ALDS1_3_A.test.cpp.html">test/ALDS1_3_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/ALDS1_5_D.test.cpp.html">test/ALDS1_5_D.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/ALDS1_7_A.test.cpp.html">test/ALDS1_7_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/ALDS1_7_B.test.cpp.html">test/ALDS1_7_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_A.test.cpp.html">玉区別する、箱区別する、制限なし($k^{n}$)</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_B.test.cpp.html">玉区別する、箱区別する、1個以内(${}_k P _n$)</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_C.test.cpp.html">玉区別する、箱区別する、1個以上($\sum_{i=0}^{k} (-1)^{i} {}_{k} C _{i} (k-i)^n$)</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_D.test.cpp.html">玉区別しない、箱区別する、制限なし(${}_n H _k$)</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_E.test.cpp.html">玉区別しない、箱区別する、1個以内(${}_k C _n$)</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_F.test.cpp.html">玉区別しない、箱区別する、1個以上(${}_{n-k} H _k$)</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_G.test.cpp.html">玉区別する、箱区別しない、制限なし(ベル数($O(\min(N,K)log N$))</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_G_2.test.cpp.html">玉区別する、箱区別しない、制限なし(ベル数($O(NKlog N$))</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_H.test.cpp.html">玉区別する、箱区別しない、1個以内(0 or 1)</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_I.test.cpp.html">玉区別する、箱区別しない、1個以上(第二種スターリング数)</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_I_DP.test.cpp.html">玉区別する、箱区別しない、1個以上(第二種スターリング数(DP))</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_J.test.cpp.html">玉区別しない、箱区別しない、制限なし(分割数$P(n,k)$)</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_K.test.cpp.html">玉区別しない、箱区別しない、1個以内(0 or 1)</a>
* :heavy_check_mark: <a href="../../verify/test/DPL_5_L.test.cpp.html">玉区別しない、箱区別しない、1個以上(分割数$P(n-k,k)$)</a>
* :heavy_check_mark: <a href="../../verify/test/DSL_1_A.test.cpp.html">test/DSL_1_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/DSL_2_A.test.cpp.html">test/DSL_2_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/DSL_2_B.test.cpp.html">test/DSL_2_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/DSL_2_B_2.test.cpp.html">test/DSL_2_B_2.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/DSL_2_G.test.cpp.html">test/DSL_2_G.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/GRL_1_A.test.cpp.html">test/GRL_1_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/GRL_1_A_2.test.cpp.html">test/GRL_1_A_2.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/GRL_1_C.test.cpp.html">test/GRL_1_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/GRL_5_A.test.cpp.html">test/GRL_5_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/GRL_5_B.test.cpp.html">test/GRL_5_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/GRL_5_C.test.cpp.html">test/GRL_5_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/union_find_tree.yosupo.test.cpp.html">test/union_find_tree.yosupo.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef MACROS_HPP
#define MACROS_HPP

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

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

