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


# :heavy_check_mark: graph/shortest_path/dijkstra.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#fff28642b706f0621a80a098b694618d">graph/shortest_path</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/shortest_path/dijkstra.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-28 15:01:29+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp"
#include <bits/stdc++.h>
using namespace std;

template<class T> class Dijkstra {
public:
    int N;
    T inf;
    vector<T> cost;
    vector<vector<pair<T, int>>> edge;
 
    Dijkstra(const int _N, T _inf = 1e18) : N(_N), inf(_inf),cost(N), edge(N) {
    }
 
    void make_edge(int from, int to, T w) {
        edge[from].push_back({ w,to });
    }
 
    void solve(int start) {
        for(int i = 0; i < N; ++i) cost[i] = inf;
 
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
        cost[start] = 0;
        pq.push({ 0,start });
 
        while (!pq.empty()) {
            T v = pq.top().first;
            int from = pq.top().second;
            pq.pop();
            for (auto u : edge[from]) {
                T w = v + u.first;
                int to = u.second;
                if (w < cost[to]) {
                    cost[to] = w;
                    pq.push({ w,to });
                }
            }
        }
        return;
    }
};


int main() {
    const long long INFLL = (long long)1e18+1;
    int V, E, r;
    cin >> V >> E >> r;

    Dijkstra<long long> G(V, INFLL);

    for(int _ = 0; _ < E; _++){
        int s, t;
        long long d;
        cin >> s >> t >> d;
        G.make_edge(s, t, d);
    }

    G.solve(r);

    for(int i = 0; i < V; i++){
        if(G.cost[i] == INFLL)cout << "INF" << endl;
        else cout << G.cost[i] << endl;
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/shortest_path/dijkstra.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp"
#include <bits/stdc++.h>
using namespace std;

template<class T> class Dijkstra {
public:
    int N;
    T inf;
    vector<T> cost;
    vector<vector<pair<T, int>>> edge;
 
    Dijkstra(const int _N, T _inf = 1e18) : N(_N), inf(_inf),cost(N), edge(N) {
    }
 
    void make_edge(int from, int to, T w) {
        edge[from].push_back({ w,to });
    }
 
    void solve(int start) {
        for(int i = 0; i < N; ++i) cost[i] = inf;
 
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
        cost[start] = 0;
        pq.push({ 0,start });
 
        while (!pq.empty()) {
            T v = pq.top().first;
            int from = pq.top().second;
            pq.pop();
            for (auto u : edge[from]) {
                T w = v + u.first;
                int to = u.second;
                if (w < cost[to]) {
                    cost[to] = w;
                    pq.push({ w,to });
                }
            }
        }
        return;
    }
};


int main() {
    const long long INFLL = (long long)1e18+1;
    int V, E, r;
    cin >> V >> E >> r;

    Dijkstra<long long> G(V, INFLL);

    for(int _ = 0; _ < E; _++){
        int s, t;
        long long d;
        cin >> s >> t >> d;
        G.make_edge(s, t, d);
    }

    G.solve(r);

    for(int i = 0; i < V; i++){
        if(G.cost[i] == INFLL)cout << "INF" << endl;
        else cout << G.cost[i] << endl;
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

