#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp"
#include "../macro/macros.hpp"
#include "../graph/shortest_path/dijkstra.cpp"

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