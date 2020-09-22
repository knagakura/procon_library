#ifndef MAX_FLOW
#define MAX_FLOW

#include "../macro/macros.hpp"
/*

@title 最大流(Ford-Fulkerson法)
@category ネットワークフロー

*/

struct edge{
    int to, cap, rev;
};

struct FordFulkerson{
    int V;
    vector<vector<edge>> G;
    vector<bool> used;
    FordFulkerson(int V_):V(V_){
        G.resize(V);
        used.assign(V, false);
    }
    void add_edge(int from, int to, int cap){
        G[from].push_back((edge){to, cap, (int)G[to].size()});
        G[to].push_back((edge){from, 0, (int)G[from].size()-1});
    }
    int dfs(int v, int t, int f){
        if(v == t)return f;
        used[v] = true;
        for(auto &&e: G[v]){
            if(used[e.to])continue;
            if(e.cap <= 0)continue;
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
        return 0;
    }
    int max_flow(int s, int t){
        int flow = 0;
        for( ; ; ){
            used.assign(V, false);
            int f = dfs(s, t, INF);
            if(f == 0)return flow;
            flow += f;
        }
    }
};

#endif