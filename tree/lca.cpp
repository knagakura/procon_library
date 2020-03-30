/*
@title 最小共通祖先/LCA(Lowest Common Acestor)
*/
#include "../macro/macros.hpp"
#include "template.cpp"

template<typename T>
class LCA :  public Tree<T>{
  public:
    using Tree<T>::N;
    using Tree<T>::G;
    int bitlen = 1;
    vector<int> d; //depth
    vector<vector<int>> anc; // bitlen * N
    LCA(int _N):Tree<T>::Tree(_N){
        init(_N);
    }
    void init(int n){
        while((1 << bitlen) < n){
            bitlen++;
        }
        d.assign(n, 0);
        anc.assign(bitlen, vector<int>(n,-1));
    }
    void dfs(int v = 0, int p = -1){
        anc[0][v] = p;
        for(int i = 0; i+1 < bitlen; ++i){
            anc[i+1][v] = (anc[i][v] >= 0) ? anc[i][anc[i][v]] : -1;
        }
        for(auto ne: G[v]) if(ne.to != p){
            d[ne.to] = d[v]+1;
            dfs(ne.to, v);
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
