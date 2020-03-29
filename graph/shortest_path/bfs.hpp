#ifndef BFS_HPP
#define BFS_HPP
#include "../../macro/macros.hpp"
#include "../template.hpp"

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
#endif