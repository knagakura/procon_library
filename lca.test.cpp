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