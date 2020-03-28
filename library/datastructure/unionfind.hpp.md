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


# :warning: UnionFind Tree

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/unionfind.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-28 17:49:27+09:00





## 使い方講座
1. まず、main関数内で `UnionFind uni(N);`と呼び出します（これでUnionFind木のuniちゃんが呼び出されます）。
2. uniちゃんの中には、NodeがN個あり、それぞれの親とそれが属する集合の数（size）が定義されています。
    - 二つのNode xとy が同じ集合に属するか確認するとき

        `uni.same(x, y);`
    - あるNode x が含まれる集合の大きさを知りたいとき

        `uni.size(x);`
    - 二つのNode xとyを同じ集合に属させたいとき

        `uni.unite(x, y);`
    - あるNode xの根を知りたいとき

        `uni.root(x);`

## UnionFind木が出題された問題
1. [D-Decayed Bridges](https://beta.atcoder.jp/contests/abc120)

    UnionFind木は繋がりを断つことはできないが、構成することはできるので、逆からやるやつ。

1. [D-Equals](https://beta.atcoder.jp/contests/abc097)

    swapすればそれらは行き来可能になるので、実質パイプ。

1. [B-Union Find](https://beta.atcoder.jp/contests/atc001)

    典型問題。uniteして、繋がってるか聞かれたら答えるだけ。

1. [B-道路工事](https://beta.atcoder.jp/contests/arc032/)

    すべての点に対して根を考えることで、グループが幾つに分かれているかを知ることができる


1. [D-連結](https://beta.atcoder.jp/contests/abc049)

    - [解説](http://drken1215.hatenablog.com/entry/2019/06/29/182300)

    二つのUnionFind木を管理して、同時に繋がっていることを根のPairを持ってmapで管理すると良い


1. [D - Friend Suggestions](https://atcoder.jp/contests/abc157/tasks/abc157_d)

    - [提出](https://atcoder.jp/contests/abc157/submissions/10460043)

    友達関係のグルーピングに使う。sizeも用いた。


1. [E - 1 or 2](https://atcoder.jp/contests/abc126/tasks/abc126_e)
    - [提出](https://atcoder.jp/contests/abc126/submissions/10649376)

    集合の数を管理するgroup_numを実装した


## Depends on

* :heavy_check_mark: <a href="../macros.hpp.html">macros.hpp</a>


## Required by

* :warning: <a href="../test/DSL_1_A.cpp.html">test/DSL_1_A.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef INCLUDED_UNIONFIND_HPP
#define INCLUDED_UNIONFIND_HPP
#include "../macros.hpp"
/*
@title UnionFind Tree
@category datastructure
@docs ../docs/datastructure/unionfind.md
*/
struct UnionFind{
    int n;
    vector<int> Parent;
    vector<int> sizes;
    UnionFind(int _n):n(_n),Parent(_n),sizes(_n,1){ rep(i,n)Parent[i]=i; }
    //find the root of x
    int root(int x){
        if(x!=Parent[x]){
        Parent[x] = root(Parent[x]);
        }
        return Parent[x];
    }
    //merge x and y
    void unite(int x,int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(sizes[x] < sizes[y]) swap(x, y);
        Parent[y] = x;
        sizes[x] += sizes[y];
    }
    bool same(int x,int y){ return root(x) == root(y); }
    int size(int x){ return sizes[root(x)]; }
    int group_num(){
        set<int> s;
        for(int i = 0; i < n; ++i){
            s.insert(root(i));
        }
        return int(s.size());
    }
};
#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "datastructure/unionfind.hpp"


#line 2 "macros.hpp"
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
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/
#line 4 "datastructure/unionfind.hpp"
/*
@title UnionFind Tree
@category datastructure
@docs ../docs/datastructure/unionfind.md
*/
struct UnionFind{
    int n;
    vector<int> Parent;
    vector<int> sizes;
    UnionFind(int _n):n(_n),Parent(_n),sizes(_n,1){ rep(i,n)Parent[i]=i; }
    //find the root of x
    int root(int x){
        if(x!=Parent[x]){
        Parent[x] = root(Parent[x]);
        }
        return Parent[x];
    }
    //merge x and y
    void unite(int x,int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(sizes[x] < sizes[y]) swap(x, y);
        Parent[y] = x;
        sizes[x] += sizes[y];
    }
    bool same(int x,int y){ return root(x) == root(y); }
    int size(int x){ return sizes[root(x)]; }
    int group_num(){
        set<int> s;
        for(int i = 0; i < n; ++i){
            s.insert(root(i));
        }
        return int(s.size());
    }
};


```
{% endraw %}

<a href="../../index.html">Back to top page</a>

