#ifndef BINARY_TREE_CPP
#define BINARY_TREE_CPP
#include "../macro/macros.hpp"

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

#endif