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


# :heavy_check_mark: test/ALDS1_11_C.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/ALDS1_11_C.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 19:52:39+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C&lang=ja">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C&lang=ja</a>


## Depends on

* :heavy_check_mark: <a href="../../library/graph/shortest_path/bfs.hpp.html">graph/shortest_path/bfs.hpp</a>
* :heavy_check_mark: <a href="../../library/graph/template.hpp.html">graph/template.hpp</a>
* :heavy_check_mark: <a href="../../library/macro/macros.hpp.html">macro/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C&lang=ja"
#include "../macro/macros.hpp"
#include "../graph/template.hpp"
#include "../graph/shortest_path/bfs.hpp"

int main(){
    int N;
    cin >> N;
    BFS<int> G(N);
    rep(i,N){
        int u, k;
        cin >> u >> k;
        u--;
        rep(j,k){
            int v;
            cin >> v;
            v--;
            G.add_Directed_edge(u, v);
        }
    }
    G.bfs();
    rep(i,N){
        cout << i + 1 << " " << G.d[i] << endl;
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/ALDS1_11_C.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C&lang=ja"
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


#line 1 "graph/template.hpp"


#line 4 "graph/template.hpp"

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
        rep(i,M){
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

#line 1 "graph/shortest_path/bfs.hpp"


#line 5 "graph/shortest_path/bfs.hpp"

template<typename T>
class BFS : public Graph<T>{
  public:
    using Graph<T>::Graph;
    int N;
    vec<T> d;
    BFS(int _N):N(_N), Graph<T>::Graph(_N), d(_N,-1){
    }
    vec<T> bfs(int start = 0){
        auto edges = Graph<T>::G;
        queue<int> q;
        q.push(start);
        d[start] = 0;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto nv: edges[cur]){
                if(d[nv.to] != -1)continue;
                d[nv.to] = d[cur] + 1;
                q.push(nv.to);
            }
        }
        return d;
    }
};

#line 5 "test/ALDS1_11_C.test.cpp"

int main(){
    int N;
    cin >> N;
    BFS<int> G(N);
    rep(i,N){
        int u, k;
        cin >> u >> k;
        u--;
        rep(j,k){
            int v;
            cin >> v;
            v--;
            G.add_Directed_edge(u, v);
        }
    }
    G.bfs();
    rep(i,N){
        cout << i + 1 << " " << G.d[i] << endl;
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

