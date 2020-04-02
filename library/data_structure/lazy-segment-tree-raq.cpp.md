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


# :heavy_check_mark: data_structure/lazy-segment-tree-raq.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/lazy-segment-tree-raq.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-03 02:33:04+09:00




## Depends on

* :heavy_check_mark: <a href="../macro/macros.hpp.html">Macro</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/DSL_2_G.test.cpp.html">test/DSL_2_G.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef LAZY_SEGMENT_TREE_RAQ_CPP
#define LAZY_SEGMENT_TREE_RAQ_CPP
#include "../macro/macros.hpp"

/*
@遅延評価セグメント木(Lazy Segment Tree) 区間加算
*/
template<typename T>
class LazySegTree {
  public:
    int N;//葉の数
    vector<T> data;//配列
    vector<T> lazy;//遅延評価
    void _add(int a, int b, T x, int k, int l, int r){
        eval(k, l, r);
        if(b <= l || r <= a)return;
        if(a <= l && r <= b){
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else{
            _add(a, b, x, 2*k+1, l, (l+r)/2);
            _add(a, b, x, 2*k+2, (l+r)/2, r);
            data[k] = data[2*k+1] + data[2*k+2];
        }
    }
    T _query(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) return 0;
        eval(k, l, r);
        if(a <= l && r <= b) return data[k];
        T c1 = _query(a, b, 2*k+1, l, (l+r)/2);
        T c2 = _query(a, b, 2*k+2, (l+r)/2, r);
        return c1 + c2;
    }
    //コンストラクター
    LazySegTree(vector<T> v){
        int sz = v.size();
        N = 1;
        while(N < sz)N *= 2;
        data.assign(2 * N - 1, 0);
        lazy.assign(2 * N - 1, 0);
        for(int i = 0; i < sz; i++) data[N-1+i] = v[i];
        for(int i = N - 2; i >= 0; i--) data[i] = data[i*2+1] + data[i*2+2];
    }
    //遅延評価
    void eval(int k, int l, int r){
        if(lazy[k] == 0)return;
        data[k] += lazy[k];
        if(r - l > 1){
            lazy[2*k+1] += lazy[k] / 2;
            lazy[2*k+2] += lazy[k] / 2;
        }
        lazy[k] = 0;
    }
    void add(int a, int b, T x){
        _add(a, b, x, 0, 0, N);
    }
    //[a, b)の区間クエリの実行
    T query(int a, int b){
        return _query(a, b, 0, 0, N);
    }
    //添字でアクセス
    T operator[](int i) {
        return data[i + N - 1];
    }
};

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/lazy-segment-tree-raq.cpp"


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


#line 4 "data_structure/lazy-segment-tree-raq.cpp"

/*
@遅延評価セグメント木(Lazy Segment Tree) 区間加算
*/
template<typename T>
class LazySegTree {
  public:
    int N;//葉の数
    vector<T> data;//配列
    vector<T> lazy;//遅延評価
    void _add(int a, int b, T x, int k, int l, int r){
        eval(k, l, r);
        if(b <= l || r <= a)return;
        if(a <= l && r <= b){
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else{
            _add(a, b, x, 2*k+1, l, (l+r)/2);
            _add(a, b, x, 2*k+2, (l+r)/2, r);
            data[k] = data[2*k+1] + data[2*k+2];
        }
    }
    T _query(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) return 0;
        eval(k, l, r);
        if(a <= l && r <= b) return data[k];
        T c1 = _query(a, b, 2*k+1, l, (l+r)/2);
        T c2 = _query(a, b, 2*k+2, (l+r)/2, r);
        return c1 + c2;
    }
    //コンストラクター
    LazySegTree(vector<T> v){
        int sz = v.size();
        N = 1;
        while(N < sz)N *= 2;
        data.assign(2 * N - 1, 0);
        lazy.assign(2 * N - 1, 0);
        for(int i = 0; i < sz; i++) data[N-1+i] = v[i];
        for(int i = N - 2; i >= 0; i--) data[i] = data[i*2+1] + data[i*2+2];
    }
    //遅延評価
    void eval(int k, int l, int r){
        if(lazy[k] == 0)return;
        data[k] += lazy[k];
        if(r - l > 1){
            lazy[2*k+1] += lazy[k] / 2;
            lazy[2*k+2] += lazy[k] / 2;
        }
        lazy[k] = 0;
    }
    void add(int a, int b, T x){
        _add(a, b, x, 0, 0, N);
    }
    //[a, b)の区間クエリの実行
    T query(int a, int b){
        return _query(a, b, 0, 0, N);
    }
    //添字でアクセス
    T operator[](int i) {
        return data[i + N - 1];
    }
};



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

