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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: graph/shortest_path/warshall-floyd.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#fff28642b706f0621a80a098b694618d">graph/shortest_path</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/shortest_path/warshall-floyd.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-31 04:16:41+09:00




## Depends on

* :heavy_check_mark: <a href="../template.hpp.html">Graph Class</a>
* :heavy_check_mark: <a href="../../macro/macros.hpp.html">Macro</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/GRL_1_C.test.cpp.html">test/GRL_1_C.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef WARSHALL_FLOYD_CPP
#define WARSHALL_FLOYD_CPP
/*
*/
#include "../../macro/macros.hpp"
#include "../template.hpp"

template<typename T>
class WarshallFloyd : public Graph<T>{
  public:
    using Graph<T>::N;
    using Graph<T>::G;
    T inf;
    vector<vector<T>> d;
    WarshallFloyd(int _N, T _inf):Graph<T>::Graph(_N), inf(_inf), d(_N,vector<T>(_N,_inf)){}
    void solve(){
        //initialize the distance matrix
        d.assign(N, vector<T>(N,inf));
        for(int i = 0; i < N; i++) d[i][i] = 0;
        for(int i = 0; i < N; i++){
            for(auto e: G[i]){
                d[i][e.to] = e.cost;
            }
        }
        //WarshallFloyd
        for(int k = 0; k < N; k++)for(int i = 0; i < N; i++)for(int j = 0; j < N; j++){
            if(d[i][k] == inf || d[k][j] == inf)continue;
            chmin(d[i][j],d[i][k] + d[k][j]);
        }
    }
    bool negative_cycle(){
        for(int i = 0; i < N; i++)
            if(d[i][i] < 0)
                return true;
        return false;
    }
    void debug(){
        for(int i = 0; i < N; ++i){
            cerr<<i+1<<": ";
            for(auto e: G[i]){
                cerr<<"{"<<e.to+1<<", "<<e.cost<<"}, ";
            }
            cerr<<endl<<endl;
        }

        cerr<<"distance_matrix"<<endl;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(d[i][j] == inf){
                    cerr<<-1<<" ";
                }else cerr<<d[i][j]<<" ";
            }
            cerr<<endl;
        }
    }
};
#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/shortest_path/warshall-floyd.cpp"


/*
*/
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

#line 7 "graph/shortest_path/warshall-floyd.cpp"

template<typename T>
class WarshallFloyd : public Graph<T>{
  public:
    using Graph<T>::N;
    using Graph<T>::G;
    T inf;
    vector<vector<T>> d;
    WarshallFloyd(int _N, T _inf):Graph<T>::Graph(_N), inf(_inf), d(_N,vector<T>(_N,_inf)){}
    void solve(){
        //initialize the distance matrix
        d.assign(N, vector<T>(N,inf));
        for(int i = 0; i < N; i++) d[i][i] = 0;
        for(int i = 0; i < N; i++){
            for(auto e: G[i]){
                d[i][e.to] = e.cost;
            }
        }
        //WarshallFloyd
        for(int k = 0; k < N; k++)for(int i = 0; i < N; i++)for(int j = 0; j < N; j++){
            if(d[i][k] == inf || d[k][j] == inf)continue;
            chmin(d[i][j],d[i][k] + d[k][j]);
        }
    }
    bool negative_cycle(){
        for(int i = 0; i < N; i++)
            if(d[i][i] < 0)
                return true;
        return false;
    }
    void debug(){
        for(int i = 0; i < N; ++i){
            cerr<<i+1<<": ";
            for(auto e: G[i]){
                cerr<<"{"<<e.to+1<<", "<<e.cost<<"}, ";
            }
            cerr<<endl<<endl;
        }

        cerr<<"distance_matrix"<<endl;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(d[i][j] == inf){
                    cerr<<-1<<" ";
                }else cerr<<d[i][j]<<" ";
            }
            cerr<<endl;
        }
    }
};


```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

