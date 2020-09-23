#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_7_A"
#include "../macro/macros.hpp"
#include "../flow/ford-fulkerson.cpp"

int main() {
    int X, Y, E;
    cin >> X >> Y >> E;
    FordFulkerson<int> G(X+Y+2, INF);
    int s = X + Y;
    int t = s + 1;
    rep(i,X)G.add_edge(s, i, 1);
    rep(j,Y)G.add_edge(j+X, t, 1);
    for(int i = 0; i < E; i++){
        int x, y;
        cin >> x >> y;
        y += X;
        G.add_edge(x, y, 1);
    }
    cout << G.max_flow(s, t) << endl;
}