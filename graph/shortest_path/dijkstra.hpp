#ifndef BFS_HPP
#define BFS_HPP
#include "../../macro/macros.hpp"
#include "../template.hpp"

template<typename T>
class Dijkstra : public Graph<T>{
  public:
    using Graph<T>::Graph;
    int N;
    vec<T> d;
    T inf;
    Dijkstra(int _N, T _inf):N(_N), Graph<T>::Graph(_N), inf(_inf), d(_N,_inf){
    }
    vec<T> solve(int start = 0){
        auto edges = Graph<T>::G;
        rep(i,N) d[i] = inf;
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
        d[start] = 0;
        pq.push({ 0,start });
        while (!pq.empty()) {
            T v = pq.top().first;
            int from = pq.top().second;
            pq.pop();
            for (auto u : edges[from]) {
                T w = v + u.cost;
                if (chmin(d[u.to], w)) {
                    pq.push({ w,u.to });
                }
            }
        }
        return d;
    }
};
#endif