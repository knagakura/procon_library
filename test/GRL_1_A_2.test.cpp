#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp"
#include "../macro/macros.hpp"
#include "../graph/template.hpp"
#include "../graph/shortest_path/dijkstra.hpp"

int main() {
    int V, E, r;
    cin >> V >> E >> r;
    Dijkstra<long long> G(V, INFLL);
    G.input(E, 0, true, true);
    G.solve(r);
    for(int i = 0; i < V; i++){
        if(G.d[i] == INFLL)cout << "INF" << endl;
        else cout << G.d[i] << endl;
    }
}