#ifndef ROOTED_TREE_CPP
#define ROOTED_TREE_CPP
#include "../macro/macros.hpp"

/*
@title 根付き木(Rooted Tree)
@category tree
@ignore
*/
struct Rooted_Tree{
    int N;
    vector<vector<int>> G;
    vector<int> par;
    vector<int> depth;
    vector<string> type;
    vector<vector<int>> childs;
    Rooted_Tree(int _N):N(_N),G(_N), par(_N, -1),depth(_N,0), type(_N), childs(_N){}
    void add_directed_edge(int parent, int child){
        G[parent].push_back(child);
        par[child] = parent;
    }
    void dfs(int cur, int pre = -1){
        for(auto nv: G[cur]){
            if(nv == pre)continue;
            childs[cur].push_back(nv);
            depth[nv] = depth[cur] + 1;
            dfs(nv, cur);
        }
        if(pre == -1)
            type[cur] = "root";
        else if((int)childs[cur].size() == 0)
            type[cur] = "leaf";
        else
            type[cur] = "internal node";
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
        cout << "node "     << idx          << ": ";
        cout << "parent = " << par[idx]     << ", ";
        cout << "depth = "  << depth[idx]   << ", ";
        cout << type[idx]   << ", ";
        cout << "[";
        for(int i = 0; i < (int)childs[idx].size();i++){
            cout << childs[idx][i];
            if(i < (int)childs[idx].size()-1)
                cout << ", ";
        }
        cout << "]" << endl;
    }
};

#endif