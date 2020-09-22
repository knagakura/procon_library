#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A"

#include "../macro/macros.hpp"
#include "../flow/ford-fulkerson.cpp"

int main() {
    int V, E;
    cin >> V >> E;
    FordFulkerson G(V);
    rep(i,E){
        int u, v, c;
        cin >> u >> v >> c;
        G.add_edge(u, v, c);
    }
    cout << G.max_flow(0, V-1) << endl;
}
