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


# :heavy_check_mark: test/GRL_5_B.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/GRL_5_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-31 06:16:00+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_B">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_B</a>


## Depends on

* :heavy_check_mark: <a href="../../library/graph/template.hpp.html">Graph Class</a>
* :heavy_check_mark: <a href="../../library/macro/macros.hpp.html">Macro</a>
* :heavy_check_mark: <a href="../../library/tree/template.cpp.html">Tree Class</a>
* :heavy_check_mark: <a href="../../library/tree/tree-diameter-height.cpp.html">木の直径と高さ/Diameter and Height of a Tree (全方位木DP/Rerooting ver.)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_B"
#include "../macro/macros.hpp"
#include "../tree/template.cpp"
#include "../tree/tree-diameter-height.cpp"


int main(){
    int N;
    cin >> N;
    Tree_DH<long long> G(N);
    G.input(N-1, 0, true, false);
    G.build();
    auto ans = G.get_height();
    for(auto x: ans){
        cout << x << endl;
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/GRL_5_B.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_B"
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


#line 1 "tree/template.cpp"


#line 1 "graph/template.hpp"


#line 4 "graph/template.hpp"

/*
@title Graph Class
@category template
*/
template<typename T = int>
struct edge{
    int to;
    T cost;
    int id;
    edge(int _to, T _cost = 1, int _id = -1) :to(_to), cost(_cost), id(_id) {}
};

template<class T>
class Graph {
  public:
    int N;
    vvec<edge<T>> G;
    Graph(int _N): N(_N),G(_N){
    }
    void add_Directed_edge(int from, int to, T cost = 1, int id = -1){
        G[from].push_back({to, cost, id});
    }
    void add_edge(int v1, int v2, T cost = 1, int id = -1){
        add_Directed_edge(v1, v2, cost, id);
        add_Directed_edge(v2, v1, cost, id);
    }
    //standard input
    void input(int M, int padding = -1, bool weighted = false, bool directed = false){
        while(M--){
            int a, b;
            cin >> a >> b;
            a += padding;
            b += padding;
            T c = T(1);
            if(weighted)cin >> c;
            if(directed)add_Directed_edge(a,b,c);
            else add_edge(a,b,c);
        }
    }
};

#line 5 "tree/template.cpp"

/*
@title Tree Class
@category template
*/
template<class T>
class Tree {
  public:
    int N;
    vvec<edge<T>> G;
    Tree(int _N): N(_N),G(_N){
    }
    void add_Directed_edge(int from, int to, T cost = 1, int id = -1){
        G[from].push_back({to, cost, id});
    }
    void add_edge(int v1, int v2, T cost = 1, int id = -1){
        add_Directed_edge(v1, v2, cost, id);
        add_Directed_edge(v2, v1, cost, id);
    }
    //standard input
    void input(int M, int padding = -1, bool weighted = false, bool directed = false){
        while(M--){
            int a, b;
            cin >> a >> b;
            a += padding;
            b += padding;
            T c = T(1);
            if(weighted)cin >> c;
            if(directed)add_Directed_edge(a,b,c);
            else add_edge(a,b,c);
        }
    }
};


#line 1 "tree/tree-diameter-height.cpp"
/*
@title 木の直径と高さ/Diameter and Height of a Tree (全方位木DP/Rerooting ver.)
@category tree
@docs ../docs/tree/tree-diameter-height.md
*/
#line 8 "tree/tree-diameter-height.cpp"

template<typename T>
class Tree_DH :  public Tree<T>{
  public:
    using Tree<T>::N;
    using Tree<T>::G;
    vector<T> dp, dp2, height;
    T diameter;
    Tree_DH(int _N):Tree<T>::Tree(_N), dp(_N,0), dp2(_N), height(_N){}
    //Calc distance and start Rerooting
    void build(int start = 0, int pre = -1, bool debug = false){
        dfs1(start, pre);
        dfs2(start, pre);
        if(debug){
            print(dp);
            print(dp2);
            print(height);
        }
        diameter = *max_element(dp2.begin(), dp2.end());
    }
    //calculate the distance from start
    void dfs1(int cur = 0, int pre = -1){
        dp[cur] = 0;
        for(edge<T>& ne: G[cur]){
            if(ne.to == pre)continue;
            dfs1(ne.to, cur);
            dp[cur] = max(dp[cur],dp[ne.to] + ne.cost);
        }
    }
    void dfs2(int cur = 0, int pre = -1, T d_par = 0){
        //rerooting
        vector<pair<T,int>> childs;
        childs.push_back({0, -1}); //番兵 次数が1だと壊れるので
        for(auto ne: G[cur]){
            if(ne.to == pre)
                childs.push_back({d_par + ne.cost, ne.to});
            else 
                childs.push_back({dp[ne.to] + ne.cost, ne.to});
        }
        //大きい二つ
        sort(all(childs), greater<pair<T, int>>());
        dp2[cur] = childs[0].first + childs[1].first;
        height[cur] = childs[0].first;
        for(auto ne: G[cur]){
            if(ne.to == pre)continue;
            //降りる辺が最大値
            if(childs[0].second == ne.to)
                dfs2(ne.to, cur, childs[1].first);
            else 
                dfs2(ne.to, cur, childs[0].first);
        }
    }
    T get_diameter(){
        return diameter;
    }
    vector<T> get_height(){
        return height;
    }
};
#line 5 "test/GRL_5_B.test.cpp"


int main(){
    int N;
    cin >> N;
    Tree_DH<long long> G(N);
    G.input(N-1, 0, true, false);
    G.build();
    auto ans = G.get_height();
    for(auto x: ans){
        cout << x << endl;
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

