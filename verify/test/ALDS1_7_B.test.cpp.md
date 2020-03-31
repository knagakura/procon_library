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


# :heavy_check_mark: test/ALDS1_7_B.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/ALDS1_7_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-31 19:14:10+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_B">https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_B</a>


## Depends on

* :heavy_check_mark: <a href="../../library/macro/macros.hpp.html">Macro</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_B"
#include "../macro/macros.hpp"
#include "../tree/binary-tree.cpp"
/*
*/

int main(){
    int N;
    cin >> N;
    Binary_Tree G(N);
    for(int i = 0; i < N;i++){
        int from, l, r;
        cin >> from >> l >> r;
        if(l != -1)G.add_directed_edge(from, l);
        if(r != -1)G.add_directed_edge(from, r);
        if(l != -1 && r != -1){
            G.set_sibling(l, r);
        }
    }
    G.build();
    G.Cout();
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/ALDS1_7_B.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_B"
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


#line 1 "tree/binary-tree.cpp"


#line 4 "tree/binary-tree.cpp"

/*
@title 二分木(Binary Tree)
@category tree
@ignore
*/
struct Binary_Tree{
    int N;
    vector<vector<int>> G;
    vector<int> par, sibling, depth, height;
    vector<string> type;
    Binary_Tree(int _N):N(_N),G(_N), par(_N, -1), sibling(_N, -1), depth(_N,0),height(_N), type(_N){}
    void add_directed_edge(int from, int to){
        G[from].push_back(to);
        par[to] = from;
    }
    void set_sibling(int l, int r){
        sibling[l] = r;
        sibling[r] = l;
    }
    int dfs(int cur, int pre = -1){
        int res = 0;
        for(auto nv: G[cur]){
            depth[nv] = depth[cur] + 1;
            res = max(res, dfs(nv, cur) + 1);
        }
        if(pre == -1)
            type[cur] = "root";
        else if((int)G[cur].size() == 0)
            type[cur] = "leaf";
        else
            type[cur] = "internal node";
        return height[cur] = res;
    }
    void build(){
        for(int i = 0; i < N; i++){
            if(par[i] == -1){
                dfs(i);
                break;
            }
        }
    }
    void Cout(){
        for(int i = 0; i < N; i++){
            prints(i);
        }
    }
    void prints(int idx){
        cout << "node "         << idx              << ": ";
        cout << "parent = "     << par[idx]         << ", ";
        cout << "sibling = "    << sibling[idx]     << ", ";
        cout << "degree = "     << G[idx].size()    << ", "; 
        cout << "depth = "      << depth[idx]       << ", ";
        cout << "height = "     << height[idx]      << ", ";
        cout << type[idx]       << endl;
    }
};


#line 4 "test/ALDS1_7_B.test.cpp"
/*
*/

int main(){
    int N;
    cin >> N;
    Binary_Tree G(N);
    for(int i = 0; i < N;i++){
        int from, l, r;
        cin >> from >> l >> r;
        if(l != -1)G.add_directed_edge(from, l);
        if(r != -1)G.add_directed_edge(from, r);
        if(l != -1 && r != -1){
            G.set_sibling(l, r);
        }
    }
    G.build();
    G.Cout();
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

