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
<script type="text/javascript" src="../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../assets/css/copy-button.css" />


# :x: lca.test.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/lca.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-28 03:56:06+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C">https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C"

#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

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

int main() {
    int N;
    cin >> N;
    vector<vector<int>> g(N);
    rep(i,N){
        int k;
        cin >> k;
        rep(j,k){
            int a;
            cin >> a;
            g[i].push_back(a);
            g[a].push_back(i);
        }
    }
    LCA G(N, g);
    int Q;
    cin >> Q;
    while(Q--){
        int a, b;
        cin >> a >> b;
        cout << G.lca(a, b) << endl;
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lca.test.cpp"
//#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C"

#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

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

int main() {
    int N;
    cin >> N;
    vector<vector<int>> g(N);
    rep(i,N){
        int k;
        cin >> k;
        rep(j,k){
            int a;
            cin >> a;
            g[i].push_back(a);
            g[a].push_back(i);
        }
    }
    LCA G(N, g);
    int Q;
    cin >> Q;
    while(Q--){
        int a, b;
        cin >> a >> b;
        cout << G.lca(a, b) << endl;
    }
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

