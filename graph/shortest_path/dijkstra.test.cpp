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